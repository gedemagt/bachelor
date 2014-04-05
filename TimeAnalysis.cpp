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

	TH1F *protonpeak1 = l->load1DHistogram("Histogrammer/protonmg21.root", "peak1-time");
	TH1F *protonpeak2 = l->load1DHistogram("Histogrammer/protonmg21.root", "peak2-time");
	TH1F *protonpeak3 = l->load1DHistogram("Histogrammer/protonmg21.root", "peak3-time");
	TH1F *protonpeak4 = l->load1DHistogram("Histogrammer/protonmg21.root", "peak4-time");
	TH1F *protonpeak5 = l->load1DHistogram("Histogrammer/protonmg21.root", "peak5-time");
	TH1F *protonpeak6 = l->load1DHistogram("Histogrammer/protonmg21.root", "peak6-time");
	TH1F *protonpeak7 = l->load1DHistogram("Histogrammer/protonmg21.root", "peak7-time");
	TH1F *protonpeak8 = l->load1DHistogram("Histogrammer/protonmg21.root", "peak8-time");
	TH1F *protonpeak18 = l->load1DHistogram("Histogrammer/protonmg21.root", "peak18-time");
	TH1F *protonpeak19 = l->load1DHistogram("Histogrammer/protonmg21.root", "peak19-time");
	TH1F *protonpeak20 = l->load1DHistogram("Histogrammer/protonmg21.root", "peak20-time");
	TH1F *protonpeak21 = l->load1DHistogram("Histogrammer/protonmg21.root", "peak21-time");
	TH1F *protonpeakekstra = l->load1DHistogram("Histogrammer/protonmg21.root", "peakekstra1-time");

	TH1F *protonpeak1top = l->load1DHistogram("Histogrammer/time.root", "top_peak_1");
	TH1F *protonpeak1bottom = l->load1DHistogram("Histogrammer/time.root", "bottom_peak_1");
	
	TGraph* g = k->setReferenceHistogram(referenceproton);
	
	k->testVsHistogram(protonpeak1, 0, 1200);
	k->testVsHistogram(protonpeak2, 0, 1200);
	k->testVsHistogram(protonpeak3, 0, 1200);
	k->testVsHistogram(protonpeak4, 0, 1200);
	k->testVsHistogram(protonpeak5, 0, 1200);
	k->testVsHistogram(protonpeak6, 0, 1200);
	k->testVsHistogram(protonpeak7, 0, 1200);
	k->testVsHistogram(protonpeak8, 0, 1200);
	k->testVsHistogram(protonpeak18, 0, 1200);
	k->testVsHistogram(protonpeak19, 0, 1200);
	k->testVsHistogram(protonpeak20, 0, 1200);
	k->testVsHistogram(protonpeak21, 0, 1200);
	k->testVsHistogram(protonpeakekstra, 0, 1200);
	k->testVsHistogram(protonpeak1top, 0, 1200);
	k->testVsHistogram(protonpeak1bottom, 0, 1200);

	fclose(stdout);
}