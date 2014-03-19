#include "DataLoader.h"
#include "Kolmogorow.h"
#include "TH1F.h"
#include <iostream>
using namespace std;
void TimeAnalysis() {

	DataLoader *l = new DataLoader();
	Kolmogorow* k = new Kolmogorow();
	TH1F *protonpeak = l->load1DHistogram("Histogrammer/protonmg21.root", "peak6-time");
	TH1F *protonpeak5 = l->load1DHistogram("Histogrammer/protonmg21.root", "peak5-time");
	TH1F *protons = l->load1DHistogram("Histogrammer/time.root", "bottomClocks3");
	TH1F *left = l->load1DHistogram("Histogrammer/time.root", "leftClocks");
	TH1F *mid = l->load1DHistogram("Histogrammer/time.root", "midClock");
	
	TGraph* g = k->setReferenceHistogram(protonpeak);
	k->testBoth(protonpeak);
	k->testBoth(protons);
	k->testBoth(protonpeak5);
	k->testBoth(left);
	k->testBoth(mid);
}