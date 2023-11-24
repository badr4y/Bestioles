#ifndef _CARAPACE_H_
#define _CARAPACE_H_

#include "Accessoire.h"

class Carapace :public Accessoire {
private:
	static const double OMEGA_MAX;
	static const double ETA_MAX;

private:
	double omega;
	double eta;

public:
	Carapace();

	bool isYeux();
	bool isCamouflage();
	bool isCarapace();
	bool isNageoire();
	bool isOreille();
};

#endif