
#include "TimeAnalyzer.h"
#include "DataLoader.h"
#include "Selector.h"
#include "TString.h"
#include "Cuts.h"
#include "RootTCut.h"
#include <iostream>
using namespace std;

TimeAnalyzer::TimeAnalyzer(const char* destination) : Analyzer(destination) {
	calc = new TimeCalc();
}

void TimeAnalyzer::analyze(Selector* s) {
	calc->calculateNewEvent(s);
	egas = s->Egas;
	e1 = s->E1;
	if (calc->shouldFill()) {
		c->fill1D(e1, egas, calc->getClocks());
	}
}

void TimeAnalyzer::setCuts(Cuts* cuts) {
	c = cuts;
}

void TimeAnalyzer::terminate() {
	TString rootFile = "Histogrammer/" + TString(getDestination()) + ".root";
	TFile* f = new TFile(rootFile, "recreate");
	c->writeToFile(f);
	f->Close();
}

