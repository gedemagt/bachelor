#include "DataLoader.h"
#include "TH1F.h"
#include <iostream>
using namespace std;
void TimeAnalysis() {

	DataLoader *l = new DataLoader();
	TH1F *protonpeak = l->load1DHistogram("Histogrammer/protonmg21.root", "peak6-time");
	TH1F *mid = l->load1DHistogram("Histogrammer/time2.root", "midClock");
	TH1F *left = l->load1DHistogram("Histogrammer/time2.root", "leftClocks");

	Double_t prob;

	prob = protonpeak->KolmogorovTest(left);
	cout << prob << endl;

	prob = protonpeak->KolmogorovTest(mid);
	cout << prob << endl;
}