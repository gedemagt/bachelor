#include "Analyzer.h"
#include "TH1F.h"
#include "Calibration.h"
#include "AnalysisClass.h"

class DSSDAnalyzer : public Analyzer {
public:
	DSSDAnalyzer(const char* dest);
	virtual ~DSSDAnalyzer() {};
	void analyze(Selector* s);
	void terminate();
	const char* getDestination();


private:
	const char* dest;

	TH1F* front_calib;
	TH1F* back_calib;

	TH1F* paired_21mg;

	Calibration Mg_Calib;
	Analysis Mg_Anal;
	Int_t NparEvent = 0, Npar = 0;
};