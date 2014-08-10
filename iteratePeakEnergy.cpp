#include"SRIMLoader.h"

TGraph *alfaa;
Double_t a, b, c;
Double_t newStartEnergy;
Int_t ch;

void iterate(int iterations) {
	for (int i = 0; i < iterations; i++) {
		newStartEnergy = a * ch + b + c*alfaa->Eval(newStartEnergy - c*alfaa->Eval(newStartEnergy - newStartEnergy / 2));
		cout << "E: " << newStartEnergy << endl;
	}
}

void findEnergy(Int_t channel,  Double_t startGuess) {

	a = 1.40822;
	b = -100.146;
	c = 315.401;
	ch = channel;
	newStartEnergy = startGuess;
	SRIMLoader *loader = new SRIMLoader();
	alfaa = loader->LoadSRIM("C:/Users/Jesper/Desktop/SRIM/alfaCF4_mig.txt");
}