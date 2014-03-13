#include "Analyzer.h"
#include "TCutG.h"
#include "TH1F.h"
#include "TFile.h"

using namespace std;

struct cut {
	Double_t left;
	Double_t right;
	const char* name;
};

class ProtonMg21Analyzer : public Analyzer {
public:
	ProtonMg21Analyzer();
	virtual ~ProtonMg21Analyzer() {};
	void analyze(Selector* s);
	void terminate();
	const char* getDestination();
private:
	Int_t clockllast = 0, Nt1last = 0, clocks, clockl;
	Int_t n;
	bool isInside(Double_t E1, cut cut);
	TCutG* bottomCut2;
	TH1F* peakHistograms;
	TH1F* timeHistograms;
	cut* cuts;

};