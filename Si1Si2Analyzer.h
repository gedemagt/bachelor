#pragma once
#include "Analyzer.h"
#include "TCutG.h"
#include "TH2F.h"
#include "TFile.h"
#include "Calibration.h"

#ifndef SI1SI2_H
#define SI1SI2_H

class Si1Si2Analyzer : public Analyzer {

public:
	Si1Si2Analyzer(const char* dest);
	virtual ~Si1Si2Analyzer() {};
	void analyze(Selector* s);
	void terminate();
	const char* getDestination();

private:
	void fillTimeHistogram(Selector*s, TH1F* time);

	Short_t e1;
	Int_t clockllast = 0, Nt1last = 0, clocks, clockl;
	Calibration Mg_Calib;
	const char* dest;

	// AL information
	TH2F * allData;
	TH2F* cutted;
	TH1F* time;
	TH1F* silicium1;
	TH1F* silicium2;

	TH1F* time_s2_left;
	TH1F* time_s2_right;

};

#endif