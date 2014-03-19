#include "TH1F.h"
#include "TGraph.h"

class Kolmogorow {
public:
	Kolmogorow(){};
	~Kolmogorow(){};
	virtual TGraph* generateFunction(TH1F* histo);
	virtual Double_t testHistogram(TH1F* histo);
	virtual Double_t compareHistograms(TH1F* h1, TH1F* h2);
private:
	TH1F* getCumHisto(TH1F* histo);
	TGraph * graph;
};