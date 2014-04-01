
#include "TimeAnalyzer.h"
#include "DataLoader.h"
#include "Selector.h"
#include "TString.h"
#include "Cuts.h"
#include <iostream>
using namespace std;

struct cut {
	TCutG* tcut;
	char* name;
	TH1F* histo;
};

TimeAnalyzer::TimeAnalyzer() {
	
	// Load cuts
	DataLoader* l = new DataLoader();
	c = new Cuts(15);

	midCut = l->loadCut("Histogrammer/cuts/midCut.root", "CUTG");
	bottomCut = l->loadCut("Histogrammer/cuts/bottomCut.root", "CUTG");
	bottomCut2 = l->loadCut("Histogrammer/cuts/bottomCut2.root", "CUTG");
	bottomLeftCut = l->loadCut("Histogrammer/cuts/bottomLeftCut.root", "CUTG");
	leftCut = l->loadCut("Histogrammer/cuts/lotofcuts.root", "left");
	topRightCut = l->loadCut("Histogrammer/cuts/topRightCut.root", "CUTG");
	bottomClock3sCut = l->loadCut("Histogrammer/cuts/lotofcuts.root","bottom1");
	overflowCut = l->loadCut("Histogrammer/cuts/lotofcuts.root", "overflow");
	bottomClock3BigCut = l->loadCut("Histogrammer/cuts/protoncuts.root", "bigcut");
	

	TCutG* c1 = l->loadCut("Histogrammer/cuts/alphacuts.root", "Center1");
	TCutG* c2 = l->loadCut("Histogrammer/cuts/alphacuts.root", "center2");
	TCutG* c3 = l->loadCut("Histogrammer/cuts/alphacuts.root", "center3");
	TCutG* c4 = l->loadCut("Histogrammer/cuts/alphacuts.root", "center4");
	TCutG* ll = l->loadCut("Histogrammer/cuts/alphacuts.root", "left");
	TCutG* between = l->loadCut("Histogrammer/cuts/alphacuts.root", "between");

	c->setStandard1D(5000, 0, 5000);

	c->add1DCut(c1, "alpha_c1");
	c->add1DCut(c2, "alpha_c2");
	c->add1DCut(c3, "alpha_c3");
	c->add1DCut(c4, "alpha_c4");
	c->add1DCut(ll, "alpha_left");
	c->add1DCut(between, "alpha_between");

	c->add1DCut(midCut, "mid");
	c->add1DCut(bottomCut, "bottom");
	c->add1DCut(bottomCut2, "bottom2");
	c->add1DCut(bottomLeftCut, "bottomLeft");
	c->add1DCut(leftCut, "left");
	c->add1DCut(topRightCut, "topRight");
	c->add1DCut(bottomClock3sCut, "bottom3");
	c->add1DCut(overflowCut, "overflow");
	c->add1DCut(bottomClock3BigCut, "bottom3Big");

	// AL tids information
	allClocks = new TH1F("allClocks", "Al data: Clockl i sek.", 5000, 0, 5000);

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
		allClocks->Fill(clocks);
	}
}

const char* TimeAnalyzer::getDestination() {
	return "time";
}

void TimeAnalyzer::terminate() {
}

