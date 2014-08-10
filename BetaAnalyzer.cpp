#include "BetaAnalyzer.h"
#include "TFile.h"
#include "DataLoader.h"

BetaAnalyzer::BetaAnalyzer(const char* dest) : Analyzer(dest) {

	DataLoader* l = new DataLoader();
	innerCut = l->loadCut("Histogrammer/cuts/extra_cuts.root","bot_inner");
	calc = new TimeCalc();

	left = new TH1F("left", "Beta - left", 5000, 0, 5000);
	middle = new TH1F("middle", "Beta - middle", 5000, 0, 5000);
	right = new TH1F("right", "Beta - right", 5000, 0, 5000);

}

void BetaAnalyzer::analyze(Selector* s) {
	calc->calculateNewEvent(s);

	if (innerCut->IsInside(s->E1, s->Egas)) {
		if (s->E1 < 175) {
			calc->fillHistogram(left);
		}
		if (s->E1 > 175 && s->E1 < 250) {
			calc->fillHistogram(middle);
		}
		if (s->E1 > 250) {
			calc->fillHistogram(right);
		}
	}


}

void BetaAnalyzer::terminate() {
	TString rootFile = "Histogrammer/" + TString(getDestination()) + ".root";
	TFile* f = new TFile(rootFile, "recreate");
	f->WriteTObject(left);
	f->WriteTObject(middle);
	f->WriteTObject(right);
	f->Close();
}