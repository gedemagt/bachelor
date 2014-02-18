#ifndef ANALYSISCLASS_H
#define ANALYSISCLASS_H

//Libraries included
#include <cmath>
#include "TGraph.h"

class Analysis{
 public:
  //Default constructor
  Analysis() { }

  //---------------------------------------Functions-------------------------------------
  Int_t EventMatching(Double_t *Efront,Int_t Nfe,Double_t *Eback,Int_t Nbe)
  {
    //Function to distinguish noise from particles in the dsssd. It counts how many
    //particles is seen per event. It also does event-matching by the condition of lowest
    //energy difference between front- and backside for each event.
    //It returns directly the number of particles. It puts the index number of Efront and 
    //Eback of the found particle into the class variables iback_vec and ifront_vec.

    //IMPORTANT: iback/ifront is index number in Eback/Efront for entrances with a signal and
    //           the max value is Nbe/Nfe. Not strip number!

    //Variables:
    Int_t Npar=0;
    Double_t Emin, dE_orig, dE;
    Int_t iback_acc[16];

    //Zeroing index numbers:
    for(Int_t i=0;i<16;i++){
      iback_acc[i]=-1;
      iback_vec[i]=-1;
      ifront_vec[i]=-1;
      dE_vec[i]=-1.;
    }
    //A particle must have more than Emin keV energy in dsssd:
    Emin=200.;
    //Maximum difference between front and back side energy:
    dE_orig=300.;
    //Loop that runs through all events in front side (ifront is not strip number):
    for(Int_t ifront=0;ifront<Nfe;ifront++){
      dE=dE_orig;
      if(Efront[ifront] > Emin){
	//Each event on the back side is compared to the events on the front side (iback is not strip number):
	for(Int_t iback=0;iback<Nbe;iback++){
	  if((Eback[iback] > Emin) && (abs(Eback[iback] - Efront[ifront]) < dE)){
	    //Choosing the lowest energy difference between front and back side.  
	    dE=abs(Eback[iback] - Efront[ifront]);
	    iback_acc[ifront]=iback;
	    //Index is ifront in order to do the next comparison. 
	  }
	}
      }
    }
 
    //Present status: the same back strip might be matched to several front strips!! 
    //Next we solve this problem.
    
    //Goes through all back strips:
    Int_t dummy=0;
    for(Int_t iback=0;iback<Nbe;iback++){
      dE_vec[Npar]=dE_orig;
      dummy=0;
      //Loop over all front strips:
      for(Int_t ifront=0;ifront<Nfe;ifront++){
	//If the back strip was coupled to a front strip before and the difference between 
	//front and back side is less than the required difference or a previous accepted
	//event, this is used:
	if((iback==iback_acc[ifront]) && (abs(Eback[iback]-Efront[ifront]) < dE_vec[Npar])){
	  dE_vec[Npar]=abs(Eback[iback]-Efront[ifront]);
	  iback_vec[Npar]=iback;
	  ifront_vec[Npar]=ifront;
	  dummy=5;
	}
      }
      if(dummy==5) Npar++;
    }
    //Status: all frontstrips and backstrips are matched to each other only once!
    return Npar;
  }
  //----------------------------------------------------------------------------------
  Double_t AngularCorrection(Double_t E0,Double_t theta_max)
  {
    //E0 are the energy-loss for theta=0.
    //Function to calculate the angular correction of the energy (Angle must be in radians!):
    Double_t E_ave=-E0*log(abs(cos(theta_max)))/(1-cos(theta_max)); 
    return E_ave;
  }
  //----------------------------------------------------------------------------------
  Double_t AngularCorrectionInv(Double_t E_ave,Double_t theta_max)
  {
    //Function to calculate the inverse angular correction of the energy (Angle must be in 
    //radians!):
    Double_t E0=-E_ave*(1-cos(theta_max))/log(abs(cos(theta_max))); 
    return E0;
  }
  //----------------------------------------------------------------------------------
  Double_t AngCorr(Double_t theta_max)
  {
    //Function to calculate the angular correction factor
    return -log(abs(cos(theta_max)))/(1-cos(theta_max)); 
  }
  //----------------------------------------------------------------------------------
  Double_t RangePar(TGraph *Range,Double_t E0)
  {
    //Function to calculate the projected range from SRIM:
    Double_t Rpar=Range->Eval(E0,0,"S");
    return Rpar;
  }

  //----------------------------------------------------------------------------------
  Double_t ELossPar(TGraph *Range,TGraph *Energy,Double_t E0,Double_t thickness)
  {
    //Function to calculate the energy loss from SRIM:
    Double_t Rpar=Range->Eval(E0,0,"S");
    Double_t Epar=Energy->Eval(Rpar-thickness,0,"S");
    return E0-Epar;
  }
  //----------------------------------------------------------------------------------
  Double_t EPar(TGraph *Range,TGraph *Energy,Double_t E0,Double_t thickness)
  {
    //Function to calculate the energy of a particle after a given deadlayer with SRIM:
    Double_t Rpar=Range->Eval(E0,0,"S");
    Double_t Epar=Energy->Eval(Rpar-thickness,0,"S");
    return Epar;
  }
  //------------------------------------Variables-------------------------------------
  Short_t ChFront[16],ChBack[16];
  Int_t iback_vec[16], ifront_vec[16];
  Double_t dE_vec[16];
};
#endif
