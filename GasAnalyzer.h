#pragma once
#include "Analyzer.h"
#include "TCutG.h"
#include "TH1F.h"
#include "TFile.h"

class GasAnalyzer : public Analyzer {

public:
	GasAnalyzer();
	virtual ~GasAnalyzer() {};
	void analyze(Selector* s);
	void terminate();
	const char* getDestination();

private:
	void fillHistograms(Short_t Egas, Short_t E1);

	Short_t e1;
	Short_t Egas;

	// AL information
	TH1F *peak1Gas;
	TH1F *peak2Gas;
	TH1F *peak1Si;
	TH1F *peak2Si;

	TH1F *alfa1Gas;
	TH1F *alfa2Gas;

	TCutG* midCut;
	TCutG* leftCut;

};