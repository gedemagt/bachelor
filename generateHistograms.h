#include "DataLoader.h"
#include "RootTCut.h"
#include "Cuts.h"
#include "Selector.h"
#include "TimeAnalyzer.h"
#include "SiliciumAnalyzer.h"
#include "BananaAnalyzer.h"
#include "GasAnalyzer.h"
#include "Mg20GasAnalyzer.h"
#include "ProtonMg21Analyzer.h"
#include "Mg20SiliciumAnalyzer.h"
#include "Cut2D.h"
#include "Si1Si2Analyzer.h"
#include "DSSDAnalyzer.h"
#include "BetaAnalyzer.h"
#include "LaseroffAnalyzer.h"

#ifndef GENERATEHISTOGRAMS_H
#define GENERATEHISTOGRAMS_H

void generateTimeHistograms() {
	DataLoader* l = new DataLoader();
	TChain* chain = l->loadData("mg21.dat", "h7");
	TimeAnalyzer* t = new TimeAnalyzer("New/time");
	Cuts* c = new Cuts(30);
	TCutG* midCut = l->loadCut("Histogrammer/cuts/midCut.root", "CUTG");
	TCutG* bottomCut = l->loadCut("Histogrammer/cuts/bottomCut.root", "CUTG");
	TCutG* bottomCut2 = l->loadCut("Histogrammer/cuts/bottomCut2.root", "CUTG");
	TCutG* bottomLeftCut = l->loadCut("Histogrammer/cuts/bottomLeftCut.root", "CUTG");
	TCutG* leftCut = l->loadCut("Histogrammer/cuts/lotofcuts.root", "left");
	TCutG* topRightCut = l->loadCut("Histogrammer/cuts/topRightCut.root", "CUTG");
	TCutG* bottomClock3sCut = l->loadCut("Histogrammer/cuts/lotofcuts.root", "bottom1");
	TCutG* overflowCut = l->loadCut("Histogrammer/cuts/lotofcuts.root", "overflow");
	TCutG* bottomClock3BigCut = l->loadCut("Histogrammer/cuts/protoncuts.root", "bigcut");


	TCutG* c1 = l->loadCut("Histogrammer/cuts/alphacuts.root", "center1");
	TCutG* c2 = l->loadCut("Histogrammer/cuts/alphacuts.root", "center2");
	TCutG* c3 = l->loadCut("Histogrammer/cuts/alphacuts.root", "center33");
	TCutG* c4 = l->loadCut("Histogrammer/cuts/alphacuts.root", "center44");
	TCutG* ll = l->loadCut("Histogrammer/cuts/alphacuts.root", "left");
	TCutG* between = l->loadCut("Histogrammer/cuts/alphacuts.root", "between");

	TCutG* proton_right_cut = l->loadCut("Histogrammer/cuts/tailcuts.root", "right");
	TCutG* proton_mid_cut = l->loadCut("Histogrammer/cuts/tailcuts.root", "middle");
	TCutG* proton_left_mid_cut = l->loadCut("Histogrammer/cuts/tailcuts.root", "leftmid");
	TCutG* proton_left_cut = l->loadCut("Histogrammer/cuts/tailcuts.root", "left");

	TCutG* top_1 = l->loadCut("Histogrammer/cuts/tailcuts.root", "top");
	TCutG* bottom_1 = l->loadCut("Histogrammer/cuts/tailcuts.root", "bottom");

	TCutG* extra_all = l->loadCut("Histogrammer/cuts/extra_cuts.root", "all_reduced");
	TCutG* extra_inner = l->loadCut("Histogrammer/cuts/extra_cuts.root", "bot_inner");
	TCutG* extra_mid = l->loadCut("Histogrammer/cuts/extra_cuts.root", "bot_mid");
	TCutG* extra_out = l->loadCut("Histogrammer/cuts/extra_cuts.root", "bot_out");

	TCutG* beta_left = l->loadCut("Histogrammer/cuts/betabeta.root", "beta_left");
	TCutG* beta_right = l->loadCut("Histogrammer/cuts/betabeta.root", "beta_right");

	c->setStandard1D(5000, 0, 5000);

	c->add1DCut(new RootTCut(extra_all), "extra_all");
	c->add1DCut(new RootTCut(extra_inner), "extra_inner");
	c->add1DCut(new RootTCut(extra_mid), "extra_mid");
	c->add1DCut(new RootTCut(extra_out), "extra_out");

	c->add1DCut(new RootTCut(c1), "alpha_c1");
	c->add1DCut(new RootTCut(c2), "alpha_c2");
	c->add1DCut(new RootTCut(c3), "alpha_c3");
	c->add1DCut(new RootTCut(c4), "alpha_c4");
	c->add1DCut(new RootTCut(ll), "alpha_left");
	c->add1DCut(new RootTCut(between), "alpha_between");

	c->add1DCut(new RootTCut(midCut), "mid");
	c->add1DCut(new RootTCut(bottomCut), "bottom");
	c->add1DCut(new RootTCut(bottomCut2), "bottom2");
	c->add1DCut(new RootTCut(bottomLeftCut), "bottomLeft");
	c->add1DCut(new RootTCut(leftCut), "left");
	c->add1DCut(new RootTCut(topRightCut), "topRight");
	c->add1DCut(new RootTCut(bottomClock3sCut), "bottom3");
	c->add1DCut(new RootTCut(overflowCut), "overflow");
	c->add1DCut(new RootTCut(bottomClock3BigCut), "bottom3Big");

	c->add1DCut(new RootTCut(proton_right_cut), "tail_21"); // peak 21
	c->add1DCut(new RootTCut(proton_mid_cut), "tail_6"); // peak 6
	c->add1DCut(new RootTCut(proton_left_mid_cut), "tail_1"); // peak 1
	c->add1DCut(new RootTCut(proton_left_cut), "tail_y"); // y-aksen

	c->add1DCut(new RootTCut(top_1), "top_peak_1");
	c->add1DCut(new RootTCut(bottom_1), "bottom_peak_1");

	c->add1DCut(new RootTCut(beta_left), "beta_left");
	c->add1DCut(new RootTCut(beta_right), "beta_right");
	t->setCuts(c);
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

void generateProtonMg21Silicium() {
	DataLoader* l = new DataLoader();
	TChain* chain = l->loadData("mg21.dat", "h7");
	ProtonMg21Analyzer* t = new ProtonMg21Analyzer("New/proton21_silicium");
	Selector *s = new Selector(t);
	chain->Process(s);
}

void generateMg20Silicium() {
	DataLoader* l = new DataLoader();
	TChain* chain = l->loadData("mg20.dat", "h7");
	Mg20SiliciumAnalyzer* t = new Mg20SiliciumAnalyzer("New/mg20_silicium");
	Selector *s = new Selector(t);
	chain->Process(s);
}

void generateMg20Gas() {
	DataLoader* l = new DataLoader();
	TChain* chain = l->loadData("mg20.dat", "h7");
	Mg20GasAnalyzer* t = new Mg20GasAnalyzer("New/mg20_gas");
	Selector *s = new Selector(t);
	chain->Process(s);
}

void generateMg21Gas() {
	DataLoader* l = new DataLoader();
	TChain* chain = l->loadData("mg21.dat", "h7");
	GasAnalyzer* t = new GasAnalyzer("New/mg21_gas");
	Selector *s = new Selector(t);
	chain->Process(s);
}

void generateMg21Banana() {
	DataLoader* l = new DataLoader();
	TChain* chain = l->loadData("mg21.dat", "h7");
	BananaAnalyzer* t = new BananaAnalyzer("New/mg21_banana");
	Selector *s = new Selector(t);
	chain->Process(s);
}

void generateLeftCornerSquareTimeHistograms() {
	DataLoader* l = new DataLoader();
	TChain* chain = l->loadData("mg21.dat", "h7");
	TimeAnalyzer* t = new TimeAnalyzer("New/timeSquare");

	Int_t x_max = 700;
	Int_t y_max = 1500;
	Int_t x_min = 20;
	Int_t y_min = 0;
	Int_t x = 50;
	Int_t y = 80;
	
	Cuts* c = new Cuts((x_max/x+1)*(y_max/y+1));
	c->setStandard1D(5000, 0, 5000);
	
	for (Double_t i = x_min; i < x_max; i+=x) {
		for (Double_t j = y_min; j < y_max; j+=y) {
			char name[2];
			sprintf(name, "%lg%lg", i, j);
			c->add1DCut(new Cut2D(i, i+x, j+y, j, name),name);
		}
	}
	t->setCuts(c);
	Selector *s = new Selector(t);
	chain->Process(s);
}

void generateSi1Si2() {
	DataLoader* l = new DataLoader();
	TChain* chain = l->loadData("mg21.dat", "h7");
	Si1Si2Analyzer* t = new Si1Si2Analyzer("New/si1si2");
	Selector *s = new Selector(t);
	chain->Process(s);
}

void generateDSSD() {
	DataLoader* l = new DataLoader();
	TChain* chain = l->loadData("mg21.dat", "h7");
	DSSDAnalyzer* t = new DSSDAnalyzer("New/dssd");
	Selector *s = new Selector(t);
	chain->Process(s);
}

void generateBeta() {
	DataLoader* l = new DataLoader();
	TChain* chain = l->loadData("mg21.dat", "h7");
	BetaAnalyzer* t = new BetaAnalyzer("New/beta");
	Selector *s = new Selector(t);
	chain->Process(s);
}

void generateLaserOff() {
	DataLoader* l = new DataLoader();
	TChain* chain = l->loadData("mg21_laseroff.dat", "h7");
	LaseroffAnalyzer* t = new LaseroffAnalyzer("New/laseroff");
	Selector *s = new Selector(t);
	chain->Process(s);
}

#endif;