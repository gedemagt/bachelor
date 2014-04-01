#include "DataLoader.h"
#include "Kolmogorow.h"
#include "TH1F.h"
#include <iostream>
#include <cstdio>
#include <time.h>
using namespace std;
void TimeAnalysis() {

	time_t t = time(0);   // get time now
	struct tm * now = localtime(&t);

	char buffer[80];
	strftime(buffer, 80, "Logs/%Y-%m-%d--%H-%M-%S-timeanalysis.txt", now);

	freopen(buffer, "w", stdout);

	DataLoader *l = new DataLoader();
	Kolmogorow* k = new Kolmogorow();
	TH1F *referenceproton = l->load1DHistogram("Histogrammer/time.root","bottom3");
	TH1F *protonpeak = l->load1DHistogram("Histogrammer/protonmg21.root", "peak6-time");
	TH1F *protonpeak5 = l->load1DHistogram("Histogrammer/protonmg21.root", "peak5-time");
	TH1F *protons = l->load1DHistogram("Histogrammer/time.root", "bottomClocks3");
	TH1F *left = l->load1DHistogram("Histogrammer/time.root", "left");
	TH1F *mid = l->load1DHistogram("Histogrammer/time.root", "mid");

	TH1F *c1 = l->load1DHistogram("Histogrammer/time.root", "alpha_c1");
	TH1F *c2 = l->load1DHistogram("Histogrammer/time.root", "alpha_c2");
	TH1F *c3 = l->load1DHistogram("Histogrammer/time.root", "alpha_c3");
	TH1F *c4 = l->load1DHistogram("Histogrammer/time.root", "alpha_c4");
	TH1F *al_left = l->load1DHistogram("Histogrammer/time.root", "alpha_left");
	TH1F *between = l->load1DHistogram("Histogrammer/time.root", "alpha_between");
	
	TGraph* g = k->setReferenceHistogram(referenceproton);
	
	k->testVsHistogram(protonpeak);

	k->testVsHistogram(left, 0, 1200);
	k->testVsHistogram(mid, 0, 1200);
	k->testVsHistogram(c1, 0, 1200);
	k->testVsHistogram(c2, 0, 1200);
	k->testVsHistogram(c3, 0, 1200);
	k->testVsHistogram(c4, 0, 1200);
	k->testVsHistogram(al_left, 0, 1200);
	k->testVsHistogram(between, 0, 1200);

	fclose(stdout);
}