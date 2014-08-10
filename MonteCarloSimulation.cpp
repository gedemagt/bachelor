#include"MonteCarlo.h"
#include"DataLoader.h"
#include"TMath.h"
#include<iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void printReport(ofstream &file, Int_t repeats, Double_t* A, Double_t* W, Double_t* D) {
	const char separator = ' ';
	const int numWidth = 10;
	const int charWidth = 4;
	Double_t* alpha = new Double_t[]{ 0.75, 0.85, 0.9, 0.95, 0.975, 0.99 };
	Int_t i = 0;
	// Header
	for (i = 0; i < 6; i++) {
		file << left << setw(numWidth) << setfill(separator) << alpha[i];
	}
	file << endl;
	// Fill D
	file << left << setw(charWidth) << setfill(separator) << "D";
	for (i = 0; i < 6; i++) {
		Int_t index = alpha[i] * repeats;
		file << left << setw(numWidth) << setfill(separator) << D[index];
	}
	file << endl;
	// Fill W
	file << left << setw(charWidth) << setfill(separator) << "W";
	for (i = 0; i < 6; i++) {
		Int_t index = alpha[i] * repeats;
		file << left << setw(numWidth) << setfill(separator) << W[index];
	}
	file << endl;
	// Fill A
	file << left << setw(charWidth) << setfill(separator) << "A";
	for (i = 0; i < 6; i++) {
		Int_t index = alpha[i] * repeats;
		file << left << setw(numWidth) << setfill(separator) << A[index];
	}
	file << endl;

}

void MonteCarloSimulation(Int_t c, Int_t r) {
	DataLoader* l = new DataLoader();
	TH1F *referenceproton = l->load1DHistogram("Histogrammer/New/time.root", "bottom3");
	Int_t repeats = r;
	Int_t counts = c;
	MonteCarlo* mc = new MonteCarlo();
	mc->setModelHistogram(referenceproton);
	mc->setCounts(counts);
	mc->setRepeats(repeats);
	
	mc->performSimulation();
	
	Int_t* sorted_A = new Int_t[repeats];
	Int_t* sorted_W = new Int_t[repeats];
	Int_t* sorted_D = new Int_t[repeats];
	
	Double_t* A = new Double_t[repeats];
	Double_t* W = new Double_t[repeats];
	Double_t* D = new Double_t[repeats];

	TMath::Sort(repeats, mc->A, sorted_A, false);
	TMath::Sort(repeats, mc->W, sorted_W, false);
	TMath::Sort(repeats, mc->D, sorted_D, false);

	char result_str[80];
	char report_str[80];
	//strcat(str, "montecarlo");
	sprintf(result_str, "montecarlo%i_%i.txt", counts, repeats);
	sprintf(report_str, "montecarlo%i_%i_raport.txt", counts, repeats);

	ofstream myfile;
	myfile.open(result_str);
	myfile << "D,W,A" << endl;
	for (int i = 0; i < repeats; i++) {
		A[i] = (mc->A)[sorted_A[i]];
		D[i] = (mc->D)[sorted_D[i]];
		W[i] = (mc->W)[sorted_W[i]];
		myfile << D[i] << "," << W[i] << "," << A[i] << endl;
	}
	myfile.close();
	ofstream report;
	report.open(report_str);
	printReport(report, repeats, A, W, D);
	report.close();
	//cout << A[37999] << endl;
	//cout << W[37999] << endl;
	//cout << D[37999] << endl;
}