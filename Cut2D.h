#include"Cut.h"

#ifndef CUT1D_H
#define CUT1D_H

class Cut2D : public Cut {
public:
	Cut2D(double left, double right, double top, double buttom, const char* name) {
		this->left = left;
		this->right = right;
		this->name = name;
		this->top = top;
		this->bottom = buttom;
	};
	bool Cut::IsInside(double constraint_x, double constraint_y) {
		
		bool re = constraint_x < right && constraint_x > left && constraint_y < top && constraint_y > bottom;
		//if(re) cout << constraint_x << " " << constraint_y << ":(" << left << "," << right << "),(" << top << "," << bottom << ") :" << re << endl;
		return re;
	}
private:
	double left;
	double right;
	double top;
	double bottom;
	const char* name;
};

#endif