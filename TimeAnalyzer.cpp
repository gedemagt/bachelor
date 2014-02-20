
#include "TimeAnalyzer.h"
#include "DataLoader.h"
using namespace std;

TimeAnalyzer::TimeAnalyzer(char* filename) {
	file = new TFile("Histogrammer/histograms.root", "RECREATE");
	
	// Load cuts
	DataLoader* l = new DataLoader();
	midCut = l->loadCut("Histogrammer/midCut.root", "CUTG");
	bottomCut = l->loadCut("Histogrammer/bottomCut.root", "CUTG");
	leftCut = l->loadCut("Histogrammer/leftCut.root", "CUTG");
	topRightCut = l->loadCut("Histogrammer/topRightCut.root", "CUTG");

	// AL tids information
	allClockl = new TH1F("allClockl", "Al data: Clockl i sek.", 5000, 0, 3200000);
	allClocks = new TH1F("allClocks", "Al data: Clockl i sek.", 500, 0, 5000);

	// Mid stuff
	midClockl = new TH1F("midClockl", "Midt: Clockl i sek.", 5000, 0, 3200000);
	midClocks = new TH1F("midClock", "Midt: Clockl i sek.", 500, 0, 5000);

	// Bottom stuff
	bottomClockl = new TH1F("bottomClockl", "Bund: Clockl i sek.", 5000, 0, 3200000);
	bottomClocks = new TH1F("bottomClocks", "Bund: Clockl i sek.", 500, 0, 5000);

	// Left stuff
	leftClockl = new TH1F("leftClockl", "Left: Clockl i sek.", 5000, 0, 3200000);
	leftClocks = new TH1F("leftClocks", "Left: Clockl i sek.", 500, 0, 5000);

	// Top right stuff
	topRightClockl = new TH1F("topRightClockl", "Top/Højre: Clockl i sek.", 5000, 0, 3200000);
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
		fillHistograms(egas, e1);
	}
}

void TimeAnalyzer::fillHistograms(Short_t Egas, Short_t E1) {

	allClockl->Fill(clockl);
	allClocks->Fill(clocks);

}

void TimeAnalyzer::terminate() {
	file->Write();
	file->Close();
}
