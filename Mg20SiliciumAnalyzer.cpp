#include "Mg20SiliciumAnalyzer.h"
#include "DataLoader.h"
#include "Selector.h"
#include <iostream>
using namespace std;

Mg20SiliciumAnalyzer::Mg20SiliciumAnalyzer(const char* dest) : Analyzer(dest){
	peak1 = new TH1F("peak1", "Silicium - 20mg", 500, 1000, 1500);
	peak2 = new TH1F("peak2", "Silicium - 20mg", 250, 2900, 3155);
}

void Mg20SiliciumAnalyzer::analyze(Selector* s) {
	fillHistograms(s->Egas, s->E1);
}

void Mg20SiliciumAnalyzer::fillHistograms(Short_t Egas, Short_t E1) {

	//peak 1
	if (Egas > 920 && E1 > 1000 && E1<1508) {
		peak1->Fill(E1);
	}
	if (Egas > 540 && E1 > 2850 && E1 < 3165) {
		peak2->Fill(E1);
	}
}

void Mg20SiliciumAnalyzer::terminate() {
	TString rootFile = "Histogrammer/" + TString(getDestination()) + ".root";
	TFile* f = new TFile(rootFile, "recreate");
	f->WriteTObject(peak1);
	f->WriteTObject(peak2);
	f->Close();
}

