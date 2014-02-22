#pragma once
#include "Analyzer.h"
#include "TCutG.h"
#include "TH1F.h"
#include "TFile.h"

class SiliciumAnalyzer : public Analyzer {

public:
	SiliciumAnalyzer();
	virtual ~SiliciumAnalyzer() {};
	void analyze(Selector* s);
	void terminate();
	char* getDestination();

private:
	void fillHistograms(Short_t Egas, Short_t E1);

	Short_t e1;

	TCutG* midCut;
	TCutG* leftCut;
	TCutG* topRightCut;
	TCutG* bottomCut;

	// AL information
	TH1F *allData;
	TH1F *midData;
	TH1F *leftData;
	TH1F *bottomData;
	TH1F *topRightData;

};