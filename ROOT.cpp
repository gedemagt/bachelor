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
#include "SiliciumAnalyzer.h"
#include "BananaAnalyzer.h"
#include "GasAnalyzer.h"
#include "TRint.h"

using namespace std;

void is507();
void timeHistograms();

int _tmain(int argc, _TCHAR* argv[])
{
	TRint *theApp = new TRint("ROOT example", &argc, (char**)argv);
	DataLoader* l = new DataLoader();
	TChain* chain = l->loadData("FileName1.dat", "h7");
	chain->Process(new Selector(new GasAnalyzer()));
	//timeHistograms();
	theApp->Run();
	return 0;
}

