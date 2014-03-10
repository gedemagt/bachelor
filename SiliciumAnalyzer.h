#pragma once
#include "Analyzer.h"
#include "TCutG.h"
#include "TH1F.h"
#include "TFile.h"
#include "Calibration.h"

class SiliciumAnalyzer : public Analyzer {

public:
	SiliciumAnalyzer(Calib* ca);
	virtual ~SiliciumAnalyzer() {};
	void analyze(Selector* s);
	void terminate();
	const char* getDestination();

private:
	void fillHistograms(Short_t Egas_ch, Short_t E1_ch, Short_t Egas, Short_t E1);

	Short_t e1;

	Calib* ca;

	TCutG* midCut;
	TCutG* leftCut;
	TCutG* topRightCut;
	TCutG* bottomCut;
	TCutG* bottomCut2;
	TCutG* bottomLeftCut;

	// AL information
	TH1F *allData;
	TH1F *midData;
	TH1F *leftData;
	TH1F *bottomData;
	TH1F *bottomData2;
	TH1F *bottomLeftData;
	TH1F *topRightData;

};