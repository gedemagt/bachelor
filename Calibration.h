#include"Selector.h"
#include"CalibrationClass.h"

#ifndef CALIBRATION_H
#define CALIBRATION_H

class Calib {
public:
	Calibration Mg_Calib;
	Calib(int state) {
		ts = state;
		Mg_Calib.LoadCalib();
	};
	~Calib();
	void calibrate(Selector *s) {
		Mg_Calib.Calibrate(s->Epad, s->E1, s->Ef, s->Nsfe, s->Nfe, s->Eb, s->Nsbe, s->Nbe);
		if (ts == 1)  {
			Egas = s->Egas;
			E1 = s->E1;
		}
		else if (ts == 2) {
			Double_t a = 1.40822;
			Double_t b = -100.146;
			Egas = s->Egas;
			E1 = s->E1 * a + b;
		}
		else if (ts == 3) {
			Egas = s->Egas;
			E1 = Mg_Calib.E1_calib;
		}
	
	};
	char* getCalibration() {
		switch (ts) {
		case 1:
			return "No calibration";
		case 2:
			return "My Calibration";
		case 3:
			return "Mortens Calibration";
		}
	}
	Double_t Egas, E1;
private:
	int ts = 1;
};

#endif