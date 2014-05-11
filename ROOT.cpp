// ROOT.cpp : Defines the entry point for the console application.
#include "TApplication.h"
#include "stdafx.h"
#include <iostream>
#include "generateHistograms.h"
#include "TRint.h"


using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	TRint *theApp = new TRint("ROOT example", &argc, (char**)argv);
	//generateLeftCornerSquareTimeHistograms();
	//analyseLeftSquare();
	//analyseProtonAround200();

	//generateSi1Si2();
	generateDSSD();
	//analyseSi1Si2Proton();

	theApp->Run();
	return 0;
}

