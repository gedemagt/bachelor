#pragma once
#include "Analyzer.h"
#include "TCutG.h"
#include "TH1F.h"
#include "TFile.h"
#include "Cuts.h"

class GasAnalyzer : public Analyzer {

public:
	GasAnalyzer(const char* dest);
	virtual ~GasAnalyzer() {};
	void analyze(Selector* s);
	void terminate();

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

	TCutG* proton_right_cut;
	TCutG* proton_mid_cut;
	TCutG* proton_left_mid_cut;
	TCutG* proton_left_cut;

	Cuts* c;
};