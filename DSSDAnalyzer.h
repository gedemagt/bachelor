#include "Analyzer.h"
#include "TH1F.h"
#include "Calibration.h"
#include "AnalysisClass.h"
#include "TimeCalc.h"

class DSSDAnalyzer : public Analyzer {
public:
	DSSDAnalyzer(const char* dest);
	virtual ~DSSDAnalyzer() {};
	void analyze(Selector* s);
	void terminate();

private:

	TH1F* front_calib;
	TH1F* back_calib;

	TH1F* paired_21mg;

	TH1F* time_24;
	TH1F* time_33;
	TH1F* time_38;
	TH1F* time_46;
	TH1F* time_62;

	Calibration Mg_Calib;
	TimeCalc* calc;
	Analysis Mg_Anal;
	Int_t NparEvent = 0, Npar = 0;
};