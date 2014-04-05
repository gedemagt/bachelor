#include "DataLoader.h"
#include "Util.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TLegendEntry.h"
#include "TStyle.h"
#include "Kolmogorow.h"

void CumuTime() {
	DataLoader* l = new DataLoader();
	TH1F* c1 = l->load1DHistogram("Histogrammer/time.root", "alpha_c1");
	TH1F* c2 = l->load1DHistogram("Histogrammer/time.root", "alpha_c2");
	TH1F* c3 = l->load1DHistogram("Histogrammer/time.root", "alpha_c3");
	TH1F* c4 = l->load1DHistogram("Histogrammer/time.root", "alpha_c4");
	
	freopen("Results/central_alpha_cuts.txt", "w", stdout);
	
	// Time analysis
	Kolmogorow* k = new Kolmogorow();
	k->setReferenceHistogram(c1);
	k->testVsHistogram(c2, 0, 1200);
	k->testVsHistogram(c3, 0, 1200);
	k->testVsHistogram(c4, 0, 1200);

	Int_t max = 1200;
	TH1F* c1_cum = util::getCumulatedHistogram(c1, 0, max, true);
	c1_cum->SetName("c1");
	c1_cum->SetLineColor(1);
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

	TLegend* leg = new TLegend(0.4, 0.26, 0.85, 0.46);
	leg->SetHeader("");
	leg->SetNColumns(2);
	leg->AddEntry(c1_cum, "c1");
	leg->AddEntry(c2_cum, "c2");
	leg->AddEntry(c3_cum, "c3");
	leg->AddEntry(c4_cum, "c4");
	leg->Draw();

	f.WriteTObject(canvas);
	canvas->Print("Results/cumulated_alpha_cuts.pdf");
	fclose(stdout);
}