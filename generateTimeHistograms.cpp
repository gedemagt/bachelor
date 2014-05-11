#include "DataLoader.h"
#include "RootTCut.h"
#include "Cuts.h"
#include "Selector.h"
#include "TimeAnalyzer.h"
#include "SiliciumAnalyzer.h"

void generateTimeHistograms() {
	DataLoader* l = new DataLoader();
	TChain* chain = l->loadData("mg21.dat", "h7");
	TimeAnalyzer* t = new TimeAnalyzer("New/time");
	Selector *s = new Selector(t);
	chain->Process(s);
}

void generateMg21Silicium() {
	DataLoader* l = new DataLoader();
	TChain* chain = l->loadData("mg21.dat", "h7");
	Calib *c = new Calib(1);
	SiliciumAnalyzer* t = new SiliciumAnalyzer(c, "New/silicium21_large");
	Selector *s = new Selector(t);
	chain->Process(s);
}