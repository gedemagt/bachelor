#include "DataLoader.h"
#include "Util.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TLegendEntry.h"
#include "TStyle.h"
#include "Kolmogorow.h"
#include <iostream>

using namespace std;

void CumuTime() {
	DataLoader* l = new DataLoader();
	TH1F* c1 = l->load1DHistogram("Histogrammer/time.root", "alpha_c1");
	TH1F* c2 = l->load1DHistogram("Histogrammer/time.root", "alpha_c2");
	TH1F* c3 = l->load1DHistogram("Histogrammer/time.root", "alpha_c3");
	TH1F* c4 = l->load1DHistogram("Histogrammer/time.root", "alpha_c4");
	
	freopen("Results/central_alpha_cuts.txt", "w", stdout);
	
	// Time analysis
	Kolmogorow* k = new Kolmogorow();

	Int_t max = 1200;
	TH1F* c1_cum = util::getCumulatedHistogram(c1, 0, max, true);
	c1_cum->SetName("c1");
	c1_cum->SetLineColor(1);
	TH1F* c1_cum_squared = util::getSquaredHistogram(c1, 0, max, true, true);
	c1_cum_squared->SetName("c1_squared");
	c1_cum_squared->SetLineColor(5);
	
	TH1F* c2_cum = util::getCumulatedHistogram(c2, 0, max, true);
	c2_cum->SetName("c2");
	c2_cum->SetLineColor(2);
	
	TH1F* c3_cum = util::getCumulatedHistogram(c3, 0, max, true);
	c3_cum->SetName("c3");
	c3_cum->SetLineColor(3);
	
	TH1F* c4_cum = util::getCumulatedHistogram(c4, 0, max, true);
	c4_cum->SetName("c4");
	c4_cum->SetLineColor(4);

	TFile f("Histogrammer/cumulated_alpha_cuts.root", "recreate");
	f.WriteTObject(c1_cum);
	f.WriteTObject(c1_cum_squared);
	f.WriteTObject(c2_cum);
	f.WriteTObject(c3_cum);
	f.WriteTObject(c4_cum);


	TCanvas* canvas = new TCanvas("canvas");
	gStyle->SetOptStat(0);
	canvas->SetObjectStat(0);
	c1_cum->SetTitle("Cumulated time distributions for central alpha cuts");
	c1_cum->SetXTitle("Time(ms)");
	c1_cum->SetYTitle("%");
	c1_cum->GetXaxis()->CenterTitle();
	c1_cum->GetYaxis()->CenterTitle();

	c1_cum->Draw();
	c2_cum->Draw("same");
	c3_cum->Draw("same");
	c4_cum->Draw("same");
	c1_cum_squared->Draw("same");

	TLegend* leg = new TLegend(0.4, 0.26, 0.85, 0.46);
	leg->SetHeader("");
	leg->SetNColumns(2);
	leg->AddEntry(c1_cum, "c1");
	leg->AddEntry(c2_cum, "c2");
	leg->AddEntry(c3_cum, "c3");
	leg->AddEntry(c4_cum, "c4");
	leg->AddEntry(c1_cum_squared, "c1 squared");
	leg->Draw();

	f.WriteTObject(canvas);
	canvas->Print("Results/cumulated_alpha_cuts.pdf");


	TH1F* c1_squared = util::getSquaredHistogram(c1, 0, 5000, false, false);
	TH1F* proton = l->load1DHistogram("Histogrammer/time.root","bottom3");
	TH1F* proton_squared = util::getSquaredHistogram(proton, 0, 5000, false, false);
	//f.WriteTObject(c1_squared);
	//c1->Draw();
	//c1_squared->SetLineColor(3);
	//c1_squared->Draw();
	//c1->Draw();
	cout << "-------------Rene c1-------------" << endl;
	k->setReferenceHistogram(c1);
	k->testVsHistogram(c2, 0, 1200);
	k->testVsHistogram(c3, 0, 1200);
	k->testVsHistogram(c4, 0, 1200);
	cout << "-------------Rene c1_squared-------------" << endl;
	k->setReferenceHistogram(c1_squared);
	k->testVsHistogram(c2, 0, 1200);
	k->testVsHistogram(c3, 0, 1200);
	k->testVsHistogram(c4, 0, 1200);
	cout << "-------------Rene proton-------------" << endl;
	k->setReferenceHistogram(proton);
	k->testVsHistogram(c1, 0, 1200);
	k->testVsHistogram(c2, 0, 1200);
	k->testVsHistogram(c3, 0, 1200);
	k->testVsHistogram(c4, 0, 1200);
	cout << "-------------Rene proton_squared-------------" << endl;
	k->setReferenceHistogram(proton_squared);
	k->testVsHistogram(c1, 0, 1200);
	k->testVsHistogram(c2, 0, 1200);
	k->testVsHistogram(c3, 0, 1200);
	k->testVsHistogram(c4, 0, 1200);
	//cout << "-------------Kumulerede c1-------------" << endl;
	//k->setReferenceHistogram(c1_cum);
	//k->testVsHistogram(c2_cum, 0, 1200);
	//k->testVsHistogram(c3_cum, 0, 1200);
	//k->testVsHistogram(c4_cum, 0, 1200);
	//cout << "-------------Kumulerede c1_cumuleret_squared-------------" << endl;
	//k->setReferenceHistogram(c1_cum_squared);
	//k->testVsHistogram(c2_cum, 0, 1200);
	//k->testVsHistogram(c3_cum, 0, 1200);
	//k->testVsHistogram(c4_cum, 0, 1200);

	fclose(stdout);
}