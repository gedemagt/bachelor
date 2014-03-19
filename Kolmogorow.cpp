#include "Kolmogorow.h"
#include <iostream>
#include "TMath.h"
#include "TRandom1.h"
using namespace std;

Double_t Kolmogorow::testVsFunction(TH1F* histo) {
	cout << "Testing " << histo->GetName() << " vs function." << endl;
	cout << "Bins: " << histo->GetNbinsX() << " vs " << reference->GetNbinsX() << endl;
	cout << "N: " << histo->Integral() << endl;
	
	// Initialize random object using the RanLux generator
	TRandom1* r = new TRandom1();
	Int_t bins = histo->GetNbinsX();
	Double_t n = histo->Integral();
	TH1F* cum = getCumHisto(histo);

	// Initialize variables
	W_f = A_f = D_f = 0.0;
	Double_t d_plus = 0.0, d_minus = 0.0;
	Double_t width = 0.0, current_plus = 0.0, current_minus = 0.0, k = 0.0, Z_i = 0.0;
	Int_t t = 0;

	for (Int_t i = 0; i < bins; i++) {

		width = histo->GetBinWidth(i);
		k = i*width + width*r->Rndm();
		Z_i = reference_graph->Eval(k);


		// Kolmogorow-Smirnoff
		current_plus = i * histo->GetBinContent(i) / n - Z_i;
		current_minus = Z_i - ((i - 1) * histo->GetBinContent(i)) / n;
		
		if (current_plus > d_plus) d_plus = current_plus;
		if (current_minus < d_minus) d_minus = current_minus;
		
		
		for (Int_t f = 0; f < histo->GetBinContent(i); f++) {
			k = i*width + width*r->Rndm();
			Z_i = reference_graph->Eval(k);

			// Cramér-von Mises
			W_f += (Z_i - (2 * t - 1) / (2 * n)) * (Z_i - (2 * t - 1) / (2 * n));
			
			// Anderson-Darling
			if(Z_i > 0.0 && Z_i < 1) A_f += (2 * t - 1)*log(Z_i) + (2*n+1-2*t)*log(1-Z_i);

			t++;
		}

	}
	W_f += 1 / (12 * n);
	A_f *= -1 / n;
	A_f += -n;
	cout << "D_+ = " << d_plus << endl;
	cout << "D_- = " << d_minus << endl;
	cout << "W2 = " << W_f << endl;
	cout << "A2 = " << A_f << endl << endl;
	return 0;
}

Double_t Kolmogorow::testBoth(TH1F* histo) {
	testVsHistogram(histo);
	testVsFunction(histo);
	return 0;
}

Double_t Kolmogorow::testVsHistogram(TH1F* histo) {

	cout << "Testing "<< histo->GetName() << " vs histogram." << endl;
	cout << "Bins: " << histo->GetNbinsX() << " vs " << reference->GetNbinsX() << endl;
	cout << "N: " << histo->Integral() << endl;

	TH1F* EDF = getCumHisto(histo);
	TH1F* F = reference_cum;

	// Initialize variables
	Double_t n = F->GetNbinsX();
	Double_t d_plus = 0.0, d_minus = 0.0;
	Double_t EDF_i = 0.0, F_i = 0.0, diff1 = 0.0, diff2 = 0.0, p_i = 0.0;
	W_h = A_h = D_h = 0.0;

	for (Int_t i = 0; i < n; i++) {
		EDF_i = EDF->GetBinContent(i);
		F_i = F->GetBinContent(i);
		diff1 = F_i - EDF_i;
		diff2 = EDF_i - F_i;
		if(diff1 > d_plus) d_plus = diff1;
		if(diff2 > d_minus) d_minus = diff2;

		p_i = reference->GetBinContent(i) / reference->Integral();

		W_h += pow(EDF_i - F_i, 2)*p_i;
		if ((F_i*(1 - F_i)) != 0.0) {
			A_h += pow(EDF_i - F_i, 2)*p_i / (F_i*(1 - F_i));
		}
		
	}

	d_plus *= sqrt(n);
	d_minus *= sqrt(n);
	
	W_h *= n;
	A_h *= n;

	cout << "D = " << TMath::Max(d_plus, d_minus) << endl;
	cout << "W2 = " << W_h << endl;
	cout << "A2 = " << A_h << endl << endl;

	return 0;
}


TH1F* Kolmogorow::getCumHisto(TH1F* histo) {
	// The amounts of bins in the histogram
	Int_t bins = histo->GetNbinsX();
	TH1F* cum = new TH1F("", "", bins, 0, 5000);
	Double_t cum_sum = 0.0;
	for (int i = 0; i < bins; i++) {
		Double_t content = histo->GetBinContent(i);
		cum_sum += content;
		cum->SetBinContent(i, cum_sum / histo->Integral());
	}
	return cum;
}

TGraph* Kolmogorow::setReferenceHistogram(TH1F* histo) {
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
	reference = histo;
	reference_cum = getCumHisto(histo);
	reference_graph = new TGraph(bins, x_points, y_points);
	return reference_graph;
}