#include"MonteCarlo.h"
#include"DataLoader.h"
#include"TMath.h"
#include<iostream>

using namespace std;

void MonteCarloSimulation() {
	DataLoader* l = new DataLoader();
	TH1F *referenceproton = l->load1DHistogram("Histogrammer/time.root", "bottom3");
	Int_t repeats = 100;
	MonteCarlo* mc = new MonteCarlo();
	mc->setModelHistogram(referenceproton);
	mc->setCounts(1000);
	mc->setRepeats(repeats);
	
	mc->performSimulation();
	cout << "Sorting" << endl;
	Int_t* sorted_A = new Int_t[repeats];
	Int_t* sorted_W = new Int_t[repeats];
	Int_t* sorted_D = new Int_t[repeats];
	
	Double_t* A = new Double_t[repeats];
	Double_t* W = new Double_t[repeats];
	Double_t* D = new Double_t[repeats];

	TMath::Sort(repeats, mc->A, sorted_A, false);
	TMath::Sort(repeats, mc->W, sorted_W, false);
	TMath::Sort(repeats, mc->D, sorted_D, false);

	for (int i = 0; i < repeats; i++) {
		A[i] = (mc->A)[sorted_A[i]];
		D[i] = (mc->D)[sorted_D[i]];
		W[i] = (mc->W)[sorted_W[i]];
	}
	
	cout << A[94] << endl;
	cout << W[94] << endl;
	cout << D[94] << endl;
}