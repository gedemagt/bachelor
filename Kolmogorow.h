#include "TH1F.h"
#include "TGraph.h"

class Kolmogorow {
public:
	Kolmogorow(){};
	~Kolmogorow(){};
	virtual TGraph* setReferenceHistogram(TH1F* histo);
	virtual Double_t testVsHistogram(TH1F* histo);
	virtual Double_t testVsHistogram(TH1F* histo, Int_t lower_bin, Int_t upper_bin);
	virtual Double_t testVsFunction(TH1F* histo);
	virtual Double_t testVsFunction(TH1F* histo, Int_t lower_bin, Int_t upper_bin);
	virtual Double_t testBoth(TH1F* histo);
	virtual Double_t testBoth(TH1F* histo, Int_t lower_bin, Int_t upper_bin);
	Double_t D_h, W_h, A_h, D_f, W_f, A_f;
private:
	TGraph * reference_graph;
	TH1F* reference;
	TH1F* reference_cum;
	Bool_t both = false;
	
};