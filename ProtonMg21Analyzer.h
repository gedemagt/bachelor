#include "Analyzer.h"
#include "TCutG.h"
#include "TH1F.h"
#include "TFile.h"
#include "TimeCalc.h"

using namespace std;

struct cut {
	Double_t left;
	Double_t right;
	const char* name;
};

class ProtonMg21Analyzer : public Analyzer {
public:
	ProtonMg21Analyzer(const char* dest);
	virtual ~ProtonMg21Analyzer() {};
	void analyze(Selector* s);
	void terminate();
private:
	TimeCalc* calc;
	Int_t n;
	bool isInside(Double_t E1, cut cut);
	TCutG* bottomCut2;

	TCutG* proton200_deep;
	TCutG* proton200_medium;
	TCutG* proton200_low;

	TH1F* peakHistograms;
	TH1F* timeHistograms;
	cut* cuts;

	TH1F* peak_200;
};