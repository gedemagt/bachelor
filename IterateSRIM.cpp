
#include"SRIMLoader.h"
#include"TGraph.h"
#include"TMatrixD.h"
#include"TArrayD.h"
#include"TVectorD.h"
#include<iostream>
#include"TDecompLU.h"

using namespace std;

TVectorD E_total(3);
TMatrixD matrix(3, 3);
TVectorD channel(3);
TVectorD de(3);
TVectorD result(3);

TGraph *proton;
TGraph *alfa;
TDecompLU *comp;
void fillMatrixColumn(TVectorD vector, Int_t coln);
void fillNewDeltaE(Double_t newC);
void solveMatrix();
void vectorCopyToResult(TVectorD vec2);
void iterateSRIM() {

	SRIMLoader *loader = new SRIMLoader();
	alfa = loader->LoadSRIM("C:/Users/Jesper/Desktop/SRIM/alfaCF4_mig.txt");
	proton = loader->LoadSRIM("C:/Users/Jesper/Desktop/SRIM/pCF4_mig.txt");

	// Set kanal tal
	channel[0] = 1328;
	channel[1] = 3044;
	channel[2] = 1364;

	// Set E_total
	E_total[0] = 2153.2;
	E_total[1] = 4433.8;
	E_total[2] = 1862;

	// Set initial des
	de[0] = alfa->Eval(E_total[0]);
	de[1] = alfa->Eval(E_total[1]);
	de[2] = proton->Eval(E_total[2]);

	// Fill channels
	fillMatrixColumn(channel, 0);

	matrix[0][1] = 1;
	matrix[1][1] = 1;
	matrix[2][1] = 1;

	// Fill SRIM de
	fillMatrixColumn(de, 2);

	// Solve initial
	vectorCopyToResult(E_total);
	comp = new TDecompLU(matrix);
	solveMatrix();
	cout << "Start guess" << endl;
	cout << result[0] << "," << result[1] << "," << result[2] << endl << endl;

	for (int i = 1; i < 15; i++) {
		cout << "Iteration " << i << endl;
		fillNewDeltaE(result[2]);
		vectorCopyToResult(E_total);
		solveMatrix();
		cout << result[0] << "," << result[1] << "," << result[2] << endl << endl;
	}
}

// Copies 2 into 1
void vectorCopyToResult(TVectorD vec2) {
	result[0] = vec2[0];
	result[1] = vec2[1];
	result[2] = vec2[2];
}

void fillMatrixColumn(TVectorD vector, Int_t coln) {
	matrix[0][coln] = vector[0];
	matrix[1][coln] = vector[1];
	matrix[2][coln] = vector[2];
}

void fillNewDeltaE(Double_t newC) {
	Double_t delta_e;
	Double_t devide = 2;
	delta_e = newC * alfa->Eval(E_total[0]);
	matrix[0][2] = alfa->Eval((E_total[0] - delta_e / devide));

	delta_e = newC * alfa->Eval(E_total[1]);
	matrix[1][2] = alfa->Eval((E_total[1] - delta_e / devide));

	delta_e = newC * proton->Eval(E_total[2]);
	matrix[2][2] = proton->Eval((E_total[2] - delta_e / devide));
}

void solveMatrix() {
	comp = new TDecompLU(matrix);
	comp->Solve(result);
}