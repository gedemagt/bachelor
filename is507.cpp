/*************************************************************
  Function to load the datafiles described in 'FileName.dat' *
  and to extract the data by looping. During extraction the  *
  data are calibrated and stored in several histograms which *
  are written to a root file. The class Calibration is used. *
  *
  Written by Morten V. Lund                                  *
  ************************************************************/

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

//My libraries:
#include "CalibrationClass.h"
#include "AnalysisClass.h"

using namespace std;

void is507(){

	//Initializing classes:
	Analysis Mg_Anal;
	Calibration Mg_Calib;

	//*********************************************
	//*          Reading in calibrations          *
	//*********************************************

	//Energy to be in keV for all calibrations!!
	Mg_Calib.LoadCalib();

	//*********************************************
	//*            Loading data files             *
	//*********************************************

	TChain chain("h7");
	Char_t dFile[100], hFile[100];
	Int_t nfiles;
	ifstream loading("FileName.dat");
	loading >> nfiles;
	for (Int_t ii = 0; ii < nfiles; ii++){ loading >> dFile, chain.Add(dFile); }
	loading >> hFile;
	loading.close();
	chain.ls();

	//*********************************************
	//*         Input, branch addresses           *
	//*********************************************

	//Setting dummy variables for input:
	Short_t E1, E2, T1, T2, Egas, Epad, Tgas, Tpad;
	Short_t Ef[16], Eb[16], Tf[16], Tb[16];
	Int_t Clockl, Nt1, Npad, Ne1, Ne2, Ngas, Nfe, Nbe, Nft, Nbt;
	UChar_t Nsfe[16], Nsbe[16];

	/*      POSSIBLE INPUT FROM DATA STRUCTURE
	//I (Int_t): clockl,Ievent,Ntrig,Nacc,Np,Nn,Ngas,Ne1,Ne2,Npad,Nt1,Nfe,Nbe,Nft,Nbt
	//S (Short_t): Egas,E1,E2,Epad,Tgas,T1,T2,Tpad,Ef,Eb,Tf,Tb
	//b (UChar_t): Nsfe,Nsbe,Nsft,Nsbt,
	*/

	chain.SetBranchStatus("*", 1);

	//Setting branch addresses:
	chain.SetBranchAddress("E1", &E1);
	chain.SetBranchAddress("E2", &E2);
	chain.SetBranchAddress("T1", &T1);
	chain.SetBranchAddress("T2", &T2);
	chain.SetBranchAddress("Egas", &Egas);
	chain.SetBranchAddress("Epad", &Epad);
	chain.SetBranchAddress("Ef", Ef);
	chain.SetBranchAddress("Eb", Eb);
	chain.SetBranchAddress("Tgas", &Tgas);
	chain.SetBranchAddress("Tpad", &Tpad);
	chain.SetBranchAddress("Tf", Tf);
	chain.SetBranchAddress("Tb", Tb);
	chain.SetBranchAddress("Clockl", &Clockl);
	chain.SetBranchAddress("Nt1", &Nt1);
	chain.SetBranchAddress("Npad", &Npad);
	chain.SetBranchAddress("Ne1", &Ne1);
	chain.SetBranchAddress("Ne2", &Ne2);
	chain.SetBranchAddress("Ngas", &Ngas);
	chain.SetBranchAddress("Nfe", &Nfe);
	chain.SetBranchAddress("Nbe", &Nbe);
	chain.SetBranchAddress("Nft", &Nft);
	chain.SetBranchAddress("Nbt", &Nbt);
	chain.SetBranchAddress("Nsfe", Nsfe);
	chain.SetBranchAddress("Nsbe", Nsbe);

	//*********************************************
	//*           Declaring histograms            *
	//*********************************************

	TFile file(hFile, "RECREATE");  //Output file.

	//Non-calibrated histograms::
	TH1F *hE1 = new TH1F("hE1", "Energy Si1 (counts/2 channels)", 2100, 0, 4200);
	TH1F *hE2 = new TH1F("hE2", "Energy Si2", 300, 0, 3000);
	TH1F *hEgas = new TH1F("hEgas", "Energy gas", 450, 0, 4500);
	TH1F *hEpad = new TH1F("hEpad", "Energy pad", 450, 0, 5000);
	TH1F *hT1 = new TH1F("hT1", "Time Si1", 900, 0, 4500);
	TH1F *hT2 = new TH1F("hT2", "Time Si2", 900, 0, 4500);
	TH1F *hTgas = new TH1F("hTgas", "Time gas", 900, 0, 4500);
	TH1F *hTpad = new TH1F("hTpad", "Time pad", 900, 0, 4500);
	TH1F *hClockl = new TH1F("hClockl", "Clockl i sek.", 5000, 0, 5000);
	TH1F *hClocks = new TH1F("hClocks", "Clocks i msek.", 15000, 0, 150000);

	//Calibrated histograms:
	TH1F *hE1_calib = new TH1F("hE1_calib", "Energy Si1", 4220, 0, 6000);
	TH1F *hEpad_calib = new TH1F("hEpad_calib", "Energy pad", 1098, 0, 11000);
	TH1F *hE1_21Mg = new TH1F("hE1_21Mg", "Energy Si1, 21Mg", 4220, 0, 6000);
	TH1F *hE1_21Mg_p = new TH1F("hE1_21Mg_p", "Energy Si1, 21Mg protons", 4220, 0, 6000);

	//DeltaE-E histograms:
	TH2F *hBanan = new TH2F("hBanan", "E1 vs. Egas (counts/5kev)", 900, 0, 4500, 900, 0, 4500);
	TH2F *hBananCalib = new TH2F("hBananCalib", "", 1180, 0, 5900, 840, 0, 4200);

	//DSSSD example histogram
	TH1F *hEb_calib = new TH1F("hEb_calib", "E_{back}", 1750, 0, 7000);
	TH1F *hEf_calib = new TH1F("hEf_calib", "E_{front}", 1750, 0, 7000);

	//*********************************************
	//*          Filling histograms               *
	//*********************************************

	//Variables:
	Int_t clockllast = 0, Nt1last = 0, clocks;

	//Loop over all data points:
	Long64_t nentries = chain.GetEntries();
	for (Long64_t ii = 0; ii < nentries; ii++){

		chain.GetEvent(ii);

		//----------------Histograms before calibration:------------------------

		hE1->Fill(E1), hT1->Fill(T1);
		hE2->Fill(E2), hT2->Fill(T2);
		hEgas->Fill(Egas), hTgas->Fill(Tgas);
		hEpad->Fill(Epad), hTpad->Fill(Tpad);
		hBanan->Fill(E1,Egas);

		//Clock short stuff:
		clocks = 0;
		if (Clockl > clockllast){
			clocks = Clockl - clockllast;
			if (Nt1 > Nt1last){
				clockllast = Clockl;
				Nt1last = Nt1;
			}
			hClockl->Fill(Clockl / 1000);
			hClocks->Fill(clocks);
		}

		//-----------------------------Calibration:-------------------------------------

		//Calibrating:
		Mg_Calib.Calibrate(Epad, E1, Ef, Nsfe, Nfe, Eb, Nsbe, Nbe);

		//------------------Histograms after calibration:-----------------------------

		hBananCalib->Fill(Mg_Calib.E1_calib, Egas);

		//Telescope calibrated:
		if (Epad > 0)hEpad_calib->Fill(Mg_Calib.Epad_calib);
		if (E1 > 0)hE1_calib->Fill(Mg_Calib.E1_calib);

		//21Mg histograms with cuts:
		if (Egas<1000) hE1_21Mg_p->Fill(Mg_Calib.E1_calib);
	
		if (Egas>1000) hE1_21Mg->Fill(Mg_Calib.E1_calib);

		//DSSSD calibrated histograms for front and back:
		for (Int_t i = 0; i < Nfe; i++){
			hEf_calib->Fill(Mg_Calib.Efront[i]);
		}
		for (Int_t i = 0; i < Nbe; i++){
			hEb_calib->Fill(Mg_Calib.Eback[i]);
		}
		cout.precision(3);
		if (ii % 10000 == 0){ cout << "\rProgress: " << ((double)ii) / ((double)nentries) * 100 << "%" << flush; }
	}

	hBananCalib->GetXaxis()->SetTitle("E_{Si1} (keV)");
	hBananCalib->GetYaxis()->SetTitle("Ch_{gas} (channel)");

	hE1_21Mg_p->GetXaxis()->SetTitle("E_{Si1} (keV)");
	hE1_21Mg_p->GetYaxis()->SetTitle("counts / 5keV");


	hE1_21Mg->GetXaxis()->SetTitle("E_{Si1} (keV)");
	hE1_21Mg->GetYaxis()->SetTitle("counts / 5keV");
	file.Write();
	file.Close();
}
