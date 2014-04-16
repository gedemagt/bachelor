#include "Util.h"

namespace util{

	TH1F* getCumulatedHistogram(TH1F* histo, Int_t lower_bin, Int_t upper_bin, Bool_t normalized) {

		// The amounts of bins in the histogram
		Double_t max = histo->GetXaxis()->GetBinUpEdge(upper_bin);
		Double_t min = histo->GetXaxis()->GetBinUpEdge(lower_bin);
		Double_t integral = 1.0;
		if (normalized) integral = histo->Integral(lower_bin, upper_bin);
		TH1F* cum = new TH1F("", "", upper_bin - lower_bin, min, max);
		Double_t cum_sum = 0.0;
		for (int i = lower_bin; i < upper_bin; i++) {
			Double_t content = histo->GetBinContent(i);
			cum_sum += content;
			cum->SetBinContent(i, cum_sum / integral);
		}
		return cum;

	}
	
	TH1F* getSquaredHistogram(TH1F* histo, Int_t lower_bin, Int_t upper_bin, Bool_t normalized, Bool_t cumulated) {
		//histo->Draw();
		// The amounts of bins in the histogram
		Double_t max = histo->GetXaxis()->GetBinUpEdge(upper_bin);
		Double_t min = histo->GetXaxis()->GetBinUpEdge(lower_bin);
		//Double_t integral = 1.0;
		//if (normalized) integral = histo->Integral(lower_bin, upper_bin);
		TH1F* temp = new TH1F("", "", upper_bin - lower_bin, min, max);
		Double_t cum_sum = 0.0;
		Double_t content = 0.0;
		Double_t fill = 0.0;
		for (int i = lower_bin; i < upper_bin; i++) {
			content = histo->GetBinContent(i);
			cum_sum += content*content;
			if (cumulated) fill = cum_sum;
			else fill = content*content;
			temp->SetBinContent(i, fill);
		}
		if (normalized) temp->Scale(1.0/cum_sum);
		
		return temp;

	}

}