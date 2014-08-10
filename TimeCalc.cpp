#include "TimeCalc.h"

TimeCalc::TimeCalc() {

}

TimeCalc::~TimeCalc() {

}

bool TimeCalc::shouldFill() {
	return clockl > clockllast;
}

Int_t TimeCalc::getClocks() {
	return clocks;
}

void TimeCalc::calculateNewEvent(Selector* s) {

	if (s->Nt1 < Nt1last) {
		clockllast = 0;
		Nt1last = 0;
	}

	clockl = s->Clockl;
	clocks = 0;
	if (s->Clockl > clockllast){
		clocks = s->Clockl - clockllast;
		if (s->Nt1 > Nt1last){
			clockllast = s->Clockl;
			Nt1last = s->Nt1;
		}
	}
}

void TimeCalc::fillHistogram(TH1F* histo) {
	if (clockl > clockllast){
		histo->Fill(clocks);
	}
}