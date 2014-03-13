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
#include "Calibration.h"
#include "ProtonMg21Analyzer.h"

void TimeAnalysis();

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	TRint *theApp = new TRint("ROOT example", &argc, (char**)argv);
	DataLoader* l = new DataLoader();
	TChain* chain = l->loadData("mg21.dat", "h7");
	Calib *c = new Calib(1);
	SiliciumAnalyzer* sa = new SiliciumAnalyzer(c);
	Selector *s = new Selector(new ProtonMg21Analyzer());
	chain->Process(s);

	//TimeAnalysis();
	theApp->Run();
	return 0;
}

