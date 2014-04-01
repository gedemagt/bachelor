#pragma once
#include "Analyzer.h"
#include "TCutG.h"
#include "TH1F.h"
#include "TFile.h"
#include "Cuts.h"

class TimeAnalyzer : public Analyzer {

public:
	TimeAnalyzer();
	virtual ~TimeAnalyzer() {};
	void analyze(Selector* s);
	void terminate();
	const char* getDestination();

private:

	Int_t clockllast = 0, Nt1last = 0, clocks, clockl;
	Short_t egas;
	Short_t e1;

	//TFile *file;

	TCutG* midCut;
	TCutG* leftCut;
	TCutG* topRightCut;
	TCutG* bottomCut;
	TCutG* bottomCut2;
	TCutG* bottomLeftCut;
	TCutG* overflowCut;
	TCutG* bottomClock3sCut;
	TCutG* bottomClock3BigCut;

	// AL tids information
	TH1F *allClocks;
	Cuts* c;

};