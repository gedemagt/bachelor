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
	
	TGraph* g = k->setReferenceHistogram(protonpeak);
	k->testBoth(protonpeak);
	k->testBoth(protonpeak5);
	k->testBoth(left);
	k->testBoth(mid);
	//k->testVsFunction(protonpeak);
	//k->testVsHistogram(protonpeak);
	//k->testVsHistogram(protonpeak5);
	//k->compareHistograms(protonpeak, left);
	//k->compareHistograms(protonpeak, mid);
}