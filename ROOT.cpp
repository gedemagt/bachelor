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
#include "Mg20GasAnalyzer.h"
#include "Mg20SiliciumAnalyzer.h"
#include "SRIMLoader.h"

using namespace std;

void is507();
void timeHistograms();
void iterateSRIM();

int _tmain(int argc, _TCHAR* argv[])
{
	TRint *theApp = new TRint("ROOT example", &argc, (char**)argv);
	
	//SRIMLoader* l = new SRIMLoader();
	//TGraph* g = l->LoadSRIM("C:/Users/Jesper/Desktop/SRIM/alfaCF4_mig.txt");
	//g->Draw();
	iterateSRIM();
	//DataLoader* l = new DataLoader();
	//TChain* chain = l->loadData("mg21.dat", "h7");
	//chain->Process(new Selector(new GasAnalyzer()));
	//timeHistograms();
	theApp->Run();
	return 0;
}

