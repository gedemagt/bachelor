/*************************************************************************************************
Class definition of SRIM. The class includes three functions, one constructor, and a destructor: 
1) SRIMLoader() is to load data from SRIM-files. The variable m_SrimPath defines the directory, 
which the user gives upon invoking the SetPathName() function. After concatenating the FileName
 SrimPath becomes the path to the file from the current directory.
2) Creategraphs() is to create TGraph objects (members of SRIM) of the relevant SRIM data files.
The SRIM class also includes two private variables. 
3) SetPathName() is used to set the path for the SRIM data files into the variable m_SrimPath.

Written by Morten V. Lund (July 2012)
*************************************************************************************************/
#include <fstream>
#include <iostream>
#include <cstring>
#include <cassert>
#include "TGraph.h"
using namespace std;

class SRIM{
public:
  //Default constructor:
  SRIM()
    {
      //Setting class variables to zero:
      m_SrimPath=0;
      for(Int_t ii=0;ii<131;ii++)
	{
	  Eion[ii]=0.;
	  ProjRange[ii]=0.;
	}
      return;
    }
  //Destructor
  ~SRIM()
    {
      delete[] m_SrimPath;
      m_SrimPath=0;
    }
  //Function to set the path to the SRIM data files:
  void SetPathName(const Char_t Path[])
  {
    m_SrimPath=new Char_t[200];
    strcat(m_SrimPath,Path);
    Char_t dummy[10]="";
    assert(strncmp(m_SrimPath,dummy,100) != 0);  //Gives error if no path is specified.
    return;
  }
  void Creategraphs();
  TGraph *Range[8][16];
  TGraph *Energy[8][16];

private:
  void SRIMLoader(Char_t* FileName);  
  Double_t Eion[131], ProjRange[131];
  Char_t *m_SrimPath;
};

void SRIM::Creategraphs(){
  //Ion: Mg20
  Char_t FileName[30]="Mg20Poly.txt";
  SRIM::SRIMLoader(FileName);
  Range[0][0] = new TGraph(131,Eion,ProjRange);
  Energy[0][0] = new TGraph(131,ProjRange,Eion);
  
  strcpy(FileName,"Mg20Al.txt");
  SRIM::SRIMLoader(FileName);
  Range[0][1] = new TGraph(131,Eion,ProjRange);
  Energy[0][1] = new TGraph(131,ProjRange,Eion);
  
  //Ion: Na20
  strcpy(FileName,"Na20Poly.txt");
  SRIM::SRIMLoader(FileName);
  Range[1][0] = new TGraph(131,Eion,ProjRange);
  Energy[1][0] = new TGraph(131,ProjRange,Eion);

  strcpy(FileName,"Na20Al.txt");
  SRIM::SRIMLoader(FileName);
  Range[1][1] = new TGraph(131,Eion,ProjRange);
  Energy[1][1] = new TGraph(131,ProjRange,Eion);

  strcpy(FileName,"Na20CF4_Malin.txt");
  SRIM::SRIMLoader(FileName);
  Range[1][2] = new TGraph(131,Eion,ProjRange);
  Energy[1][2] = new TGraph(131,ProjRange,Eion);

  strcpy(FileName,"Na20CF4_mig.txt");
  SRIM::SRIMLoader(FileName);
  Range[1][3] = new TGraph(131,Eion,ProjRange);
  Energy[1][3] = new TGraph(131,ProjRange,Eion);

  strcpy(FileName,"Na20Si.txt");
  SRIM::SRIMLoader(FileName);
  Range[1][4] = new TGraph(131,Eion,ProjRange);
  Energy[1][4] = new TGraph(131,ProjRange,Eion);

  //Ion: O16
  strcpy(FileName,"O16Poly.txt");
  SRIM::SRIMLoader(FileName);
  Range[2][0] = new TGraph(131,Eion,ProjRange);
  Energy[2][0] = new TGraph(131,ProjRange,Eion);

  strcpy(FileName,"O16Al.txt");
  SRIM::SRIMLoader(FileName);
  Range[2][1] = new TGraph(131,Eion,ProjRange);
  Energy[2][1] = new TGraph(131,ProjRange,Eion);

  strcpy(FileName,"O16CF4_Malin.txt");
  SRIM::SRIMLoader(FileName);
  Range[2][2] = new TGraph(131,Eion,ProjRange);
  Energy[2][2] = new TGraph(131,ProjRange,Eion);

  strcpy(FileName,"O16CF4_mig.txt");
  SRIM::SRIMLoader(FileName);
  Range[2][3] = new TGraph(131,Eion,ProjRange);
  Energy[2][3] = new TGraph(131,ProjRange,Eion);

  strcpy(FileName,"O16Si.txt");
  SRIM::SRIMLoader(FileName);
  Range[2][4] = new TGraph(131,Eion,ProjRange);
  Energy[2][4] = new TGraph(131,ProjRange,Eion);

  //Ion: Alfa
  strcpy(FileName,"alfaPoly.txt");
  SRIM::SRIMLoader(FileName);
  Range[3][0] = new TGraph(131,Eion,ProjRange);
  Energy[3][0] = new TGraph(131,ProjRange,Eion);

  strcpy(FileName,"alfaAl.txt");
  SRIM::SRIMLoader(FileName);
  Range[3][1] = new TGraph(131,Eion,ProjRange);
  Energy[3][1] = new TGraph(131,ProjRange,Eion);

  strcpy(FileName,"alfaCF4_Malin.txt");
  SRIM::SRIMLoader(FileName);
  Range[3][2] = new TGraph(131,Eion,ProjRange);
  Energy[3][2] = new TGraph(131,ProjRange,Eion);

  strcpy(FileName,"alfaCF4_mig.txt");
  SRIM::SRIMLoader(FileName);
  Range[3][3] = new TGraph(131,Eion,ProjRange);
  Energy[3][3] = new TGraph(131,ProjRange,Eion);

  strcpy(FileName,"alfaSi.txt");
  SRIM::SRIMLoader(FileName);
  Range[3][4] = new TGraph(131,Eion,ProjRange);
  Energy[3][4] = new TGraph(131,ProjRange,Eion);

  //Ion: Proton
  strcpy(FileName,"pPolyp.txt");
  SRIM::SRIMLoader(FileName);
  Range[4][0] = new TGraph(131,Eion,ProjRange);
  Energy[4][0] = new TGraph(131,ProjRange,Eion);

  strcpy(FileName,"pAl.txt");
  SRIM::SRIMLoader(FileName);
  Range[4][1] = new TGraph(131,Eion,ProjRange);
  Energy[4][1] = new TGraph(131,ProjRange,Eion);

  strcpy(FileName,"pCF4_Malin.txt");
  SRIM::SRIMLoader(FileName);
  Range[4][2] = new TGraph(131,Eion,ProjRange);
  Energy[4][2] = new TGraph(131,ProjRange,Eion);

  strcpy(FileName,"pCF4_mig.txt");
  SRIM::SRIMLoader(FileName);
  Range[4][3] = new TGraph(131,Eion,ProjRange);
  Energy[4][3] = new TGraph(131,ProjRange,Eion);

  strcpy(FileName,"pSi.txt");
  SRIM::SRIMLoader(FileName);
  Range[4][4] = new TGraph(131,Eion,ProjRange);
  Energy[4][4] = new TGraph(131,ProjRange,Eion);

  //Ion: Mg21
  strcpy(FileName,"Mg21Poly.txt");
  SRIM::SRIMLoader(FileName);
  Range[5][0] = new TGraph(131,Eion,ProjRange);
  Energy[5][0] = new TGraph(131,ProjRange,Eion);

  strcpy(FileName,"Mg21Al.txt");
  SRIM::SRIMLoader(FileName);
  Range[5][1] = new TGraph(131,Eion,ProjRange);
  Energy[5][1] = new TGraph(131,ProjRange,Eion);

  strcpy(FileName,"Mg21Si.txt");
  SRIM::SRIMLoader(FileName);
  Range[5][2] = new TGraph(131,Eion,ProjRange);
  Energy[5][2] = new TGraph(131,ProjRange,Eion);

  //Ion: Ar33
  strcpy(FileName,"Ar33Poly.txt");
  SRIM::SRIMLoader(FileName);
  Range[6][0] = new TGraph(131,Eion,ProjRange);
  Energy[6][0] = new TGraph(131,ProjRange,Eion);

  strcpy(FileName,"Ar33Al.txt");
  SRIM::SRIMLoader(FileName);
  Range[6][1] = new TGraph(131,Eion,ProjRange);
  Energy[6][1] = new TGraph(131,ProjRange,Eion);

  strcpy(FileName,"Ar33Si.txt");
  SRIM::SRIMLoader(FileName);
  Range[6][2] = new TGraph(131,Eion,ProjRange);
  Energy[6][2] = new TGraph(131,ProjRange,Eion);

  //Ion: alfa, Target: CF4 (various densities)
  strcpy(FileName,"CF4/alfaCF4_8.txt");
  SRIM::SRIMLoader(FileName);
  Range[7][0] = new TGraph(131,Eion,ProjRange);
  Energy[7][0] = new TGraph(131,ProjRange,Eion);

  strcpy(FileName,"CF4/alfaCF4_9.txt");
  SRIM::SRIMLoader(FileName);
  Range[7][1] = new TGraph(131,Eion,ProjRange);
  Energy[7][1] = new TGraph(131,ProjRange,Eion);

  strcpy(FileName,"CF4/alfaCF4_10.txt");
  SRIM::SRIMLoader(FileName);
  Range[7][2] = new TGraph(131,Eion,ProjRange);
  Energy[7][2] = new TGraph(131,ProjRange,Eion);

  strcpy(FileName,"CF4/alfaCF4_11.txt");
  SRIM::SRIMLoader(FileName);
  Range[7][3] = new TGraph(131,Eion,ProjRange);
  Energy[7][3] = new TGraph(131,ProjRange,Eion);

  strcpy(FileName,"CF4/alfaCF4_12.txt");
  SRIM::SRIMLoader(FileName);
  Range[7][4] = new TGraph(131,Eion,ProjRange);
  Energy[7][4] = new TGraph(131,ProjRange,Eion);

  strcpy(FileName,"CF4/alfaCF4_5.txt");
  SRIM::SRIMLoader(FileName);
  Range[7][5] = new TGraph(131,Eion,ProjRange);
  Energy[7][5] = new TGraph(131,ProjRange,Eion);

  strcpy(FileName,"CF4/alfaCF4_13.txt");
  SRIM::SRIMLoader(FileName);
  Range[7][6] = new TGraph(131,Eion,ProjRange);
  Energy[7][6] = new TGraph(131,ProjRange,Eion);

  strcpy(FileName,"CF4/alfaCF4_14.txt");
  SRIM::SRIMLoader(FileName);
  Range[7][7] = new TGraph(131,Eion,ProjRange);
  Energy[7][7] = new TGraph(131,ProjRange,Eion);

  strcpy(FileName,"CF4/alfaCF4_15.txt");
  SRIM::SRIMLoader(FileName);
  Range[7][8] = new TGraph(131,Eion,ProjRange);
  Energy[7][8] = new TGraph(131,ProjRange,Eion);

  strcpy(FileName,"CF4/alfaCF4_22.txt");
  SRIM::SRIMLoader(FileName);
  Range[7][9] = new TGraph(131,Eion,ProjRange);
  Energy[7][9] = new TGraph(131,ProjRange,Eion);

  strcpy(FileName,"CF4/alfaCF4_16.txt");
  SRIM::SRIMLoader(FileName);
  Range[7][10] = new TGraph(131,Eion,ProjRange);
  Energy[7][10] = new TGraph(131,ProjRange,Eion);

  strcpy(FileName,"CF4/alfaCF4_17.txt");
  SRIM::SRIMLoader(FileName);
  Range[7][11] = new TGraph(131,Eion,ProjRange);
  Energy[7][11] = new TGraph(131,ProjRange,Eion);

  strcpy(FileName,"CF4/alfaCF4_18.txt");
  SRIM::SRIMLoader(FileName);
  Range[7][12] = new TGraph(131,Eion,ProjRange);
  Energy[7][12] = new TGraph(131,ProjRange,Eion);

  strcpy(FileName,"CF4/alfaCF4_19.txt");
  SRIM::SRIMLoader(FileName);
  Range[7][13] = new TGraph(131,Eion,ProjRange);
  Energy[7][13] = new TGraph(131,ProjRange,Eion);

  strcpy(FileName,"CF4/alfaCF4_20.txt");
  SRIM::SRIMLoader(FileName);
  Range[7][14] = new TGraph(131,Eion,ProjRange);
  Energy[7][14] = new TGraph(131,ProjRange,Eion);

  strcpy(FileName,"CF4/alfaCF4_21.txt");
  SRIM::SRIMLoader(FileName);
  Range[7][15] = new TGraph(131,Eion,ProjRange);
  Energy[7][15] = new TGraph(131,ProjRange,Eion);
}

void SRIM::SRIMLoader(Char_t *FileName){
  //Checking if m_SrimPath has been set to a value different from zero:
  assert(m_SrimPath != 0);
  
  //Initializing variables:
  Double_t R_ele[131],R_nuc[131],Longi[131],Lateral[131];
  Char_t Eunit[5],Runit[5],LongUnit[5],LatUnit[5];
  Char_t dummy[200];
  Char_t ev[10]="eV",mev[10]="MeV",a[10]="A",mm[10]="mm",m[10]="m";  //For unit recognition
  Char_t SrimPath[200]="";   //Needed to initialize the path correctly each time
  strcat(SrimPath,m_SrimPath);
  strcat(SrimPath,FileName);
  cout<<"SRIM file to be opened is: "<<SrimPath<<endl;
  
  //Loading data:
  ifstream data(SrimPath);
  if(data.is_open()) {cout<<"File is open."<<endl;}
  else {cout<<"File is not open! Error may have occured."<<endl;}  
  for(Int_t ii=0;ii<25;ii++){ data.getline(dummy,200); }   //To skip over header.  
  for(Int_t ii=0;ii<131;ii++){
    Eion[ii]=0.;
    ProjRange[ii]=0.;
    data>>Eion[ii]>>Eunit>>R_ele[ii]>>R_nuc[ii]>>ProjRange[ii]>>Runit>>Longi[ii]>>LongUnit>>Lateral[ii]>>LatUnit;
    if(strcmp(Eunit,ev)==0) Eion[ii]=Eion[ii]*1E-3;
    if(strcmp(Eunit,mev)==0) Eion[ii]=Eion[ii]*1E3;
    if(strcmp(Runit,a)==0) ProjRange[ii]=ProjRange[ii]*1E-4;
    if(strcmp(Runit,mm)==0) ProjRange[ii]=ProjRange[ii]*1E3;
    if(strcmp(Runit,m)==0) ProjRange[ii]=ProjRange[ii]*1E6;
  }
  data.close();
}

