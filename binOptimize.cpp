#include "TH1F.h"
#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

Double_t C(TH1F* histo);

TH1F* binOptimize(TH1F* histo) {

	// Get current bins
	Int_t nBins = histo->GetNbinsX();
	cout << "Bins " << nBins << "\n" << endl;
	// Get current max
	Double_t max = histo->GetMaximum();
	cout << "Max " << max << "\n" << endl;
	// The new number of bins
	Int_t newBins;
	TH1F* result = histo;
	for (newBins = nBins; newBins > 2; newBins--) {
		// Allocate array
		Double_t* array;
		array = new Double_t[newBins];
		for (int i = 0; i < newBins; i++) {
			array[i] = max / ((Double_t)newBins) * ((Double_t)i);
		}

		result = (TH1F*)histo->Rebin(newBins - 1, "Result", array);
		cout << C(histo) << " " << C(result) << endl;
	}

	
	//cout << C(histo) << " " << C(result) << endl;
	return result;
}

Double_t C(TH1F* histo) {

	Double_t mean = histo->GetMean();
	Double_t std = histo->GetStdDev();
	Double_t var = std*std;
	Double_t width = histo->GetBinWidth(0);
	Double_t n = histo->GetEntries();
	return (2 * mean - var) / (width*n*width*n);

}