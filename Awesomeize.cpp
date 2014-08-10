#include "TCanvas.h"
#include "TList.h"
#include "TFile.h"
#include <iostream>
#include "TStyle.h"
#include "TH1.h"
#include "TROOT.h"

using namespace std;
void doPretty(int w, int h, const char* filename, const char* histoname, bool colz, bool logz);

void Awesomeize() {
	doPretty(1600, 1600, "Results/kol_grid_2.root", "kolgrid", true, true);
	doPretty(1600, 1600, "Results/kol_grid_2.root", "kolgrid_sig", true, false);
	doPretty(1600, 1600, "Results/kol_grid_2.root", "kolgrid_laseroff", true, true);
	doPretty(1600, 1600, "Results/kol_grid_2.root", "ratiogrid", true, false);
	doPretty(1600, 1600, "Results/kol_grid_2.root", "ratiogrid", true, false);
	doPretty(1600, 1000, "Histogrammer/rapport/alfa.root", "midBanan", false, false);
}

void doPretty(int w, int h, const char* filename, const char* histoname, bool colz, bool logz) {
	
	TFile *f = new TFile(filename);
	cout << gROOT->FindObject(histoname) << endl;
	TH1* histo = (TH1*) gROOT->FindObject(histoname);

	TCanvas cv("Up", "Up", w, h);
	
	if (logz) cv.SetLogz();

	gStyle->SetOptStat(0);
	cv.SetRightMargin(0.13f);
	cv.SetLeftMargin(0.14f);

	histo->SetTitle("");
	histo->GetXaxis()->CenterTitle();
	histo->GetXaxis()->SetTitle("ch_{si1} (Channel)");

	histo->GetYaxis()->CenterTitle();
	histo->GetYaxis()->SetTitleOffset(1.6);
	histo->GetYaxis()->SetTitle("ch_{gas} (Channel)");

	histo->GetYaxis()->SetTitleSize(0.045);
	histo->GetXaxis()->SetTitleSize(0.045);
	histo->GetZaxis()->SetTitleSize(0.045);

	histo->GetYaxis()->SetLabelSize(0.04);
	histo->GetXaxis()->SetLabelSize(0.04);
	histo->GetZaxis()->SetLabelSize(0.04);

	if (colz)histo->Draw("colz");
	else histo->Draw();

	cout << cv.GetRightMargin() << endl;
	cout << cv.GetLeftMargin() << endl;
	cv.SaveAs(Form("%s/%s.pdf", "Awesomeized",histoname));
}