
#include "TimeAnalyzer.h"
#include "DataLoader.h"
#include "Selector.h"
#include "TString.h"
#include <iostream>
using namespace std;

TimeAnalyzer::TimeAnalyzer() {
	
	// Load cuts
	DataLoader* l = new DataLoader();
	midCut = l->loadCut("Histogrammer/cuts/midCut.root", "CUTG");
	bottomCut = l->loadCut("Histogrammer/cuts/bottomCut.root", "CUTG");
	bottomCut2 = l->loadCut("Histogrammer/cuts/bottomCut2.root", "CUTG");
	bottomLeftCut = l->loadCut("Histogrammer/cuts/bottomLeftCut.root", "CUTG");
	leftCut = l->loadCut("Histogrammer/cuts/lotofcuts.root", "left");
	topRightCut = l->loadCut("Histogrammer/cuts/topRightCut.root", "CUTG");
	bottomCut2 = l->loadCut("Histogrammer/cuts/bottomCut2.root", "CUTG");
	bottomClock3sCut = l->loadCut("Histogrammer/cuts/lotofcuts.root","bottom1");
	overflowCut = l->loadCut("Histogrammer/cuts/lotofcuts.root", "overflow");
	bottomClock3BigCut = l->loadCut("Histogrammer/cuts/protoncuts.root", "bigcut");

	// AL tids information
	allClocks = new TH1F("allClocks", "Al data: Clockl i sek.", 5000, 0, 5000);

	// Mid stuff
	midClocks = new TH1F("midClock", "Midt: Clockl i sek.", 5000, 0, 5000);

	// Bottom stuff
	bottomClocks = new TH1F("bottomClocks", "Bund: Clockl i sek.", 5000, 0, 5000);

	bottomClock2s = new TH1F("bottomClock2s", "Bund: Clockl i sek.", 5000, 0, 5000);

	bottomLeftClocks = new TH1F("bottomLeftClocks", "Bund: Clockl i sek.", 5000, 0, 5000);

	bottomClock3s = new TH1F("bottomClocks3", "Bund: Clockl i sek.", 5000, 0, 5000);
	bottomClockBigCut = new TH1F("bottomClockBigCut", "Bund: Clockl i sek.", 5000, 0, 5000);

	// Left stuff
	leftClocks = new TH1F("leftClocks", "Left: Clockl i sek.", 5000, 0, 5000);

	overflow = new TH1F("overflow", "Left overflow: Clockl i sek.", 5000, 0, 5000);

	// Top right stuff
	topRightClocks = new TH1F("topRightClocks", "Top/Højre: Clockl i sek.", 5000, 0, 5000);

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
		fillHistograms(egas, e1, clockl);
	}
}

void TimeAnalyzer::fillHistograms(Short_t Egas, Short_t E1, Int_t Clockl) {
	allClocks->Fill(clocks);
	if (midCut->IsInside(E1, Egas)){
		midClocks->Fill(clocks);
	}
	if (bottomCut->IsInside(E1, Egas)){
		bottomClocks->Fill(clocks);
	}
	if (bottomCut2->IsInside(E1, Egas)){
		bottomClock2s->Fill(clocks);
	}
	if (bottomLeftCut->IsInside(E1, Egas)){
		bottomLeftClocks->Fill(clocks);
	}
	if (leftCut->IsInside(E1, Egas)){
		leftClocks->Fill(clocks);
	}
	if (topRightCut->IsInside(E1, Egas)){
		topRightClocks->Fill(clocks);
	}
	if (overflowCut->IsInside(E1, Egas)) {
		overflow->Fill(clocks);
	}
	if (bottomClock3sCut->IsInside(E1, Egas)) {
		bottomClock3s->Fill(clocks);
	}
	if (bottomClock3BigCut->IsInside(E1, Egas)) {
		bottomClockBigCut->Fill(clocks);
	}

}

const char* TimeAnalyzer::getDestination() {
	return "time";
}

void TimeAnalyzer::terminate() {
}

