
#include "GasAnalyzer.h"
#include "DataLoader.h"
#include "Selector.h"
#include <iostream>
using namespace std;

GasAnalyzer::GasAnalyzer() {

	peak1Gas = new TH1F("peak1Gas", "Egas", 500, 0, 1000);
	peak2Gas = new TH1F("peak2Gas", "Egas", 500, 0, 1000);

	peak1Si = new TH1F("peak1Si", "Egas", 150, 1100, 1400);
	peak2Si = new TH1F("peak2Si", "Egas", 200, 1200, 1600);
}

void GasAnalyzer::analyze(Selector* s) {
	fillHistograms(s->Egas, s->E1);
}

void GasAnalyzer::fillHistograms(Short_t Egas, Short_t E1) {
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
}

char* GasAnalyzer::getDestination() {
	return "Gas";
}

void GasAnalyzer::terminate() {
}

