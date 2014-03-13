#include "DataLoader.h"
#include "TH1F.h"
#include <iostream>
using namespace std;
void TimeAnalysis() {

	DataLoader *l = new DataLoader();
	TH1F *f = l->load1DHistogram("Histogrammer/protonmg21.root", "peak6-time");
	TH1F *ff = l->load1DHistogram("Histogrammer/protonmg21.root", "peak5-time");
	Double_t prob = f->KolmogorovTest(ff);
	cout << prob << endl;
}