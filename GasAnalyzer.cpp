
#include "GasAnalyzer.h"
#include "DataLoader.h"
#include "Selector.h"
#include "RootTCut.h"
#include <iostream>
using namespace std;

GasAnalyzer::GasAnalyzer(const char* dest) : Analyzer(dest) {
	c = new Cuts(10);
	DataLoader* l = new DataLoader();
	midCut = l->loadCut("Histogrammer/cuts/midCut.root", "CUTG");
	leftCut = l->loadCut("Histogrammer/cuts/leftCut.root", "CUTG");

	proton_right_cut = l->loadCut("Histogrammer/cuts/tailcuts.root", "right");
	proton_mid_cut = l->loadCut("Histogrammer/cuts/tailcuts.root", "middle");
	proton_left_mid_cut = l->loadCut("Histogrammer/cuts/tailcuts.root", "leftmid");
	proton_left_cut = l->loadCut("Histogrammer/cuts/tailcuts.root", "left");
	
	c->add1DCut(new RootTCut(proton_right_cut), "tail_21", 300, 0, 1500); // peak 21
	c->add1DCut(new RootTCut(proton_mid_cut), "tail_6", 300, 0, 1500); // peak 6
	c->add1DCut(new RootTCut(proton_left_mid_cut), "tail_1", 500, 0, 2500); // peak 1
	c->add1DCut(new RootTCut(proton_left_cut), "tail_y", 500, 0, 2500); // y-aksen

	peak1Gas = new TH1F("proton1gas","Proton peak1 i gas", 500, 0, 1000);
	peak2Gas = new TH1F("proton2gas","Proton peak2 i gas", 500, 0, 1000);

	peak1Si = new TH1F("proton1Si","Proton peak1 i Si", 150, 1100, 1400);
	peak2Si = new TH1F("proton2Si","Proton peak2 i Si", 200, 1200, 1600);

	alfa1Gas = new TH1F("alfaRight", "Right alfa", 300, 1000, 3300);
	alfa2Gas = new TH1F("alfaLeft", "Left alfa", 300, 1000, 3000);

}

void GasAnalyzer::analyze(Selector* s) {
	fillHistograms(s->Egas, s->E1);
}

void GasAnalyzer::fillHistograms(Short_t Egas, Short_t E1) {
	c->fill1D(E1, Egas, Egas);
	if (Egas < 1000 && Egas > 0){
		if (E1 < 1287 && E1 > 1146) {
			peak1Gas->Fill(Egas);
			peak1Si->Fill(E1);
		}
		if (E1 > 1287 && E1 < 1569) {
			peak2Gas->Fill(Egas);
			peak2Si->Fill(E1);
		}
	}
	if (midCut->IsInside(E1, Egas)) {
		alfa1Gas->Fill(Egas);
	}
	if (leftCut->IsInside(E1, Egas)) {
		alfa2Gas->Fill(Egas);
	}
}

void GasAnalyzer::terminate() {
	TString rootFile = "Histogrammer/" + TString(getDestination()) + ".root";
	TFile* f = new TFile(rootFile, "recreate");
	f->WriteTObject(peak1Gas);
	f->WriteTObject(peak2Gas);
	f->WriteTObject(peak1Si);
	f->WriteTObject(peak2Si);
	f->WriteTObject(alfa1Gas);
	f->WriteTObject(alfa2Gas);
	c->writeToFile(f);
	f->Close();
}

