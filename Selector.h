//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Feb 18 19:05:36 2014 by ROOT version 5.34/14
// from TChain h7/
//////////////////////////////////////////////////////////

#ifndef h7_h
#define h7_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class h7 : public TSelector {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

   // Declaration of leaf types
   Int_t           Clockl;
   Int_t           Ievent;
   Int_t           Ntrig;
   Int_t           Nacc;
   Int_t           Np;
   Int_t           Nn;
   Int_t           Ngas;
   Int_t           Ne1;
   Int_t           Ne2;
   Int_t           Npad;
   Int_t           Nt1;
   Short_t         Egas;
   Short_t         E1;
   Short_t         E2;
   Short_t         Epad;
   Short_t         Tgas;
   Short_t         T1;
   Short_t         T2;
   Short_t         Tpad;
   Int_t           Nfe;
   Int_t           Nbe;
   UChar_t         Nsfe[16];   //[Nfe]
   UChar_t         Nsbe[16];   //[Nbe]
   Short_t         Ef[16];   //[Nfe]
   Short_t         Eb[16];   //[Nbe]
   Int_t           Nft;
   Int_t           Nbt;
   UChar_t         Nsft[100];   //[Nft]
   UChar_t         Nsbt[100];   //[Nbt]
   Short_t         Tf[100];   //[Nft]
   Short_t         Tb[100];   //[Nbt]

   // List of branches
   TBranch        *b_Clockl;   //!
   TBranch        *b_Ievent;   //!
   TBranch        *b_Ntrig;   //!
   TBranch        *b_Nacc;   //!
   TBranch        *b_Np;   //!
   TBranch        *b_Nn;   //!
   TBranch        *b_Ngas;   //!
   TBranch        *b_Ne1;   //!
   TBranch        *b_Ne2;   //!
   TBranch        *b_Npad;   //!
   TBranch        *b_Nt1;   //!
   TBranch        *b_Egas;   //!
   TBranch        *b_E1;   //!
   TBranch        *b_E2;   //!
   TBranch        *b_Epad;   //!
   TBranch        *b_Tgas;   //!
   TBranch        *b_T1;   //!
   TBranch        *b_T2;   //!
   TBranch        *b_Tpad;   //!
   TBranch        *b_Nfe;   //!
   TBranch        *b_Nbe;   //!
   TBranch        *b_Nsfe;   //!
   TBranch        *b_Nsbe;   //!
   TBranch        *b_Ef;   //!
   TBranch        *b_Eb;   //!
   TBranch        *b_Nft;   //!
   TBranch        *b_Nbt;   //!
   TBranch        *b_Nsft;   //!
   TBranch        *b_Nsbt;   //!
   TBranch        *b_Tf;   //!
   TBranch        *b_Tb;   //!

   h7(TTree * /*tree*/ =0) : fChain(0) { }
   virtual ~h7() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   //ClassDef(h7,0);
};

#endif

#ifdef h7_cxx
void h7::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("Clockl", &Clockl, &b_Clockl);
   fChain->SetBranchAddress("Ievent", &Ievent, &b_Ievent);
   fChain->SetBranchAddress("Ntrig", &Ntrig, &b_Ntrig);
   fChain->SetBranchAddress("Nacc", &Nacc, &b_Nacc);
   fChain->SetBranchAddress("Np", &Np, &b_Np);
   fChain->SetBranchAddress("Nn", &Nn, &b_Nn);
   fChain->SetBranchAddress("Ngas", &Ngas, &b_Ngas);
   fChain->SetBranchAddress("Ne1", &Ne1, &b_Ne1);
   fChain->SetBranchAddress("Ne2", &Ne2, &b_Ne2);
   fChain->SetBranchAddress("Npad", &Npad, &b_Npad);
   fChain->SetBranchAddress("Nt1", &Nt1, &b_Nt1);
   fChain->SetBranchAddress("Egas", &Egas, &b_Egas);
   fChain->SetBranchAddress("E1", &E1, &b_E1);
   fChain->SetBranchAddress("E2", &E2, &b_E2);
   fChain->SetBranchAddress("Epad", &Epad, &b_Epad);
   fChain->SetBranchAddress("Tgas", &Tgas, &b_Tgas);
   fChain->SetBranchAddress("T1", &T1, &b_T1);
   fChain->SetBranchAddress("T2", &T2, &b_T2);
   fChain->SetBranchAddress("Tpad", &Tpad, &b_Tpad);
   fChain->SetBranchAddress("Nfe", &Nfe, &b_Nfe);
   fChain->SetBranchAddress("Nbe", &Nbe, &b_Nbe);
   fChain->SetBranchAddress("Nsfe", Nsfe, &b_Nsfe);
   fChain->SetBranchAddress("Nsbe", Nsbe, &b_Nsbe);
   fChain->SetBranchAddress("Ef", Ef, &b_Ef);
   fChain->SetBranchAddress("Eb", Eb, &b_Eb);
   fChain->SetBranchAddress("Nft", &Nft, &b_Nft);
   fChain->SetBranchAddress("Nbt", &Nbt, &b_Nbt);
   fChain->SetBranchAddress("Nsft", Nsft, &b_Nsft);
   fChain->SetBranchAddress("Nsbt", Nsbt, &b_Nsbt);
   fChain->SetBranchAddress("Tf", Tf, &b_Tf);
   fChain->SetBranchAddress("Tb", Tb, &b_Tb);
}

Bool_t h7::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

#endif // #ifdef h7_cxx
