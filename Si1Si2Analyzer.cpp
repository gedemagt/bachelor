
#include "Si1Si2Analyzer.h"
#include "DataLoader.h"
#include "Selector.h"
#include <iostream>
#include "Calibration.h"
//#include "Macros.h"
using namespace std;

Si1Si2Analyzer::Si1Si2Analyzer(const char* dest) : Analyzer(dest) {
	Mg_Calib.LoadCalib();

	calc = new TimeCalc();

	allData = new TH2F("all", "E1 vs. E2 ", 900, 0, 4500, 900, 0, 4500);
	cutted = new TH2F("cutted", "E1 vs. E2 -cutted ", 900, 0, 4500, 900, 0, 4500);
	time = new TH1F("time", "cutted_time", 5000, 0, 5000);

	silicium1 = new TH1F("silicium1", "silicium1", 1000, 0, 4000);
	silicium2 = new TH1F("silicium2", "silicium2", 1000, 0, 4000);

	time_s2_left = new TH1F("si_2_left", "si_2_left", 5000, 0, 5000);
	time_s2_right = new TH1F("si_2_right", "si_2_right", 5000, 0, 5000);


}

void Si1Si2Analyzer::fillTimeHistogram(Selector*s, TH1F* histo) {
	//if (s->Clockl > clockllast){
	//	histo->Fill(clocks);
	//}
}

void Si1Si2Analyzer::analyze(Selector* s) {
	// Calculate time stuff
	calc->calculateNewEvent(s);
	// Calculate calibration
	Mg_Calib.Calibrate(s->Epad, s->E1, s->Ef, s->Nsfe, s->Nfe, s->Eb, s->Nsbe, s->Nbe);
	
	allData->Fill(s->E1, s->E2);

	if (Mg_Calib.E1_calib > (s->E2*(3000. - 5700.) / (1250.) + 5700.)){
		if (Mg_Calib.E1_calib < 5780.){
			
			cutted->Fill(s->E1, s->E2);
			silicium1->Fill(s->E1);
			silicium2->Fill(s->E2);
			calc->fillHistogram(time);

			// Cut it in two
			if (s->E2 < 700) calc->fillHistogram(time_s2_left);
			else calc->fillHistogram(time_s2_right);
		}
	}

}

void Si1Si2Analyzer::terminate() {
	TString rootFile = "Histogrammer/" + TString(getDestination()) + ".root";
	TFile* f = new TFile(rootFile, "recreate");

	f->WriteTObject(allData);
	f->WriteTObject(cutted);
	f->WriteTObject(time);
	f->WriteTObject(silicium1);
	f->WriteTObject(silicium2);
	f->WriteTObject(time_s2_left);
	f->WriteTObject(time_s2_right);

	f->Close();
	//analyseSi1Si2Proton();
}

