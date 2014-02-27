#include "TGraph.h"
#include <fstream>
#include <iostream>
#include <cstring>
#include "TAxis.h"
using namespace std;

class SRIMLoader {
public:
	SRIMLoader() {};
	~SRIMLoader() {};
	TGraph* LoadSRIM(const Char_t path[]) {
		//Initializing variables:
		Char_t Eunit[5];
		Char_t dummy[200];
		Char_t ev[10] = "eV", mev[10] = "MeV", a[10] = "A", mm[10] = "mm", m[10] = "m";  //For unit recognition
		Double_t R_ele[131], R_nuc[131], Longi[131], Lateral[131], ProjRange[131];
		Char_t Runit[5], LongUnit[5], LatUnit[5];
		//Char_t SrimPath[200] = "";   //Needed to initialize the path correctly each time
		//Double_t R_ele[131], R_nuc[131], Longi[131], Lateral[131], ProjRange[131];
		//Char_t Eunit[5], Runit[5], LongUnit[5], LatUnit[5];
		cout << "SRIM file to be opened is: " << path << endl;

		//Loading data:
		ifstream data(path);
		if (data.is_open()) { cout << "File is open." << endl; }
		else { cout << "File is not open! Error may have occured." << endl; }
		for (Int_t ii = 0; ii<25; ii++){ data.getline(dummy, 200); }   //To skip over header.  
		for (Int_t ii = 0; ii<131; ii++){
			E[ii] = 0.;
			Delta_E[ii] = 0.;
			data >> E[ii] >> Eunit >> Delta_E[ii] >> R_nuc[ii] >> ProjRange[ii] >> Runit >> Longi[ii] >> LongUnit >> Lateral[ii] >> LatUnit;
			if (strcmp(Eunit, ev) == 0) E[ii] = E[ii] * 1E-3;
			if (strcmp(Eunit, mev) == 0) E[ii] = E[ii] * 1E3;
			//	if (strcmp(Runit, a) == 0) ProjRange[ii] = ProjRange[ii] * 1E-4;
			//	if (strcmp(Runit, mm) == 0) ProjRange[ii] = ProjRange[ii] * 1E3;
			//	if (strcmp(Runit, m) == 0) ProjRange[ii] = ProjRange[ii] * 1E6;
		}
		data.close();

		// Create TGraph
		TGraph* g = new TGraph(131, E, Delta_E);
		g->GetXaxis()->SetTitle("E [keV]");
		g->GetYaxis()->SetTitle("E [keV/(mg/cm2)]");
		return g;
	}
private:
	Char_t* path;
	Double_t E[131];
	Double_t Delta_E[131];
};