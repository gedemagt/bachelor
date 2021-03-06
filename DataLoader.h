#ifndef DATALOADER_H
#define DATALOADER_H

#include "TChain.h"
#include "TCutG.h"

class DataLoader
{
public:

	DataLoader(void){};
	virtual ~DataLoader(void){};
	virtual TChain* loadData(const char* dataFilename, const char* chainName);
	virtual TCutG* loadCut(const char* fileName, const char* cutName);
	virtual TH1F* load1DHistogram(const char* fileName, const char* cutName);

private:
	TChain* chain;
};

#endif
