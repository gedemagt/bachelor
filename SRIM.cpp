#include "SRIMM.h"
#include "TFile.h"

void srim() {
	SRIMM *ss = new SRIMM();
	ss->SetPathName("");
	ss->Creategraphs();
	TFile f("SRIM.root", "recreate");
	f.Write();
	f.WriteTObject((ss->Energy[3][3]));
}