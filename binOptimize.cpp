#include "TH1F.h"
#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

Double_t C(TH1F* histo);
TH1F* rebin(TH1F* histo, Double_t max, Int_t newBins);

TH1F* binOptimize(TH1F* histo) {

	// Get current bins
	Int_t nBins = histo->GetNbinsX();
	cout << "Bins " << nBins << endl;
	// Get current max
	Double_t max = histo->GetXaxis()->GetXmax();
	cout << "Max " << max << endl;
	// The new number of bins
	Int_t newBins;
	TH1F* result = histo;// = rebin(histo, max, 100);

	Int_t min_bin = 0;
	Int_t min = 90000000000;

	for (newBins = nBins; newBins > 2; newBins--) {
		result= rebin(histo, max, newBins);
		//result->Draw();
		cout << C(result) << endl;
		if (C(result) < min ) {
			min = C(result);
			min_bin = newBins;
		}
		
	}

	cout << min_bin << endl;
	return result;
}

TH1F* rebin(TH1F* histo, Double_t max, Int_t newBins) {

	// Allocate array
	Double_t* array;
	array = new Double_t[newBins];
	for (int i = 0; i < newBins; i++) {
		array[i] = max / ((Double_t)newBins) * ((Double_t)i);
	}

	TH1F* result = (TH1F*)histo->Rebin(newBins - 1, "Result", array);
	return result;

}

Double_t varians(TH1F* histo) {
	Int_t nBins = histo->GetNbinsX();
	Double_t mean = histo->GetMean();
	Double_t var = 0;
	for (int i = 0; i <= nBins; i++) {
		Double_t dis = (mean - histo->GetBinContent(i));
		var += dis*dis;
	}
	return mean / ((Double_t) nBins);
}

Double_t C(TH1F* histo) {

	Double_t mean = histo->GetMean();
	Double_t var = histo->GetStdDev() * histo->GetStdDev();
	Double_t width = histo->GetBinWidth(0);
	Double_t n = histo->GetEntries();
	return (2 * mean - var) / (n*n*width*width);

}