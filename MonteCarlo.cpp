#include"MonteCarlo.h"
#include"Util.h"
#include"TRandom1.h"
#include<iostream>
#include<fstream>
#include <algorithm> 
using namespace std;

MonteCarlo::MonteCarlo() {
	setCounts(500);
	setRepeats(40000);
	kol = new Kolmogorow();
}

MonteCarlo::~MonteCarlo() {
	delete[] A;
	delete[] D;
	delete[] W;
	delete cum_normalized_hitso;
}

void MonteCarlo::setCounts(Int_t counts) {
	delete[] random_num;
	random_num = new Double_t[counts];
	_counts = counts;
}

void MonteCarlo::setRepeats(Int_t repeats) {
	delete[] A;
	delete[] D;
	delete[] W;
	A = new Double_t[repeats];
	D = new Double_t[repeats];
	W = new Double_t[repeats];
	_repeats = repeats;
}

void MonteCarlo::setModelHistogram(TH1F* histo) {
	kol->setReferenceHistogram(histo);
	cum_normalized_hitso = util::getCumulatedHistogram(histo, 0, 1200, true);
	// For binary search
	Float_t* array = cum_normalized_hitso->GetArray();
	std::vector<Float_t> v(array, array + 1200);
}

void MonteCarlo::performSimulation() {
	// Fill array with random numbers
	TRandom1* rand = new TRandom1();
	TH1F* exp = NULL;
	for (Int_t j = 0; j < _repeats; j++) {
		rand->RndmArray(_counts, random_num);
		// Allocate new histogram
		exp = new TH1F("", "", 1200, 0, 1200);
		for (Int_t i = 0; i < _counts; i++) {
			exp->Fill(findBinNumber(random_num[i]));
		}

		kol->testVsHistogram(exp);
		A[j] = kol->A_h;
		D[j] = kol->D_h;
		W[j] = kol->W_h;
		delete exp;
		exp = NULL;
		cout << (Double_t) j/ (Double_t) _repeats << endl;
	}
	
}

Int_t MonteCarlo::findBinNumber(Double_t y) {
	Int_t i = 0;
	while (cum_normalized_hitso->GetBinContent(i) <= y) {
		i++;
		if (i == 1200) return i;
	}
	return i;
}

