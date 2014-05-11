#pragma once
#include "Analyzer.h"
#include "TH1F.h"
#include "TFile.h"

class Mg20GasAnalyzer : public Analyzer {

public:
	Mg20GasAnalyzer(const char* dest);
	virtual ~Mg20GasAnalyzer() {};
	void analyze(Selector* s);
	void terminate();
	const char* getDestination();

private:
	void fillHistograms(Short_t Egas, Short_t E1);

	const char* dest;
	Short_t e1;
	Short_t Egas;

	// AL information
	TH1F *peak1;
	TH1F *peak2;

};