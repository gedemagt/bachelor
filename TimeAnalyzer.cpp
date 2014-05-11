
#include "TimeAnalyzer.h"
#include "DataLoader.h"
#include "Selector.h"
#include "TString.h"
#include "Cuts.h"
#include "RootTCut.h"
#include <iostream>
using namespace std;

TimeAnalyzer::TimeAnalyzer(const char* destination) : Analyzer(destination) {
	
}

void TimeAnalyzer::analyze(Selector* s) {
	egas = s->Egas;
	e1 = s->E1;
	clockl = s->Clockl;
	// Calculte clock stuff
	clocks = 0;
	if (s->Clockl > clockllast){
		clocks = s->Clockl - clockllast;
		if (s->Nt1 > Nt1last){
			clockllast = s->Clockl;
			Nt1last = s->Nt1;
		}
		c->fill1D(e1, egas, clocks);
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

