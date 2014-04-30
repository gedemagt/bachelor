#include "Kolmogorow.h"
#include <iostream>
#include "TMath.h"
#include "TRandom1.h"
#include "Util.h"
using namespace std;

Double_t Kolmogorow::testVsFunction(TH1F* histo, Int_t lower_bin, Int_t upper_bin) {

	if(!both) cout << "-----------------------" << endl;
	if (!both) cout << "Testing " << histo->GetName() << endl;
	if (!both) cout << "Using bin " << lower_bin << " to bin " << upper_bin << endl;
	if (!both) cout << "Tested entries: " << histo->Integral(lower_bin, upper_bin) << endl;
	cout << "Testing type: Function" << endl;
	
	// Initialize random object using the RanLux generator
	TRandom1* r = new TRandom1();
	Int_t bins = histo->GetNbinsX();
	Double_t n = histo->Integral(lower_bin, upper_bin);
	TH1F* cum = util::getCumulatedHistogram(histo, lower_bin ,upper_bin, true);

	// Initialize variables
	W_f = A_f = D_f = 0.0;
	Double_t d_plus = 0.0, d_minus = 0.0;
	Double_t width = 0.0, current_plus = 0.0, current_minus = 0.0, k = 0.0, Z_i = 0.0;
	Int_t t = 0;

	for (Int_t i = lower_bin; i < upper_bin; i++) {

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
			if (Z_i > 0.0 && Z_i < 1) A_f += (2 * t - 1)*log(Z_i) + (2 * n + 1 - 2 * t)*log(1 - Z_i);

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
	cout << "-----------------------" << endl;
	return 0;

}

Double_t Kolmogorow::testVsHistogram(TH1F* histo, Int_t lower_bin, Int_t upper_bin) {
	if (_report) {
		cout << "-----------------------" << endl;
		cout << "Testing " << histo->GetName() << endl;
		cout << "Reference " << reference->GetName() << endl;
		cout << "Using bin " << lower_bin << " to bin " << upper_bin << endl;
		cout << "Tested entries: " << histo->Integral(lower_bin, upper_bin) << endl;
		if (both) cout << endl;
		cout << "Testing type: Histogram" << endl;
	}

	TH1F* EDF = util::getCumulatedHistogram(histo, lower_bin, upper_bin, true);
	//EDF->Draw();
	if (lower_F != lower_bin || upper_F != upper_bin || new_reference){
		
		delete F;
		F = util::getCumulatedHistogram(reference, lower_bin, upper_bin, true);
		lower_F = lower_bin;
		upper_F = upper_bin;
		new_reference = false;
	}
	//F->Draw("same");

	// Initialize variables
	Double_t n = upper_bin;
	Double_t d_plus = 0.0, d_minus = 0.0;
	Double_t EDF_i = 0.0, F_i = 0.0, diff1 = 0.0, diff2 = 0.0, p_i = 0.0;
	W_h = A_h = D_h = 0.0;

	for (Int_t i = lower_bin; i < n; i++) {
		EDF_i = EDF->GetBinContent(i);
		F_i = F->GetBinContent(i);
		diff1 = F_i - EDF_i;
		diff2 = EDF_i - F_i;
		if (diff1 > d_plus) d_plus = diff1;
		if (diff2 > d_minus) d_minus = diff2;

		p_i = reference->GetBinContent(i) / reference->Integral(lower_bin, upper_bin);

		W_h += pow(EDF_i - F_i, 2)*p_i;
		if ((F_i*(1 - F_i)) != 0.0) {
			A_h += pow(EDF_i - F_i, 2)*p_i / (F_i*(1 - F_i));
		}

	}

	Double_t total = histo->Integral(lower_bin, upper_bin);

	d_plus *= sqrt(total);
	d_minus *= sqrt(total);

	W_h *= total;
	A_h *= total;
	D_h = TMath::Max(d_plus, d_minus);

	if (_report) {
		cout << "D = " << D_h << endl;
		cout << "W2 = " << W_h << endl;
		cout << "A2 = " << A_h << endl << endl;
		if (!both) cout << "-----------------------" << endl;
	}
	return 0;
}

Double_t Kolmogorow::testBoth(TH1F* histo, Int_t lower_bin, Int_t upper_bin) {
	both = true;
	testVsHistogram(histo, lower_bin, upper_bin);
	testVsFunction(histo, lower_bin, upper_bin);
	both = false;
	return 0;
}

Double_t Kolmogorow::testVsFunction(TH1F* histo) {
	return testVsFunction(histo, 0, histo->GetNbinsX());
}

Double_t Kolmogorow::testBoth(TH1F* histo) {
	both = true;
	testVsHistogram(histo);
	testVsFunction(histo);
	both = false;
	return 0;
}

Double_t Kolmogorow::testVsHistogram(TH1F* histo) {
	return testVsHistogram(histo, 0, histo->GetNbinsX());
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
	reference_cum = util::getCumulatedHistogram(histo, 0, histo->GetNbinsX(), true);
	reference_graph = new TGraph(bins, x_points, y_points);
	new_reference = true;
	return reference_graph;
}

void Kolmogorow::report(Bool_t should_report) {
	_report = should_report;
}