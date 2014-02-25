
#include "SiliciumAnalyzer.h"
#include "DataLoader.h"
#include "Selector.h"
//#include "TString.h"
#include <iostream>
using namespace std;

SiliciumAnalyzer::SiliciumAnalyzer() {

	// Load cuts
	DataLoader* l = new DataLoader();
	midCut = l->loadCut("Histogrammer/cuts/midCut.root", "CUTG");
	bottomCut = l->loadCut("Histogrammer/cuts/bottomCut.root", "CUTG");
	bottomCut2 = l->loadCut("Histogrammer/cuts/bottomCut2.root", "CUTG");
	bottomLeftCut = l->loadCut("Histogrammer/cuts/bottomLeftCut.root", "CUTG");
	leftCut = l->loadCut("Histogrammer/cuts/leftCut.root", "CUTG");
	topRightCut = l->loadCut("Histogrammer/cuts/topRightCut.root", "CUTG");

	allData = new TH1F("allData", "Al data", 900, 0, 4500);
	midData = new TH1F("midBanan", "Mid data", 600, 0, 3000);
	bottomData = new TH1F("bottomBanan", "Bund data", 900, 0, 4500);
	bottomData2 = new TH1F("bottomBanan2", "Bund data", 900, 0, 4500);
	bottomLeftData = new TH1F("bottomLeftBanan", "Bund data", 900, 0, 4500);
	leftData = new TH1F("leftBanan", "Left data", 200, 0, 1000);
	topRightData = new TH1F("topRightBanan", "Right data", 200, 1500, 3000);
}

void SiliciumAnalyzer::analyze(Selector* s) {
	fillHistograms(s->Egas, s->E1);
}

void SiliciumAnalyzer::fillHistograms(Short_t Egas, Short_t E1) {
	allData->Fill(E1);
	if (midCut->IsInside(E1, Egas)){
		midData->Fill(E1);
	}
	if (bottomCut->IsInside(E1, Egas)){
		bottomData->Fill(E1);
	}
	if (bottomCut2->IsInside(E1, Egas)){
		bottomData2->Fill(E1);
	}
	if (bottomLeftCut->IsInside(E1, Egas)){
		bottomLeftData->Fill(E1);
	}
	if (leftCut->IsInside(E1, Egas)){
		leftData->Fill(E1);
	}
	if (topRightCut->IsInside(E1, Egas)){
		topRightData->Fill(E1);
	}

}

char* SiliciumAnalyzer::getDestination() {
	return "Silicium";
}

void SiliciumAnalyzer::terminate() {
}

