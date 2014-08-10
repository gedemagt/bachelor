#include "LaseroffAnalyzer.h"
#include "Selector.h"


LaseroffAnalyzer::LaseroffAnalyzer(const char* dest) : Analyzer(dest) {
	allData = new TH2F("allData", "Al data : E1 vs.Egas(counts / 5kev)", 900, 0, 4500, 900, 0, 4500);
	allTime = new TH1F("allTime", "Tid af hjørne", 5000, 0, 5000);
	calc = new TimeCalc();
}

void LaseroffAnalyzer::analyze(Selector* s) {
	calc->calculateNewEvent(s);
	allData->Fill(s->E1, s->Egas);
	if(s->E1 < 1000 && s->E1 > 97 && s->Egas >105 && s->Egas < 1400) calc->fillHistogram(allTime);
}

void LaseroffAnalyzer::terminate() {
	TString rootFile = "Histogrammer/" + TString(getDestination()) + ".root";
	TFile* f = new TFile(rootFile, "recreate");
	f->WriteTObject(allData);
	f->WriteTObject(allTime);
	f->Close();
}