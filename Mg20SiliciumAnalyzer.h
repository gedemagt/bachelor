#pragma once
#include "Analyzer.h"
#include "TH1F.h"
#include "TFile.h"

class Mg20SiliciumAnalyzer : public Analyzer {

public:
	Mg20SiliciumAnalyzer();
	virtual ~Mg20SiliciumAnalyzer() {};
	void analyze(Selector* s);
	void terminate();
	const char* getDestination();

private:
	void fillHistograms(Short_t Egas, Short_t E1);

	Short_t e1;
	Short_t Egas;

	// AL information
	TH1F *peak1;
	TH1F *peak2;

};