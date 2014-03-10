#pragma once
#include "Analyzer.h"
#include "TCutG.h"
#include "TH1F.h"
#include "TFile.h"

class TimeAnalyzer : public Analyzer {

public:
	TimeAnalyzer();
	virtual ~TimeAnalyzer() {};
	void analyze(Selector* s);
	void terminate();
	const char* getDestination();

private:
	void fillHistograms(Short_t Egas, Short_t E1, Int_t Clockl);

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

	// AL tids information
	TH1F *allClockl;
	TH1F *allClocks;

	// Mid stuff
	TH1F *midClockl;
	TH1F *midClocks;

	// Bottom stuff
	TH1F *bottomClockl;
	TH1F *bottomClocks;

	TH1F *bottomClock2s;
	TH1F *bottomClock2l;

	TH1F *bottomLeftClocks;
	TH1F *bottomLeftClockl;

	// Left stuff
	TH1F *leftClockl;
	TH1F *leftClocks;

	// Top right stuff
	TH1F *topRightClockl;
	TH1F *topRightClocks;


};