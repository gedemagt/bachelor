#include "Cut.h"
#include "TCutG.h"

#ifndef ROOTTCUT_H
#define ROOTTCUT_H

class RootTCut : public Cut {
public:
	RootTCut(TCutG* cut) { this->cut = cut; };
	~RootTCut() { delete cut; }
	bool Cut::IsInside(double x, double y) { return cut->IsInside(x, y); };

private:
	TCutG* cut;
};
#endif