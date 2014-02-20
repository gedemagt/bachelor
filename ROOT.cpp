// ROOT.cpp : Defines the entry point for the console application.
#include "TApplication.h"
#include "stdafx.h"
#include <iostream>
#include "TString.h"
#include "TH1F.h"
#include "TRint.h"
#include "TCanvas.h"
#include "TChain.h"
#include "DataLoader.h"
#include "Selector.h"
#include "TimeAnalyzer.h"

using namespace std;

void is507();
void timeHistograms();
TH1F* binOptimize(TH1F* histo);

int _tmain(int argc, _TCHAR* argv[])
{
	TApplication *theApp = new TApplication("ROOT example", &argc, (char**)argv);
	//DataLoader* l = new DataLoader();
	//TChain* chain = l->loadData("FileName1.dat", "h7");
	//chain->Process(new Selector(new TimeAnalyzer("Erik")));
	timeHistograms();
	theApp->Run();
	return 0;
}

