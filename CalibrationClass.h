#ifndef CALIBRATIONCLASS_H
#define CALIBRATIONCLASS_H
/********************************************************************
This class can read in calibration parameters with the LoadCalib() 
function. It can give you the calibrated energy back if you input
the non-calibrated value to Calibrate(). Remember that all energies
should be in keV.
It is always possible to include more detectors.

Written by Morten V. Lund, July 2012
 ********************************************************************/

#include <fstream>
using namespace std;

class Calibration{
  
 public:
  //Default constructor
  Calibration() {
    Initialize();
    return;
  }

  //Public functions
  void LoadCalib()
  {
    //Si1 (0:Proton fra Ar-33 1:Proton fra Mg-21 2:Alpha kilde)
    ifstream si1("Kalibrering/silicon1.dat");
    for(Int_t ii=0;ii<3;ii++){si1>>gain_si1[ii]>>offset_si1[ii];}
    si1.close();    
    //Epad
    ifstream epad("Kalibrering/epad.dat");
    epad>>gain_pad>>offset_pad;
    epad.close();
    //DSSSD (0:front 1, 16:back 1, 31:back 16) Strip 4 back is dead/empty
    ifstream dsssd("Kalibrering/linfit_Det1_run_106100.txt");
    Double_t dummy=0;
    for(Int_t ii=0;ii<32;ii++){dsssd>>gain_dsssd[ii]>>dummy>>offset_dsssd[ii]>>dummy;}
    dsssd.close();
    return;
  }

  void Calibrate(Short_t ChPad,Short_t ChSi1,Short_t* ChFront,UChar_t* Nsfe,Int_t Nfe,Short_t* ChBack,UChar_t* Nsbe,Int_t Nbe)
  {
    Initialize();
    //Calibrating Si1 and Epad:
    E1_calib=ChSi1*gain_si1[1]+offset_si1[1];
    Epad_calib=ChPad*gain_pad+offset_pad;
   
    //Calibrating DSSSD:
    for(Int_t strip=0;strip<16;strip++){
      for(Int_t k=0;k<Nfe;k++){
	if(Nsfe[k] == strip+1){
	  Efront[k]=ChFront[k]*gain_dsssd[strip]+offset_dsssd[strip];
	}
      }
      for(Int_t k=0;k<Nbe;k++){
	if(Nsbe[k] == strip+1){
	  Eback[k]=ChBack[k]*gain_dsssd[strip+16]+offset_dsssd[strip+16];
	}
      }
    }
    return;
  }
    
  Double_t Epad_calib,E1_calib,Egas_calib,Efront[16],Eback[16];
  
 private:
  void Initialize(){
    Epad_calib=0.;
    E1_calib=0.;
	Egas_calib=0.;
    for(Int_t ii=0;ii<16;ii++){
      Efront[ii]=0.;
      Eback[ii]=0.;
    }
    return;
  }
 
  Double_t gain_dsssd[32],offset_dsssd[32],gain_si1[3],offset_si1[3],gain_pad,offset_pad; 
};

#endif
