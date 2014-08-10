#include "DSSDAnalyzer.h"
//#include "Macros.h"

DSSDAnalyzer::DSSDAnalyzer(const char* dest) : Analyzer(dest){
	Mg_Calib.LoadCalib();
	front_calib = new TH1F("back_calib", "E_{back} - Calib", 1750, 0, 7000);
	back_calib = new TH1F("front_calib", "E_{back} - Calib", 1750, 0, 7000);
	paired_21mg = new TH1F("paired_21mg", "Ef and Eb matched", 1750, 0, 7000);

	time_24 = new TH1F("time_24", "2.4 keV", 5000, 0, 5000);
	time_33 = new TH1F("time_33", "3.3 keV", 5000, 0, 5000);
	time_38 = new TH1F("time_38", "3.8 keV", 5000, 0, 5000);
	time_46 = new TH1F("time_46", "4.6 keV", 5000, 0, 5000);
	time_62 = new TH1F("time_62", "6.2 keV", 5000, 0, 5000);

	calc = new TimeCalc();
}

void DSSDAnalyzer::analyze(Selector* s) {
	calc->calculateNewEvent(s);
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
			if (paired_value > 6000 && paired_value < 6500) {
				calc->fillHistogram(time_62);
			}
			if (paired_value > 4500 && paired_value < 5000) {
				calc->fillHistogram(time_46);
			}
			if (paired_value > 3700 && paired_value < 4100) {
				calc->fillHistogram(time_38);
			}
			if (paired_value > 3100 && paired_value < 3500) {
				calc->fillHistogram(time_33);
			}
			if (paired_value > 2300 && paired_value < 2600) {
				calc->fillHistogram(time_24);
			}


			//diverse cuts

		}
	}

}

void DSSDAnalyzer::terminate() {
	TString rootFile = "Histogrammer/" + TString(getDestination()) + ".root";
	TFile* f = new TFile(rootFile, "recreate");

	f->WriteTObject(front_calib);
	f->WriteTObject(back_calib);
	f->WriteTObject(paired_21mg);

	f->WriteTObject(time_24);
	f->WriteTObject(time_33);
	f->WriteTObject(time_38);
	f->WriteTObject(time_46);
	f->WriteTObject(time_62);

	f->Close();
	//analyzeDSSD();
}