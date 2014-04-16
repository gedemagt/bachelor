#include"TH1F.h"
#include"Kolmogorow.h"

class MonteCarlo {
public:
	MonteCarlo();
	~MonteCarlo();
	void performSimulation();
	void setModelHistogram(TH1F* histo);
	void setRepeats(Int_t repeats);
	void setCounts(Int_t counts);

	Double_t* A;
	Double_t* D;
	Double_t* W;

private:

	Int_t _repeats;
	Int_t _counts;
	TH1F* cum_normalized_hitso;

	Int_t findBinNumber(Double_t y);

	Double_t* random_num;

	Kolmogorow* kol;
};