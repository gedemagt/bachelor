
#ifndef CUT_H
#define CUT_H

class Cut {
public:
	virtual bool IsInside(double constraint_x, double constraint_y) = 0;

};
#endif