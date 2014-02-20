
#include "Analyzer.h"
#include "TCutG.h"
#include "TH2F.h"
#include "TFile.h"

class BananaAnalyzer : public Analyzer {

public:
	BananaAnalyzer();
	virtual ~BananaAnalyzer() {};
	void analyze(Selector* s);
	void terminate();
	char* getDestination();

private:

	void fillHistograms(Short_t Egas, Short_t E1);

	TCutG* midCut;
	TCutG* leftCut;
	TCutG* topRightCut;
	TCutG* bottomCut;

	//Histogrammer
	TH2F *allData;
	TH2F *midData;
	TH2F *bottomData;
	TH2F *leftData;
	TH2F *topRightData;
};