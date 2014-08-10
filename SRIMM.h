#ifndef SRIMMCLASS_H
#define SRIMMCLASS_H
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
#include "TString.h"
using namespace std;

class SRIMM{
public:
  //Default constructor:
	SRIMM()
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
  ~SRIMM()
    {
      delete[] m_SrimPath;
      m_SrimPath=0;
    }
  //Function to set the path to the SRIM data files:
  void SetPathName(const Char_t Path[])
  {
	  cout << Path << endl;
    m_SrimPath=new Char_t[200];
    strcat(m_SrimPath,Path);
	cout << m_SrimPath << endl;
    Char_t dummy[10]="";
    assert(strncmp(m_SrimPath,dummy,100) != 0);  //Gives error if no path is specified.
	m_SrimPath = "C:/Users/Jesper/Desktop/SRIM/";
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

#endif