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
}