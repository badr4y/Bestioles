#ifndef _NAGEOIRE_H_
#define _NAGEOIRE_H_

#include "Accessoire.h"

class Nageoire :public Accessoire {
private:
	static const double NU_MAX;

private:
	double nu;

public:
	Nageoire();

	bool isYeux();
	bool isCamouflage();
	bool isCarapace();
	bool isNageoire();
	bool isOreilles();

	double getNu();

};

#endif