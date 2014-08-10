#include "Analyzer.h"
#include "TH1F.h"
#include "TCutG.h"
#include "TimeCalc.h"

class BetaAnalyzer : public Analyzer {
public:
	BetaAnalyzer(const char* dest);
	~BetaAnalyzer(){};
	void analyze(Selector* s);
	void terminate();

private:
	TH1F* left;
	TH1F* middle;
	TH1F* right;


	TimeCalc* calc;
	TCutG* innerCut;
};