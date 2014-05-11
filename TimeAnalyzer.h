#pragma once
#include "Analyzer.h"
#include "TCutG.h"
#include "TH1F.h"
#include "TFile.h"
#include "Cuts.h"

class TimeAnalyzer : public Analyzer {

public:
	TimeAnalyzer(const char* destination);
	virtual ~TimeAnalyzer() {};
	void analyze(Selector* s);
	void terminate();
	const char* getDestination();
	void setCuts(Cuts* cuts);

private:

	Int_t clockllast = 0, Nt1last = 0, clocks, clockl;
	Short_t egas;
	Short_t e1;

	Cuts* c;

	const char* dest;

};