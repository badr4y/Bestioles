#ifndef _OREILLES_H_
#define _OREILLES_H_


#include "Capteur.h"

#include <cstdlib>
#include <cmath>

using namespace std;


class Oreilles : public Capteur
{

private :

	static const double GAMMA_OREILLES_MAX;
	static const double GAMMA_OREILLES_MIN;
	static const double DELTA_OREILLES_MAX;
	static const double DELTA_OREILLES_MIN;
	double delta;
	double gamma;

public :
	
	Oreilles ();
	Oreilles( const Oreilles & o );

	bool isYeux() override;
	bool isOreilles() override;
	bool isNageoire() override;
	bool isCarapace() override;
	bool isCamouflage() override;

	double getDelta() const;
	double getGamma() const;

};

#endif