
//Public libraries:
#include <fstream>
#include <iostream>
#include <cstring>
#include "TFile.h"
#include "TChain.h"
#include "TROOT.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "TStyle.h"
#include "TRoot.h"
#include "TCutG.h"
#include "DataLoader.h"
#include <vector>

using namespace std;

void timeHistograms() {
	// Load data
	DataLoader* l = new DataLoader();
	
	// Load the cuts
	TCutG* midCut = l->loadCut("Histogrammer/midCut.root", "CUTG");
	TCutG* bottomCut = l->loadCut("Histogrammer/bottomCut.root", "CUTG");
	TCutG* leftCut = l->loadCut("Histogrammer/leftCut.root", "CUTG");
	TCutG* topRightCut = l->loadCut("Histogrammer/topRightCut.root", "CUTG");
	
	// Load the chain add
	TChain* chain = l->loadData("FileName1.dat", "h7");
	//chain->MakeSelector();
	// Load the output file
	TFile file("Histogrammer/histograms.root", "RECREATE");
	
	// Variable to hold clocks and counts
	Int_t Clockl, Nt1;
	Short_t E1, Egas;
	chain->SetBranchStatus("*", 1);

	chain->SetBranchAddress("Clockl", &Clockl);
	chain->SetBranchAddress("Nt1", &Nt1);
	chain->SetBranchAddress("E1", &E1);
	chain->SetBranchAddress("Egas", &Egas);

	// Al data i bananplot
	TH2F *allBanan = new TH2F("allData", "Al data: E1 vs. Egas (counts/5kev)", 900, 0, 4500, 900, 0, 4500);
	TH2F *midBanan = new TH2F("midBanan", "Mid data: E1 vs. Egas (counts/5kev)", 900, 0, 4500, 900, 0, 4500);
	TH2F *bottomBanan = new TH2F("bottomBanan", "Bund data: E1 vs. Egas (counts/5kev)", 900, 0, 4500, 900, 0, 4500);
	TH2F *leftBanan = new TH2F("leftBanan", "Left data: E1 vs. Egas (counts/5kev)", 900, 0, 4500, 900, 0, 4500);
	TH2F *topRightBanan = new TH2F("topRightBanan", "Right data: E1 vs. Egas (counts/5kev)", 900, 0, 4500, 900, 0, 4500);

	// AL tids information
	TH1F *allClockl = new TH1F("allClockl", "Al data: Clockl i sek.", 5000, 0, 3200000);
	TH1F *allClocks = new TH1F("allClocks", "Al data: Clockl i sek.", 500, 0, 5000);

	// Mid stuff
	TH1F *midClockl = new TH1F("midClockl", "Midt: Clockl i sek.", 5000, 0, 3200000);
	TH1F *midClocks = new TH1F("midClock", "Midt: Clockl i sek.", 500, 0, 5000);

	// Bottom stuff
	TH1F *bottomClockl = new TH1F("bottomClockl", "Bund: Clockl i sek.", 5000, 0, 3200000);
	TH1F *bottomClocks = new TH1F("bottomClocks", "Bund: Clockl i sek.", 500, 0, 5000);

	// Left stuff
	TH1F *leftClockl = new TH1F("leftClockl", "Left: Clockl i sek.", 5000, 0, 3200000);
	TH1F *leftClocks = new TH1F("leftClocks", "Left: Clockl i sek.", 500, 0, 5000);

	// Top right stuff
	TH1F *topRightClockl = new TH1F("topRightClockl", "Top/Højre: Clockl i sek.", 5000, 0, 3200000);
	TH1F *topRightClocks = new TH1F("topRightClocks", "Top/Højre: Clockl i sek.", 500, 0, 5000);

	// The rest
	//TH2F *theRestBanan = new TH2F("theRestBanan", "Resten data: E1 vs. Egas (counts/5kev)", 900, 0, 4500, 900, 0, 4500);
	//TH1F *theRestClock = new TH1F("theRestClock", "Resten: Clockl i sek.", 5000, 0, 3200000);

	cout.precision(3);

	Int_t clockllast = 0, Nt1last = 0, clocks;

	//Loop over all data points:
	Long64_t nentries = chain->GetEntries();
	cout << nentries << endl;
	for (Long64_t ii = 0; ii < nentries; ii++){


		chain->GetEvent(ii);
		//Clock short stuff:

		// Calculte clock stuff
		clocks = 0;
		if (Clockl > clockllast){
			clocks = Clockl - clockllast;
			if (Nt1 > Nt1last){
				clockllast = Clockl;
				Nt1last = Nt1;
			}
			if (midCut->IsInside(E1, Egas)){
				midClockl->Fill(Clockl);
				midClocks->Fill(clocks);
			}
			else if (bottomCut->IsInside(E1, Egas)){
				bottomClockl->Fill(Clockl);
				bottomClocks->Fill(clocks);
			}
			else if (leftCut->IsInside(E1, Egas)){
				leftClockl->Fill(Clockl);
				leftClocks->Fill(clocks);
			}
			else if (topRightCut->IsInside(E1, Egas)){
				topRightClockl->Fill(Clockl);
				topRightClocks->Fill(clocks);
			}
			allClockl->Fill(Clockl);
			allClocks->Fill(clocks);
		}


		allBanan->Fill(E1, Egas);
		if (midCut->IsInside(E1, Egas)){
			midBanan->Fill(E1, Egas);
		}
		else if (bottomCut->IsInside(E1, Egas)){
			bottomBanan->Fill(E1, Egas);
		}
		else if (leftCut->IsInside(E1, Egas)){
			leftBanan->Fill(E1, Egas);
		}
		else if (topRightCut->IsInside(E1, Egas)){
			topRightBanan->Fill(E1, Egas);
		}


		if (ii % 10000 == 0){ cout << "\rProgress: " << ((double)ii) / ((double)nentries) * 100 << "%    " << flush; }
	}

	file.Write();
	file.Close();
}