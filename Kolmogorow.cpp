#include "Kolmogorow.h"
#include <iostream>
using namespace std;

Double_t Kolmogorow::testHistogram(TH1F* histo) {
	Int_t bins = histo->GetNbinsX();
	Double_t n = histo->Integral();
	TH1F* cum = getCumHisto(histo);

	Double_t width;
	Double_t d_plus = 0.0;
	Double_t d_minus = 0.0;
	Double_t current_plus;
	Double_t current_minus;
	Double_t k;
	Double_t W = 0.0;

	for (int i = 0; i < bins; i++) {

		width = histo->GetBinWidth(i);
		k = i*width + width/2;

		current_plus = i / n - graph->Eval(k);
		current_minus = graph->Eval(k) - (i - 1) / n;

		if (current_plus > d_plus) d_plus = current_plus;
		if (current_minus < d_minus) d_minus = current_minus;

		W += (graph->Eval(k) - (2 * i - 1) / (2 * n)) * (graph->Eval(k) - (2 * i - 1) / (2 * n));
	}
	W += 1 / (12 * n);
	
	cout << "D_+ = " << d_plus << endl;
	cout << "D_- = " << d_minus << endl;
	cout << "W2 = " << (W-0.4/n+0.6/(n*n))/(1.0+1.0/n) << endl;
	return 0;
}

TH1F* Kolmogorow::getCumHisto(TH1F* histo) {
	// The amounts of bins in the histogram
	Int_t bins = histo->GetNbinsX();
	Double_t d_minus = 0;
	Double_t d_plus = 0;

	TH1F* cum = new TH1F("cum", "cum", bins, histo->GetMinimum(), histo->GetMaximum());
	Double_t cum_sum = 0.0;
	for (int i = 0; i < bins; i++) {
		Double_t content = histo->GetBinContent(i);
		cum_sum += content;
		cum->SetBinContent(i, cum_sum / histo->Integral());
	}
	return cum;
}

TGraph* Kolmogorow::generateFunction(TH1F* histo) {
	// Variable holding the cumulative sum
	Double_t cum_sum = 0.0;

	// The amounts of bins in the histogram
	Int_t bins = histo->GetNbinsX();

	// The total entries
	Double_t total = histo->GetEntries();

	// Allocate array for points
	Double_t* x_points;
	Double_t* y_points;
	x_points = new Double_t[bins];
	y_points = new Double_t[bins];

	// Binwidth
	Double_t width;

	// Loop all the bins and add them
	for (int i = 0; i < bins; i++) {
		// The x value is the width * bin number
		width = histo->GetBinWidth(i);
		x_points[i] = i*width;
		Double_t content = histo->GetBinContent(i);
		cum_sum += content/total;
		y_points[i] = cum_sum;
	}

	graph = new TGraph(bins, x_points, y_points);
	return graph;
}