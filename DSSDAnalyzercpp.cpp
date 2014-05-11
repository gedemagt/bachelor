#include "DSSDAnalyzer.h"

DSSDAnalyzer::DSSDAnalyzer(const char* dest) {
	Mg_Calib.LoadCalib();
	this->dest;
	front_calib = new TH1F("back_calib", "E_{back} - Calib", 1750, 0, 7000);
	back_calib = new TH1F("front_calib", "E_{back} - Calib", 1750, 0, 7000);
	paired_21mg = new TH1F("paired_21mg", "Ef and Eb matched", 1750, 0, 7000);
}

void DSSDAnalyzer::analyze(Selector* s) {
	Mg_Calib.Calibrate(s->Epad, s->E1, s->Ef, s->Nsfe, s->Nfe, s->Eb, s->Nsbe, s->Nbe);
	for (Int_t i = 0; i<s->Nfe; i++){
		front_calib->Fill(Mg_Calib.Efront[i]);
	}
	for (Int_t i = 0; i<s->Nbe; i++){
		back_calib->Fill(Mg_Calib.Eback[i]);
	}

	NparEvent = 0;
	NparEvent = Mg_Anal.EventMatching(Mg_Calib.Efront, s->Nfe, Mg_Calib.Eback, s->Nbe);
	Npar = Npar + NparEvent;

	for (Int_t k = 0; k<NparEvent; k++){
		if (s->Epad < 0.5){
			Double_t paired_value = (Mg_Calib.Efront[Mg_Anal.ifront_vec[k]] + Mg_Calib.Eback[Mg_Anal.iback_vec[k]]) / 2.;
			paired_21mg->Fill(paired_value);

			//tidsfordelinger
			//diverse cuts

		}
	}

}

const char* DSSDAnalyzer::getDestination() {
	TString *t = new TString(dest);
	return t->Data();
}

void DSSDAnalyzer::terminate() {
	TString rootFile = "Histogrammer/" + TString(getDestination()) + ".root";
	TFile* f = new TFile(rootFile, "recreate");

	f->WriteTObject(front_calib);
	f->WriteTObject(back_calib);
	f->WriteTObject(paired_21mg);

	f->Close();
}