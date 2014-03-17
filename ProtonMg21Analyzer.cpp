#include "ProtonMg21Analyzer.h"
#include "DataLoader.h"
#include "Selector.h"

ProtonMg21Analyzer::ProtonMg21Analyzer() {

	// Load cut
	DataLoader* l = new DataLoader();
	bottomCut2 = l->loadCut("Histogrammer/cuts/bottomCut2.root", "CUTG");


	n = 13;
	cuts = new cut[n];
	peakHistograms = new TH1F[n];
	timeHistograms = new TH1F[n];
	cuts[0] = cut{ 530, 685, "1" };
	cuts[1] = cut{ 685, 787, "2" };
	cuts[2] = cut{ 787, 913, "3" };
	cuts[3] = cut{ 913, 1000, "ekstra1" };
	cuts[4] = cut{ 1000, 1100, "4" };
	cuts[5] = cut{ 1100, 1300, "5" };
	cuts[6] = cut{ 1300, 1411, "6" };
	cuts[7] = cut{ 1411, 1486, "7" };
	cuts[8] = cut{ 1486, 1621, "8" };
	cuts[9] = cut{ 2832, 2897, "18" };
	cuts[10] = cut{ 2897, 3050, "19" };
	cuts[11] = cut{ 3050, 3248, "20" };
	cuts[12] = cut{ 3248, 3400, "21" };

	Int_t i;
	for (i = 0; i < n; i++) {
		cut c = cuts[i];
		Int_t distance = c.right - c.left;
		peakHistograms[i] = TH1F(TString("peak").Append(c.name), TString("Peak ").Append(c.name), distance, c.left, c.right);
		timeHistograms[i] = TH1F(TString("peak").Append(c.name).Append("-time"), TString("Peak ").Append(c.name), 500, 0, 5000);
	}
}

bool ProtonMg21Analyzer::isInside(Double_t E1, cut cut) {
	return E1 < cut.right && E1 > cut.left;
}

void ProtonMg21Analyzer::analyze(Selector* s) {
	// Calculte clock stuff
	clocks = 0;
	if (s->Clockl > clockllast){
		clocks = s->Clockl - clockllast;
		if (s->Nt1 > Nt1last){
			clockllast = s->Clockl;
			Nt1last = s->Nt1;
		}
		
	}
	if (bottomCut2->IsInside(s->E1, s->Egas)) {
		for (int i = 0; i < n; i++) {
			if (isInside(s->E1, cuts[i]))  {
				peakHistograms[i].Fill(s->E1);
				if (s->Clockl > clockllast) timeHistograms[i].Fill(clocks);
			};
		};
	}
}

const char* ProtonMg21Analyzer::getDestination() {
	return "protonmg21";
}

void ProtonMg21Analyzer::terminate() {
}

