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
	theApp->Run();
	return 0;
}

