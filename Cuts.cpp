#include "Cuts.h"
#include <iostream>

using namespace std;

Cuts::Cuts(Int_t dimension) {
	dim = dimension;

	cut_1 = new TCutG*[dimension];
	cut_2[dimension];

	histo_1 = new TH1F*[dimension];
	histo_2[dimension];

	current_1 = 0;
	current_2 = 0;

	nBinsx_std_1 = 1;
	xlow_std_1 = 0;
	xup_std_1 = 100;

	nBinsx_std_2 = 1;
	xlow_std_2 = 0;
	xup_std_2 = 100;

	nBinsy_std_2 = 1;
	ylow_std_2 = 0;
	yup_std_2 = 100;
}

Cuts::~Cuts() {
	delete[] cut_1;
	delete[] cut_2;
	delete[] histo_1;
	delete[] histo_2;
}

void Cuts::add1DCut(TCutG* tcut, const char* name, Int_t nbinsx, Double_t xlow, Double_t xup){
	if (current_1 < dim) {
		cut_1[current_1] = tcut;
		TH1F* histo = new TH1F(name, name, nbinsx, xlow, xup);
		histo_1[current_1] = histo;
		current_1++;
	}
}

void Cuts::add1DCut(TCutG* tcut, const char* name){
	if (current_1 < dim) {
		cut_1[current_1] = tcut;
		TH1F* histo = new TH1F(name, name, nBinsx_std_1, xlow_std_1, xup_std_1);
		histo_1[current_1] = histo;
		current_1++;
	}
}

void Cuts::add2DCut(TCutG* tcut, const char* name){
	if (current_2 < dim) {
		cut_2[current_2] = tcut;
		TH2F* histo = new TH2F(name, name, nBinsx_std_2, xlow_std_2, xup_std_2, nBinsy_std_2, ylow_std_2, yup_std_2);
		histo_2[current_2] = histo;
		current_2++;
	}
}

void Cuts::add2DCut(TCutG* tcut, const char* name, Int_t nbinsx, Double_t xlow, Double_t xup, Int_t nbinsy, Double_t ylow, Double_t yup){
	if (current_2 < dim) {
		cut_2[current_2] = tcut;
		TH2F* histo = new TH2F(name, name,nbinsx, xlow, xup, nbinsy, ylow, yup);
		histo_2[current_2] = histo;
		current_2++;
	}
}

void Cuts::setStandard1D(Int_t nbinsx, Double_t xlow, Double_t xup) {
	nBinsx_std_1 = nbinsx;
	xlow_std_1 = xlow;
	xup_std_1 = xup;
}

void Cuts::setStandard2D(Int_t nbinsx, Double_t xlow, Double_t xup, Int_t nbinsy, Double_t ylow, Double_t yup) {
	nBinsx_std_2 = nbinsx;
	xlow_std_2 = xlow;
	xup_std_2 = xup;

	nBinsy_std_2 = nbinsy;
	ylow_std_2 = ylow;
	yup_std_2 = yup;
}

void Cuts::fill1D(Double_t constraint_x, Double_t constraint_y, Double_t x) {
	for (Int_t i = 0; i < current_1; i++) {
		if (cut_1[i]->IsInside(constraint_x, constraint_y)) {
			histo_1[i]->Fill(x);
		}
	}
}

void Cuts::fill2D(Double_t constraint_x, Double_t constraint_y, Double_t x, Double_t y) {
	for (Int_t i = 0; i <= current_2; i++) {
		if (cut_2[i]->IsInside(constraint_x, constraint_y)) histo_2[i]->Fill(x, y);
	}
}
