#include "Mg20GasAnalyzer.h"
#include "DataLoader.h"
#include "Selector.h"
#include <iostream>
using namespace std;

Mg20GasAnalyzer::Mg20GasAnalyzer(const char* dest) : Analyzer(dest) {

	peak1 = new TH1F("peak1", "Egas", 500, 1000, 2000);
	peak2 = new TH1F("peak2", "Egas", 400, 490, 1700);


}

void Mg20GasAnalyzer::analyze(Selector* s) {
	fillHistograms(s->Egas, s->E1);
}

void Mg20GasAnalyzer::fillHistograms(Short_t Egas, Short_t E1) {

	//peak 1
	if (Egas > 920 && E1 > 1000 && E1<1508) {
		peak1->Fill(Egas);
	}
	if (Egas > 540 && E1 > 2850 && E1 < 3165) {
		peak2->Fill(Egas);
	}
}

void Mg20GasAnalyzer::terminate() {
	TString rootFile = "Histogrammer/" + TString(getDestination()) + ".root";
	TFile* f = new TFile(rootFile, "recreate");
	f->WriteTObject(peak1);
	f->WriteTObject(peak2);
	f->Close();
}

