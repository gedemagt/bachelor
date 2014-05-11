#include"Cut.h"

#ifndef CUT1D_H
#define CUT1D_H

class Cut1D : public Cut {
public:
	Cut1D(double left, double right, const char* name) {
		this->left = left;
		this->right = right;
		this->name = name;
	};

private:
	double left;
	double right;
	const char* name;
};

#endif