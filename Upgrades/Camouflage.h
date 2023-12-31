#ifndef _CAMOUFLAGE_H_
#define _CAMOUFLAGE_H_

#include "Accessoire.h"

class Camouflage :public Accessoire {
private:
	static const double PSI_MIN;
	static const double PSI_MAX;

private:
	double psi;

public:
	Camouflage();

	bool isYeux();
	bool isCamouflage();
	bool isCarapace();
	bool isNageoire();
	bool isOreilles();

	double getPsi();
};

#endif