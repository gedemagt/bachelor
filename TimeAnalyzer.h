#pragma once
#include "Analyzer.h"
#include "TCutG.h"
#include "TH1F.h"
#include "TFile.h"
#include "Cuts.h"
#include "TimeCalc.h"

class TimeAnalyzer : public Analyzer {

public:
	TimeAnalyzer(const char* destination);
	virtual ~TimeAnalyzer() {};
	void analyze(Selector* s);
	void terminate();
	void setCuts(Cuts* cuts);

private:

	TimeCalc* calc;

	Int_t clockllast = 0, Nt1last = 0, clocks, clockl;
	Short_t egas;
	Short_t e1;

	Cuts* c;

};