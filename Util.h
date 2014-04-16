#include "TH1F.h"

namespace util{
	TH1F* getCumulatedHistogram(TH1F* histo, Int_t lower_bin, Int_t upper_bin, Bool_t normalized);
	TH1F* getSquaredHistogram(TH1F* histo, Int_t lower_bin, Int_t upper_bin, Bool_t normalized, Bool_t cumulated);
}