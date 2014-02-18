// ROOT.cpp : Defines the entry point for the console application.
#include "TApplication.h"
#include "stdafx.h"
#include <iostream>
#include "TString.h"
#include "TH1F.h"
#include "TRint.h"

using namespace std;

void is507();
void timeHistograms();
void TestAreaCut();

int _tmain(int argc, _TCHAR* argv[])
{
	TApplication *theApp = new TApplication("ROOT example", &argc, (char**) argv);
	//TestAreaCut();
	timeHistograms();
	//is507();
	theApp->Run();
	return 0;
}

