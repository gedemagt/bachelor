#pragma once
#include "Analyzer.h"
#include "TCutG.h"
#include "TH1F.h"
#include "TFile.h"

class TimeAnalyzer : public Analyzer {

public:
	TimeAnalyzer(char* filename);
	virtual ~TimeAnalyzer() {};
	void analyze(Selector* s);
	void terminate();

private:
	void fillHistograms(Short_t Egas, Short_t E1);

	Int_t clockllast = 0, Nt1last = 0, clocks, clockl;
	Short_t egas;
	Short_t e1;

	TFile *file;

	TCutG* midCut;
	TCutG* leftCut;
	TCutG* topRightCut;
	TCutG* bottomCut;

	// AL tids information
	TH1F *allClockl;
	TH1F *allClocks;

	// Mid stuff
	TH1F *midClockl;
	TH1F *midClocks;

	// Bottom stuff
	TH1F *bottomClockl;
	TH1F *bottomClocks;

	// Left stuff
	TH1F *leftClockl;
	TH1F *leftClocks;

	// Top right stuff
	TH1F *topRightClockl;
	TH1F *topRightClocks;


};