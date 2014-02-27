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

int _tmain(int argc, _TCHAR* argv[])
{
	TRint *theApp = new TRint("ROOT example", &argc, (char**)argv);
	
	SRIMLoader* l = new SRIMLoader();
	TGraph* g = l->LoadSRIM("C:/Users/Jesper/Desktop/SRIM/pCF4_mig.txt");
	cout << g->Eval(1862) << endl;
	cout << g->Eval(2036) << endl;
	
	//DataLoader* l = new DataLoader();
	//TChain* chain = l->loadData("mg21.dat", "h7");
	//chain->Process(new Selector(new GasAnalyzer()));
	//timeHistograms();
	theApp->Run();
	return 0;
}

