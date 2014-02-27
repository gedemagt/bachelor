
#include "BananaAnalyzer.h"
#include "DataLoader.h"
#include "Selector.h"
//#include "TString.h"
#include <iostream>
using namespace std;

BananaAnalyzer::BananaAnalyzer() {

	// Load cuts
	DataLoader* l = new DataLoader();
	midCut = l->loadCut("Histogrammer/cuts/midCut.root", "CUTG");
	bottomCut = l->loadCut("Histogrammer/cuts/bottomCut.root", "CUTG");
	bottomCut2 = l->loadCut("Histogrammer/cuts/bottomCut2.root", "CUTG");
	bottomLeftCut = l->loadCut("Histogrammer/cuts/bottomLeftCut.root", "CUTG");
	leftCut = l->loadCut("Histogrammer/cuts/leftCut.root", "CUTG");
	topRightCut = l->loadCut("Histogrammer/cuts/topRightCut.root", "CUTG");

	allData = new TH2F("allData", "Al data: E1 vs. Egas (counts/5kev)", 900, 0, 4500, 900, 0, 4500);
	midData = new TH2F("midBanan", "Mid data: E1 vs. Egas (counts/5kev)", 900, 0, 4500, 900, 0, 4500);
	bottomData = new TH2F("bottomBanan", "Bund data: E1 vs. Egas (counts/5kev)", 900, 0, 4500, 900, 0, 4500);
	bottomData2 = new TH2F("bottomBanan2", "Bund2 data: E1 vs. Egas (counts/5kev)", 900, 0, 4500, 900, 0, 4500);
	bottomLeftData = new TH2F("bottomLeftBanan", "BundLeft data: E1 vs. Egas (counts/5kev)", 900, 0, 4500, 900, 0, 4500);
	leftData = new TH2F("leftBanan", "Left data: E1 vs. Egas (counts/5kev)", 900, 0, 4500, 900, 0, 4500);
	topRightData = new TH2F("topRightBanan", "Right data: E1 vs. Egas (counts/5kev)", 900, 0, 4500, 900, 0, 4500);
}

void BananaAnalyzer::analyze(Selector* s) {
	fillHistograms(s->Egas, s->E1);
}

void BananaAnalyzer::fillHistograms(Short_t Egas, Short_t E1) {
	allData->Fill(E1, Egas);
	if (midCut->IsInside(E1, Egas)){
		midData->Fill(E1, Egas);
	}
	if (bottomCut->IsInside(E1, Egas)){
		bottomData->Fill(E1, Egas);
	}
	if (bottomCut2->IsInside(E1, Egas)){
		bottomData2->Fill(E1, Egas);
	}
	if (bottomLeftCut->IsInside(E1, Egas)){
		bottomLeftData->Fill(E1, Egas);
	}
	if (leftCut->IsInside(E1, Egas)){
		leftData->Fill(E1, Egas);
	}
	if (topRightCut->IsInside(E1, Egas)){
		topRightData->Fill(E1, Egas);
	}

}

char* BananaAnalyzer::getDestination() {
	return "bananamg20";
}

void BananaAnalyzer::terminate() {
}

