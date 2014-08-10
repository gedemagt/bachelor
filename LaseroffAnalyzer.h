
#include "Analyzer.h"
#include "TCutG.h"
#include "TH2F.h"
#include "TFile.h"
#include "TimeCalc.h"

class LaseroffAnalyzer : public Analyzer {

public:
	LaseroffAnalyzer(const char* dest);
	virtual ~LaseroffAnalyzer() {};
	void analyze(Selector* s);
	void terminate();

private:

	//Histogrammer
	TH2F *allData;
	TH1F *allTime;

	TimeCalc* calc;

};