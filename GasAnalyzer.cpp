
#include "GasAnalyzer.h"
#include "DataLoader.h"
#include "Selector.h"
//#include "TString.h"
#include <iostream>
using namespace std;

GasAnalyzer::GasAnalyzer() {

	peak1 = new TH1F("peak1", "Egas", 500, 0, 1000);
	peak2 = new TH1F("peak2", "Egas", 500, 0, 1000);
}

void GasAnalyzer::analyze(Selector* s) {
	fillHistograms(s->Egas, s->E1);
}

void GasAnalyzer::fillHistograms(Short_t Egas, Short_t E1) {
	if (Egas < 1000 && Egas > 0){
		if (E1 < 1287 && E1 > 1146) {
			peak1->Fill(Egas);
		}
		if (E1 > 1287 && E1 < 1569) {
			peak2->Fill(Egas);
		}
	}


}

char* GasAnalyzer::getDestination() {
	return "Gas";
}

void GasAnalyzer::terminate() {
}

