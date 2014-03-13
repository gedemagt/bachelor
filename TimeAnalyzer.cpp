
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
	leftCut = l->loadCut("Histogrammer/cuts/leftCut.root", "CUTG");
	topRightCut = l->loadCut("Histogrammer/cuts/topRightCut.root", "CUTG");
	bottomCut2 = l->loadCut("Histogrammer/cuts/bottomCut2.root", "CUTG");

	// AL tids information
	//allClockl = new TH1F("allClockl", "Al data: Clockl i sek.", 5000, 0, 3200000);
	allClocks = new TH1F("allClocks", "Al data: Clockl i sek.", 500, 0, 5000);

	// Mid stuff
	//midClockl = new TH1F("midClockl", "Midt: Clockl i sek.", 5000, 0, 3200000);
	midClocks = new TH1F("midClock", "Midt: Clockl i sek.", 500, 0, 5000);

	// Bottom stuff
	//bottomClockl = new TH1F("bottomClockl", "Bund: Clockl i sek.", 5000, 0, 3200000);
	bottomClocks = new TH1F("bottomClocks", "Bund: Clockl i sek.", 500, 0, 5000);

	//bottomClock2l = new TH1F("bottomClock2l", "Bund: Clockl i sek.", 5000, 0, 3200000);
	bottomClock2s = new TH1F("bottomClock2s", "Bund: Clockl i sek.", 500, 0, 5000);

	//bottomLeftClockl = new TH1F("bottomLeftClockl", "Bund: Clockl i sek.", 5000, 0, 3200000);
	bottomLeftClocks = new TH1F("bottomLeftClocks", "Bund: Clockl i sek.", 500, 0, 5000);

	// Left stuff
	//leftClockl = new TH1F("leftClockl", "Left: Clockl i sek.", 5000, 0, 3200000);
	leftClocks = new TH1F("leftClocks", "Left: Clockl i sek.", 500, 0, 5000);

	// Top right stuff
	//topRightClockl = new TH1F("topRightClockl", "Top/Højre: Clockl i sek.", 5000, 0, 3200000);
	topRightClocks = new TH1F("topRightClocks", "Top/Højre: Clockl i sek.", 500, 0, 5000);
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
	//allClockl->Fill(clockl);
	allClocks->Fill(clocks);
	if (midCut->IsInside(E1, Egas)){
		//midClockl->Fill(Clockl);
		midClocks->Fill(clocks);
	}
	if (bottomCut->IsInside(E1, Egas)){
		//bottomClockl->Fill(Clockl);
		bottomClocks->Fill(clocks);
	}
	if (bottomCut2->IsInside(E1, Egas)){
		//bottomClock2l->Fill(Clockl);
		bottomClock2s->Fill(clocks);
	}
	if (bottomLeftCut->IsInside(E1, Egas)){
		//bottomLeftClockl->Fill(Clockl);
		bottomLeftClocks->Fill(clocks);
	}
	if (leftCut->IsInside(E1, Egas)){
		//leftClockl->Fill(Clockl);
		leftClocks->Fill(clocks);
	}
	if (topRightCut->IsInside(E1, Egas)){
		//topRightClockl->Fill(Clockl);
		topRightClocks->Fill(clocks);
	}

}

const char* TimeAnalyzer::getDestination() {
	return "time";
}

void TimeAnalyzer::terminate() {
}

