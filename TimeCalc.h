#include "TH1F.h"
#include "Selector.h"

#ifndef TIMECALC_H
#define TIMECALC_H

class TimeCalc {
public:
	TimeCalc();
	~TimeCalc();
	void calculateNewEvent(Selector* s);
	void fillHistogram(TH1F* histo);
	bool shouldFill();
	Int_t getClocks();
private:
	Int_t clockllast = 0, Nt1last = 0, clocks, clockl;
};

#endif