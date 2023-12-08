#ifndef _YEUX_H_
#define _YEUX_H_


#include "Capteur.h"


using namespace std;


class Yeux : public Capteur
{

private :

	static const double ALPHA_MIN;
	static const double ALPHA_MAX;
	static const double GAMMA_YEUX_MAX;
	static const double GAMMA_YEUX_MIN;
	static const double DELTA_YEUX_MAX;
	static const double DELTA_YEUX_MIN;
	double alpha;
	double delta;
	double gamma;

public :
	
	Yeux ();
	Yeux( const Yeux & y );

	bool isYeux() override;
	bool isOreilles() override;
	bool isNageoire() override;
	bool isCarapace() override;
	bool isCamouflage() override;

	double getAlpha() const;
	double getDelta() const;
	double getGamma() const;

};

#endif