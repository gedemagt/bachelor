#include "ProtonMg21Analyzer.h"
#include "DataLoader.h"
#include "Selector.h"

ProtonMg21Analyzer::ProtonMg21Analyzer(const char* dest) : Analyzer(dest) {
	// Load cut
	DataLoader* l = new DataLoader();
	bottomCut2 = l->loadCut("Histogrammer/cuts/bottomCut2.root", "CUTG");
	proton200_deep = l->loadCut("Histogrammer/cuts/proton200.root", "deep");
	proton200_medium = l->loadCut("Histogrammer/cuts/proton200.root", "low");
	proton200_low = l->loadCut("Histogrammer/cuts/proton200.root", "medium");

	peak_200 = new TH1F("proton_200", "Proton ved 200", 5000, 0, 5000);

	calc = new TimeCalc();

	n = 28;
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

	// These are extras for a possible small one
	cuts[13] = cut{ 100, 150, "200-2-deep" };
	cuts[14] = cut{ 150, 200, "200-1-deep"};
	cuts[15] = cut{ 200, 240, "200-deep"};
	cuts[16] = cut{ 240, 300, "200+1-deep" };
	cuts[17] = cut{ 300, 350, "200+2-deep" };

	cuts[18] = cut{ 100, 150, "200-2-medium" };
	cuts[19] = cut{ 150, 200, "200-1-medium" };
	cuts[20] = cut{ 200, 240, "200-medium" };
	cuts[21] = cut{ 240, 300, "200+1-medium" };
	cuts[22] = cut{ 300, 350, "200+2-medium" };

	cuts[23] = cut{ 100, 150, "200-2-low" };
	cuts[24] = cut{ 150, 200, "200-1-low" };
	cuts[25] = cut{ 200, 240, "200-low" };
	cuts[26] = cut{ 240, 300, "200+1-low" };
	cuts[27] = cut{ 300, 350, "200+2-low" };

	Int_t i;
	for (i = 0; i < n; i++) {
		cut c = cuts[i];
		Int_t distance = c.right - c.left;
		peakHistograms[i] = TH1F(TString("peak").Append(c.name), TString("Peak ").Append(c.name), distance, c.left, c.right);
		timeHistograms[i] = TH1F(TString("peak").Append(c.name).Append("-time"), TString("Peak ").Append(c.name), 5000, 0, 5000);
	}
}

bool ProtonMg21Analyzer::isInside(Double_t E1, cut cut) {
	return E1 < cut.right && E1 > cut.left;
}

void ProtonMg21Analyzer::analyze(Selector* s) {
	calc->calculateNewEvent(s);

	if (s->E1 < 230 && s->E1 > 200 && s->Egas < 950 && s->Egas > 550) {
		calc->fillHistogram(peak_200);
	}

	if (proton200_low->IsInside(s->E1, s->Egas)) {
		for (int i = 23; i < 28; i++) {
			if (isInside(s->E1, cuts[i]))  {
				peakHistograms[i].Fill(s->E1);
				calc->fillHistogram(&timeHistograms[i]);
			};
		};
	}

	if (proton200_medium->IsInside(s->E1, s->Egas)) {
		for (int i = 18; i < 23; i++) {
			if (isInside(s->E1, cuts[i]))  {
				peakHistograms[i].Fill(s->E1);
				calc->fillHistogram(&timeHistograms[i]);
			};
		};
	}


	if (proton200_deep->IsInside(s->E1, s->Egas)) {
		for (int i = 13; i < 18; i++) {
			if (isInside(s->E1, cuts[i]))  {
				peakHistograms[i].Fill(s->E1);
				calc->fillHistogram(&timeHistograms[i]);
			};
		};
	}
	if (bottomCut2->IsInside(s->E1, s->Egas)) {
		for (int i = 0; i < 13; i++) {
			if (i == 0 && s->Egas < 200) continue;
			if (i == 1 && s->Egas < 200) continue;
			if (isInside(s->E1, cuts[i]))  {
				peakHistograms[i].Fill(s->E1);
				calc->fillHistogram(&timeHistograms[i]);
			};
		};
	}
}

void ProtonMg21Analyzer::terminate() {
	TString rootFile = "Histogrammer/" + TString(getDestination()) + ".root";
	TFile* f = new TFile(rootFile, "recreate");
	for (Int_t i = 0; i < n; i++) {
		f->WriteTObject(&peakHistograms[i]);// = TH1F(TString("peak").Append(c.name), TString("Peak ").Append(c.name), distance, c.left, c.right);
		f->WriteTObject(&timeHistograms[i]);// = TH1F(TString("peak").Append(c.name).Append("-time"), TString("Peak ").Append(c.name), 5000, 0, 5000);
	}
	f->WriteTObject(peak_200);
	f->Close();
}

