#include "TH1F.h"
#include "TGraph.h"

class Kolmogorow {
public:
	Kolmogorow(){};
	~Kolmogorow(){};
	virtual TGraph* setReferenceHistogram(TH1F* histo);
	virtual Double_t testVsHistogram(TH1F* histo);
	virtual Double_t testVsFunction(TH1F* histo);
	virtual Double_t testBoth(TH1F* histo);
private:
	TH1F* getCumHisto(TH1F* histo);
	TGraph * reference_graph;
	TH1F* reference;
	TH1F* reference_cum;

	Double_t D_h, W_h, A_h, D_f, W_f, A_f;
};