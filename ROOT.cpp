// ROOT.cpp : Defines the entry point for the console application.
#include "TApplication.h"
#include "stdafx.h"
#include <iostream>
#include "TRint.h"
#include "generateHistograms.h"
#include "Macros.h"
#include "SRIMM.h"

using namespace std;

void CumuTime();
void MonteCarloSimulation(Int_t c, Int_t r);
void TimeAnalysis();
void iterateSRIM();
void findEnergy(Int_t channel, Double_t startGuess);
void iterate(Int_t iterations);

int _tmain(int argc, _TCHAR* argv[])
{
	TRint *theApp = new TRint("ROOT example", &argc, (char**)argv);

	CreateLandauGraph();

	theApp->Run();
	return 0;
}

