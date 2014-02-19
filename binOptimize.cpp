#include "TH1F.h"
#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

void binOptimize(TH1F* histo) {

	Int_t nBins = histo->GetNbinsX();
	Double_t max = histo->GetMaximum();
	Double_t* array;
	array = new Double_t[nBins];
	for (int i = 0; i < nBins; i++) {
		array[i] = max/nBins * i;
	}

	histo->Draw();

	cout << nBins << endl;

}