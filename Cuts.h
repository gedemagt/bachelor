#include "TCutG.h"
#include "TH1F.h"
#include "TH2F.h"

#ifndef CUTS_H
#define CUTS_H

class Cuts {
public:
	Cuts(Int_t dimension);
	virtual ~Cuts();
	virtual void add1DCut(TCutG* tcut, const char* name, Int_t nbinsx, Double_t xlow, Double_t xup);
	virtual void add2DCut(TCutG* tcut, const char* name, Int_t nbinsx, Double_t xlow, Double_t xup, Int_t nbinsy, Double_t ylow, Double_t yup);
	virtual void add1DCut(TCutG* tcut, const char* name);
	virtual void add2DCut(TCutG* tcut, const char* name);
	virtual void fill1D(Double_t constraint_x, Double_t constraint_y, Double_t x);
	virtual void fill2D(Double_t constraint_x, Double_t constraint_y, Double_t x, Double_t y);
	virtual void setStandard1D(Int_t nbinsx, Double_t xlow, Double_t xup);
	virtual void setStandard2D(Int_t nbinsx, Double_t xlow, Double_t xup, Int_t nbinsy, Double_t ylow, Double_t yup);
private:

	Int_t current_1;
	Int_t current_2;
	Int_t dim;

	TCutG** cut_1;
	TCutG** cut_2;
	TH1F** histo_1;
	TH2F** histo_2;

	Int_t nBinsx_std_1;
	Double_t xlow_std_1;
	Double_t xup_std_1;

	Int_t nBinsx_std_2;
	Double_t xlow_std_2;
	Double_t xup_std_2;

	Int_t nBinsy_std_2;
	Double_t ylow_std_2;
	Double_t yup_std_2;

};
#endif