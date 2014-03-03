
#include"SRIMLoader.h"
#include"TGraph.h"
#include"TMatrixD.h"
#include"TArrayD.h"
#include"TVectorD.h"
#include<iostream>
#include"TDecompLU.h"

using namespace std;

void iterateSRIM() {

	SRIMLoader *loader = new SRIMLoader();
	TGraph *alfa = loader->LoadSRIM("C:/Users/Jesper/Desktop/SRIM/alfaCF4_mig.txt");
	TGraph *proton = loader->LoadSRIM("C:/Users/Jesper/Desktop/SRIM/pCF4_mig.txt");

	TMatrixD matrix(3, 3);		TVectorD channel(3);	channel[0] = 1328;	channel[1] = 3044;	channel[2] = 1364;

	TVectorD E_total(3);
	E_total[0] = 2153.2;
	E_total[1] = 4433.8;
	E_total[2] = 1862;

	TVectorD de(3);
	de[0] = alfa->Eval(E_total[0]);
	de[1] = alfa->Eval(E_total[1]);
	de[2] = proton->Eval(E_total[2]);

	matrix[0][0] = channel[0];
	matrix[1][0] = channel[1];
	matrix[2][0] = channel[2];

	matrix[0][1] = 1;
	matrix[1][1] = 1;
	matrix[2][1] = 1;

	matrix[0][2] = de[0];
	matrix[1][2] = de[1];
	matrix[2][2] = de[2];

	TDecompLU *comp = new TDecompLU(matrix);
	TVectorD result(3);
	result[0] = E_total[0];
	result[1] = E_total[1];
	result[2] = E_total[2];
	comp->Solve(result);
	cout << result[0] << "," << result[1] << "," << result[2] << endl;

	Double_t E = result[2] * alfa->Eval(4433.8);
	cout << "C_0*dE/dx(4433.8)=" << E << endl;

	Double_t delta_e = result[2] * alfa->Eval(E_total[0]);
	matrix[0][2] = alfa->Eval((E_total[0] - delta_e/2));

	delta_e = result[2] * alfa->Eval(E_total[1]);
	matrix[1][2] = alfa->Eval((E_total[1] - delta_e / 2));

	delta_e = result[2] * proton->Eval(E_total[2]);
	matrix[2][2] = proton->Eval((E_total[2] - delta_e / 2));

	comp = new TDecompLU(matrix);
	result[0] = E_total[0];
	result[1] = E_total[1];
	result[2] = E_total[2];
	comp->Solve(result);
	cout << result[0] << "," << result[1] << "," << result[2] << endl;
}