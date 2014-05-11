#include "DataLoader.h"
#include "Kolmogorow.h"
#include "TH1F.h"

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

}

#include<iostream>
#include <fstream>
#include <iomanip>

void analyseLeftSquare() {
	DataLoader* l = new DataLoader();
	Kolmogorow *k = new Kolmogorow();
	TH1F* proton = l->load1DHistogram("Histogrammer/New/time.root", "bottom3");
	k->setReferenceHistogram(proton);
	freopen("Results/grid.txt", "w", stdout);
	//k->report(true);

	Double_t x_max = 500;
	Double_t y_max = 1500;
	Double_t x_min = 10;
	Double_t y_min = 0;

	const char separator = ' ';
	const int numWidth = 10;


	Double_t x = 20;
	Double_t y = 50;
	TH1F* histo;
	char name[2];
	Double_t j = 0;
	Double_t i = 0;

	// Write header line
	cout << left << setw(numWidth) << setfill(separator) << "  ";
	for (Double_t k = 0; k < y_max; k += y) {
		sprintf(name, "%lg", k);
		cout << left << setw(numWidth) << setfill(separator) << name;
	}
	cout << endl;

	for (i = x_min; i < x_max; i += x) {
		sprintf(name, "%lg", i);
		cout << left << setw(numWidth) << setfill(separator) << name;

		for (j = y_min; j < y_max; j += y) {

		sprintf(name, "%lg%lg", i, j);
		histo = l->load1DHistogram("Histogrammer/New/timeSquare.root", name);
		k->testVsHistogram(histo, 0, 1200);
		cout << left << setw(numWidth) << setfill(separator) << k->A_h;

		}
		cout << endl;
	}
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

#endif