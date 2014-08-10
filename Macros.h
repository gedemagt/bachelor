#include "DataLoader.h"
#include "Kolmogorow.h"
#include "TH1F.h"
#include "TMath.h"
#include <iostream>
#include "SRIMLoader.h"
#include "TLegend.h"
#include "TF1.h"
#include "TVectorD.h"
#include "TCanvas.h"

#ifndef MACROS_H
#define MACROS_H

using namespace std;

void analyseProtonAround200() {
	DataLoader* l = new DataLoader();
	Kolmogorow *k = new Kolmogorow();
	TH1F* proton = l->load1DHistogram("Histogrammer/New/time.root", "bottom3");
	k->setReferenceHistogram(proton);
	k->report(true);

	const char** levels = new const char*[]{"low", "medium", "deep"};
	//char* str = new char[80];
	TString s("peak200-2-time");
	for (int i = 0; i < 3; i++) {
		cout << TString("----------- ").Append(levels[i]).Append(" ----------------").Data() << endl;
		const char*  first = TString("peak200-2-time").Append(levels[i]).Data();
		const char*  second = TString("peak200-1-time").Append(levels[i]).Data();
		const char*  third = TString("peak200-time").Append(levels[i]).Data();
		const char*  last = TString("peak200+1-time").Append(levels[i]).Data();
		const char*  lastlast = TString("peak200+2-time").Append(levels[i]).Data();

		TH1F* leftleft = l->load1DHistogram("Histogrammer/New/proton21_silicium.root", TString("peak200-2-").Append(levels[i]).Append("-time").Data());
		TH1F* left = l->load1DHistogram("Histogrammer/New/proton21_silicium.root", TString("peak200-1-").Append(levels[i]).Append("-time").Data());
		TH1F* mid = l->load1DHistogram("Histogrammer/New/proton21_silicium.root", TString("peak200-").Append(levels[i]).Append("-time").Data());
		TH1F* right = l->load1DHistogram("Histogrammer/New/proton21_silicium.root", TString("peak200+1-").Append(levels[i]).Append("-time").Data());
		TH1F* rightright = l->load1DHistogram("Histogrammer/New/proton21_silicium.root", TString("peak200+2-").Append(levels[i]).Append("-time").Data());


		k->testVsHistogram(leftleft, 0, 1200);
		k->testVsHistogram(left, 0, 1200);
		k->testVsHistogram(mid, 0, 1200);
		k->testVsHistogram(right, 0, 1200); 
		k->testVsHistogram(rightright, 0, 1200);
	}
	TH1F* peak_200 = l->load1DHistogram("Histogrammer/New/proton21_silicium.root", "proton_200");
	k->testVsHistogram(peak_200, 0, 1200);
}

#include<iostream>
#include <fstream>
#include <iomanip>

void calculateBetaRatio(TH1F* histo, Double_t* ratio, Double_t* std) {
	Double_t N_1 = histo->Integral(100, 300);
	Double_t N_2 = histo->Integral(1000, 1200);
	Double_t N_1_std = TMath::Sqrt(N_1);
	Double_t N_2_std = TMath::Sqrt(N_2);

	(*ratio) = N_2 / N_1;
	(*std) = (N_2/N_1)*TMath::Sqrt((1/N_1) + 1/(N_2));
}

// Files
ofstream kol_result;
ofstream counts;
ofstream beta_ratio;
ofstream beta_ratio_std;

void analyseLeftSquare() {
	DataLoader* l = new DataLoader();
	Kolmogorow *k = new Kolmogorow();
	Kolmogorow *k2 = new Kolmogorow();
	TH1F* proton = l->load1DHistogram("Histogrammer/New/time.root", "bottom3");
	TH1F* laseroff = l->load1DHistogram("Histogrammer/New/laseroff.root", "allTime");
	

	k->setReferenceHistogram(proton);
	k2->setReferenceHistogram(laseroff);
	
	
	kol_result.open("Results/grid_kol.txt");
	counts.open("Results/grid_counts.txt");
	beta_ratio.open("Results/grid_beta_ratio.txt");
	beta_ratio_std.open("Results/grid_beta_ratio_std.txt");

	Int_t x_max = 700;
	Int_t y_max = 1500;
	Int_t x_min = 20;
	Int_t y_min = 0;
	Int_t x = 50;
	Int_t y = 80;
	
	Int_t x_range_max = x_max - ((x_max - x_min) % x) + x;
	Int_t y_range_max = y_max - ((y_max - y_min) % y) + y;
	Int_t x_bins = (x_range_max - x_min) / x;
	Int_t y_bins = (y_range_max - y_min) / y;	

	//cout << x_min << ":" << x_range_max << " - " << x_bins << endl;
	//cout << y_min << ":" << y_range_max << " - " << y_bins << endl;

	TH2F* kol_grid = new TH2F("kolgrid", "Kolmogorow test", x_bins, x_min, x_range_max, y_bins, y_min, y_range_max);
	TH2F* kol_grid_laseroff = new TH2F("kolgrid_laseroff", "Kolmogorow test", x_bins, x_min, x_range_max, y_bins, y_min, y_range_max);
	TH2F* kol_grid_sig = new TH2F("kolgrid_sig", "Kolmogorow test:Sig", x_bins, x_min, x_range_max, y_bins, y_min, y_range_max);
	TH2F* ratio_grid = new TH2F("ratiogrid", "Ratio", x_bins, x_min, x_range_max, y_bins, y_min, y_range_max);

	const char separator = ' ';
	const int numWidth = 10;


	TH1F* histo;
	char name[2];
	Double_t j = 0;
	Double_t i = 0;

	Double_t ratio = 0;
	Double_t std = 0;
	
	// Write header line
	kol_result << left << setw(numWidth) << setfill(separator) << "  ";
	counts << left << setw(numWidth) << setfill(separator) << "  ";
	beta_ratio << left << setw(numWidth) << setfill(separator) << "  ";
	beta_ratio_std << left << setw(numWidth) << setfill(separator) << "  ";

	for (Double_t k = 0; k < y_max; k += y) {
		sprintf(name, "%lg", k);
		kol_result << left << setw(numWidth) << setfill(separator) << name;
		counts << left << setw(numWidth) << setfill(separator) << name;
		beta_ratio << left << setw(numWidth) << setfill(separator) << name;
		beta_ratio_std << left << setw(numWidth) << setfill(separator) << name;
	}
	kol_result << endl;
	counts << endl;
	beta_ratio << endl;
	beta_ratio_std << endl;

	// Iterate through everything
	for (i = x_min; i < x_max; i += x) {
		sprintf(name, "%lg", i);
		kol_result << left << setw(numWidth) << setfill(separator) << name;
		counts << left << setw(numWidth) << setfill(separator) << name;
		beta_ratio << left << setw(numWidth) << setfill(separator) << name;
		beta_ratio_std << left << setw(numWidth) << setfill(separator) << name;
		
		for (j = y_min; j < y_max; j += y) {

			sprintf(name, "%lg%lg", i, j);
			histo = l->load1DHistogram("Histogrammer/New/timeSquare.root", name);
			k->testVsHistogram(histo, 0, 1200);
			k2->testVsHistogram(histo, 0, 1200);
			
			
			kol_result << left << setw(numWidth) << setfill(separator) << k->A_h;
			counts << left << setw(numWidth) << setfill(separator) << histo->Integral(0, 1200);

			calculateBetaRatio(histo, &ratio, &std);

			beta_ratio << left << setw(numWidth) << setfill(separator) << ratio;
			beta_ratio_std << left << setw(numWidth) << setfill(separator) << std;
			

			if (histo->Integral(0, 1200) > 20) {
				kol_grid_laseroff->Fill(i, j, k2->A_h);
				kol_grid->Fill(i, j, k->A_h);
				if (k->A_h <= 2.4949) kol_grid_sig->Fill(i, j, 1);
				else if (k->A_h <= 3.0912) kol_grid_sig->Fill(i, j, 0.5);
				else kol_grid_sig->Fill(i, j, 0.1);
			}
			if (histo->Integral(100, 300) > 10 && histo->Integral(1000, 1200) > 10) {
				ratio_grid->Fill(i, j, ratio);
			}
			delete histo;
		}
		kol_result << endl;
		counts << endl;
		beta_ratio << endl;
		beta_ratio_std << endl;
	}

	kol_result.close();
	counts.close();
	beta_ratio.close();
	beta_ratio_std.close();

	TString rootFile = "Results/" + TString("kol_grid_2") + ".root";
	TFile* f = new TFile(rootFile, "recreate");
	f->WriteTObject(kol_grid);
	f->WriteTObject(kol_grid_sig);
	f->WriteTObject(ratio_grid);
	f->WriteTObject(kol_grid_laseroff);
	f->Close();
}

void analyseSi1Si2Proton() {
	freopen("Results/si1si2.txt", "w", stdout);
	DataLoader* l = new DataLoader();
	Kolmogorow *k = new Kolmogorow();
	TH1F* proton = l->load1DHistogram("Histogrammer/New/time.root", "bottom3");
	TH1F* newProton = l->load1DHistogram("Histogrammer/New/si1si2.root", "time");
	TH1F* newProtonLeft = l->load1DHistogram("Histogrammer/New/si1si2.root", "si_2_left");
	TH1F* newProtonRight = l->load1DHistogram("Histogrammer/New/si1si2.root", "si_2_right");
	k->setReferenceHistogram(proton);
	k->report(true);
	k->testVsHistogram(newProton, 0, 1200);
	k->testVsHistogram(newProtonLeft, 0, 1200);
	k->testVsHistogram(newProtonRight, 0, 1200);
	fclose(stdout);
}

void analyzeDSSD() {
	freopen("Results/dssd.txt", "w", stdout);
	DataLoader* l = new DataLoader();
	Kolmogorow *k = new Kolmogorow();
	TH1F* proton = l->load1DHistogram("Histogrammer/New/time.root", "bottom3");
	TH1F* time_24 = l->load1DHistogram("Histogrammer/New/dssd.root", "time_24");
	TH1F* time_33 = l->load1DHistogram("Histogrammer/New/dssd.root", "time_33");
	TH1F* time_38 = l->load1DHistogram("Histogrammer/New/dssd.root", "time_38");
	TH1F* time_46 = l->load1DHistogram("Histogrammer/New/dssd.root", "time_46");
	TH1F* time_62 = l->load1DHistogram("Histogrammer/New/dssd.root", "time_62");

	k->setReferenceHistogram(proton);
	k->report(true);
	k->testVsHistogram(time_24, 0, 1200);
	k->testVsHistogram(time_33, 0, 1200);
	k->testVsHistogram(time_38, 0, 1200);
	k->testVsHistogram(time_46, 0, 1200);
	k->testVsHistogram(time_62, 0, 1200);
	fclose(stdout);
}

void compareBetas() {
	freopen("Results/beta.txt", "w", stdout);
	DataLoader* l = new DataLoader();
	Kolmogorow *k = new Kolmogorow();
	k->report(true);
	TH1F* proton = l->load1DHistogram("Histogrammer/New/time.root", "bottom3");
	TH1F* all = l->load1DHistogram("Histogrammer/New/time.root", "extra_inner");
	TH1F* left = l->load1DHistogram("Histogrammer/New/beta.root", "left");
	TH1F* middle = l->load1DHistogram("Histogrammer/New/beta.root", "middle");
	TH1F* right = l->load1DHistogram("Histogrammer/New/beta.root", "right");

	k->setReferenceHistogram(left);
	k->testVsHistogram(middle, 0, 1200);
	k->testVsHistogram(right, 0, 1200);

	k->setReferenceHistogram(middle);
	k->testVsHistogram(right, 0, 1200);

	k->setReferenceHistogram(proton);
	k->testVsHistogram(left, 0, 1200);
	k->testVsHistogram(middle, 0, 1200);
	k->testVsHistogram(right, 0, 1200);
	fclose(stdout);
}

void createSrimGraph() {
	SRIMLoader *l = new SRIMLoader();
	TGraph *alfa = l->LoadSRIM("C:/Users/Jesper/Desktop/SRIM/alfaCF4_mig.txt");
	TGraph *proton = l->LoadSRIM("C:/Users/Jesper/Desktop/SRIM/pCF4_mig.txt");
	alfa->Draw();
	proton->Draw("same");
	alfa->GetXaxis()->SetTitle("E (keV)");
	alfa->GetXaxis()->CenterTitle();
	alfa->GetXaxis()->SetRangeUser(0, 5000);
	alfa->SetLineStyle(9);
	proton->SetLineColor(2);

	TLegend *leg = new TLegend(0.70, 0.76, 0.85, 0.85);
	leg->SetFillColor(0);
	leg->AddEntry(alfa, "$\\alpha$", "L");
	leg->AddEntry(proton, "protons", "L");
	leg->Draw();

	alfa->GetYaxis()->SetTitle("dE/dx $\\left(\\frac{keV}{mg/cm^2} \\right)$");
	alfa->GetYaxis()->CenterTitle();

	alfa->SetTitle("");
}

void testMid() {
	Kolmogorow *k = new Kolmogorow();
	DataLoader* l = new DataLoader();
	k->report(true);
	TH1F* proton = l->load1DHistogram("Histogrammer/New/time.root", "bottom3");
	TH1F* mid = l->load1DHistogram("Histogrammer/New/time.root", "mid");
	k->setReferenceHistogram(proton);
	k->testVsHistogram(mid);
}

void createSrimOnResultGraph() {
	SRIMLoader *l = new SRIMLoader();
	TFile* file1 = new TFile("Histogrammer/New/mg21_banana.root");
	TH2F *data = (TH2F*) file1->Get("allData");
	TGraph *alfa = l->LoadSRIM("C:/Users/Jesper/Desktop/SRIM/alfaCF4_mig.txt");
	TGraph *proton = l->LoadSRIM("C:/Users/Jesper/Desktop/SRIM/pCF4_mig.txt");
	
	// Scale alfa
	TVectorD x_a = TVectorD(alfa->GetN(), alfa->GetX());
	TVectorD y_a = TVectorD(alfa->GetN(), alfa->GetY());
	y_a *= 1888 / alfa->Eval(1157 / (1356.0 / 2036.0));
	x_a *= 1356.0 / 2036.0;

	// Scale protons
	TVectorD x_p = TVectorD(proton->GetN(), proton->GetX());
	TVectorD y_p = TVectorD(proton->GetN(), proton->GetY());
	y_p *= 181 / proton->Eval(1356 / (1356.0 / 2036.0));
	x_p *= 1356.0 / 2036.0;
	proton = new TGraph(x_p, y_p);
	alfa = new TGraph(x_a, y_a);
	
	TCanvas *canvas = new TCanvas();
	canvas->SetLogz();

	data->Draw("colz");
	alfa->Draw("same");
	proton->Draw("same");

	data->GetXaxis()->SetTitle("ch_{si1} (channel)");
	data->GetXaxis()->CenterTitle();
	data->GetYaxis()->SetTitle("ch_{gas} (channel)");
	data->GetYaxis()->CenterTitle();
	data->SetTitle("");

	data->GetXaxis()->SetRangeUser(0, 4100);
	data->GetYaxis()->SetRangeUser(0, 4100);
	proton->SetLineColor(2);
	alfa->SetLineStyle(9);

	TLegend *leg = new TLegend(0.70, 0.76, 0.85, 0.85);
	leg->SetHeader("Stopping power curves");
	leg->SetFillColor(0);
	leg->AddEntry(alfa, "$\\alpha$", "L");
	leg->AddEntry(proton, "protons", "L");
	leg->Draw("same");
}

#include "TStyle.h"

void CreateLandauGraph() {
	DataLoader* l = new DataLoader();
	TH1F* tail_1 = l->load1DHistogram("Histogrammer/New/mg21_gas.root", "tail_1");
	TH1F* tail_6 = l->load1DHistogram("Histogrammer/New/mg21_gas.root", "tail_6");
	TH1F* tail_21 = l->load1DHistogram("Histogrammer/New/mg21_gas.root", "tail_21");
	tail_1->SetLineColor(1);
	tail_1->SetName("1");
	tail_6->SetLineColor(2);
	tail_6->SetName("6");
	tail_21->SetLineColor(3);
	tail_21->SetName("21");

	TCanvas* canvas = new TCanvas("canvas");
	gStyle->SetOptStat(0);
	canvas->SetObjectStat(0);
	tail_6->SetXTitle("ch_{gas} (channel)");
	tail_6->SetYTitle("Counts");
	tail_6->GetXaxis()->CenterTitle();
	tail_6->GetYaxis()->CenterTitle();
	canvas->SetLogy();
	tail_6->Draw("same");
	tail_1->Draw("same");
	tail_21->Draw("same");

	TLegend* leg = new TLegend(0.65, 0.65, 0.85, 0.85);
	leg->SetNColumns(1);
	leg->SetFillColor(0);
	leg->AddEntry(tail_1, "Peak 1", "l");
	leg->AddEntry(tail_6, "Peak 6", "l");
	leg->AddEntry(tail_21, "Peak 21", "l");
	leg->Draw();
}


#endif