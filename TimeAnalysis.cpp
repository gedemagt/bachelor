#include "DataLoader.h"
#include "Kolmogorow.h"
#include "TH1F.h"
#include <iostream>
using namespace std;
void TimeAnalysis() {

	DataLoader *l = new DataLoader();
	//TH1F *protonpeak = l->load1DHistogram("Histogrammer/protonmg21.root", "peak6-time");
	//TH1F *mid = l->load1DHistogram("Histogrammer/time2.root", "midClock");
	//TH1F *left = l->load1DHistogram("Histogrammer/time2.root", "leftClocks");

	//Double_t prob;

	//prob = protonpeak->KolmogorovTest(left);
	//cout << prob << endl;

	//prob = protonpeak->KolmogorovTest(mid);
	//cout << prob << endl;

	Kolmogorow* k = new Kolmogorow();
	TH1F *protonpeak = l->load1DHistogram("Histogrammer/protonmg21.root", "peak6-time");
	TH1F *protonpeak5 = l->load1DHistogram("Histogrammer/protonmg21.root", "peak5-time");
	TH1F *left = l->load1DHistogram("Histogrammer/time2.root", "leftClocks");
	TH1F *mid = l->load1DHistogram("Histogrammer/time2.root", "midClock");
	TGraph* g = k->generateFunction(protonpeak);
	//k->testHistogram(protonpeak);
	cout << "Proton peak 5" << endl;
	k->compareHistograms(protonpeak, protonpeak5);
	cout << "Left" << endl;
	k->compareHistograms(protonpeak, left);
	cout << "Mid" << endl;
	k->compareHistograms(protonpeak, mid);
}