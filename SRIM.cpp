#include "SRIMclass.h"
#include "TFile.h"

void srim() {
	SRIM *ss = new SRIM();
	ss->SetPathName("");
	ss->Creategraphs();
	TFile f("SRIM.root", "recreate");
	f.Write();
	f.WriteTObject((ss->Energy[3][3]));
}