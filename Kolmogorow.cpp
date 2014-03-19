#include "Kolmogorow.h"
#include <iostream>
#include "TMath.h"
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
	Int_t t = 0;

	for (Int_t i = 0; i < bins; i++) {

		width = histo->GetBinWidth(i);
		k = i*width + width/2;

		current_plus = i * histo->GetBinContent(i) / n - graph->Eval(k);
		current_minus = graph->Eval(k) - ((i-1) * histo->GetBinContent(i)) / n;
		if (current_plus > d_plus) d_plus = current_plus;
		if (current_minus < d_minus) d_minus = current_minus;
		for (Int_t f = 0; f < histo->GetBinContent(i); f++) {
			W += (graph->Eval(k) - (2 * t - 1) / (2 * n)) * (graph->Eval(k) - (2 * t - 1) / (2 * n));
			t++;
		}
		cout << "D_+ = " << current_plus << endl;
		cout << "D_- = " << current_minus << endl;
		cout << "W2 = " << W << endl;
	}
	W += 1 / (12 * n);
	cum->Draw();
	graph->Draw("same");
	cout << "D_+ = " << d_plus << endl;
	cout << "D_- = " << d_minus << endl;
	cout << "W2 = " << W << endl;
	return 0;
}

Double_t Kolmogorow::compareHistograms(TH1F* h1, TH1F* h2) {

	TH1F* EDF = getCumHisto(h2);
	TH1F* F = getCumHisto(h1);
	Double_t n = F->GetNbinsX();
	Double_t d_plus = 0.0;
	Double_t d_minus = 0.0;

	Double_t W2 = 0;
	Double_t A2 = 0;

	for (Int_t i = 0; i < n; i++) {
		Double_t EDF_i = EDF->GetBinContent(i);
		Double_t F_i = F->GetBinContent(i);
		Double_t diff1 = F_i - EDF_i;
		Double_t diff2 = EDF_i - F_i;
		if(diff1 > d_plus) d_plus = diff1;
		if(diff2 > d_minus) d_minus = diff2;

		W2 += pow(EDF_i - F_i, 2)*h1->GetBinContent(i) / h1->Integral();
		if ((F_i*(1 - F_i)) != 0.0) {
			A2 += pow(EDF_i - F_i, 2)*h1->GetBinContent(i) / h1->Integral() / (F_i*(1 - F_i));
		}
		
	}

	d_plus *= sqrt(n);
	d_minus *= sqrt(n);
	
	W2 *= n;
	A2 *= n;

	cout << "D = " << TMath::Max(d_plus, d_minus) << endl;
	cout << "W2 = " << W2 << endl;
	cout << "A2 = " << A2 << endl;

	return 0;
}


TH1F* Kolmogorow::getCumHisto(TH1F* histo) {
	// The amounts of bins in the histogram
	Int_t bins = histo->GetNbinsX();
	Double_t d_minus = 0;
	Double_t d_plus = 0;
	//cout << "max " << histo->GetMaximum() << " min " << histo->GetMinimum() << endl;
	TH1F* cum = new TH1F("cum", "cum", bins, 0, 5000);
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
		Double_t content = histo->GetBinContent(i+1);
		cum_sum += content/total;
		y_points[i] = cum_sum;
	}

	graph = new TGraph(bins, x_points, y_points);
	return graph;
}