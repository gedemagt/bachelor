#include"DataLoader.h"
#include <fstream>
#include <iostream>
#include "TFile.h"
using namespace std;

TChain* DataLoader::loadData(const char* dataFilename, const char* chainName) {
	chain = new TChain(chainName);
	Char_t dFile[100], hFile[100];
	Int_t nfiles;
	ifstream loading(dataFilename);
	loading >> nfiles;
	for (Int_t ii = 0; ii < nfiles; ii++){ loading >> dFile, chain->Add(dFile); }
	loading >> hFile;
	loading.close();
	chain->ls();
	return chain;
}

TCutG* DataLoader::loadCut(const char* fileName, const char* cutName) {
	TFile* file1 = new TFile(fileName);
	TCutG* midCut = (TCutG*) file1->Get(cutName);
	return midCut;
}

TH1F* DataLoader::load1DHistogram(const char* fileName, const char* histoName) {
	TFile* file1 = new TFile(fileName);
	TH1F* histo = (TH1F*) file1->Get(histoName);
	return histo;
}

