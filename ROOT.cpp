// ROOT.cpp : Defines the entry point for the console application.
#include "TApplication.h"
#include "stdafx.h"
#include <iostream>
#include "TString.h"
#include "TH1F.h"
#include "TRint.h"
#include "TCanvas.h"

using namespace std;

void is507();
void timeHistograms();
TH1F* binOptimize(TH1F* histo);

int _tmain(int argc, _TCHAR* argv[])
{
	TApplication *theApp = new TApplication("ROOT example", &argc, (char**) argv);
	TCanvas *c1 = new TCanvas("c1", "c1", 500, 500);
	c1->Divide(1, 2);
	c1->cd(1);
	TH1F *f = new TH1F("f", "Erik", 100, 0, 30);
	//f = f->Rebin
	f->FillRandom("gaus", 1000);
	//f->Fill(2);
	f->Draw();
	c1->cd(2);
	TH1F* result = binOptimize(f);
	//result->Draw();
	theApp->Run();
	return 0;
}

