#ifndef _CAPTEUR_H_
#define _CAPTEUR_H_


#include "Upgrade.h"
#include "../Bestiole.h"

using namespace std;


class Capteur : virtual public Upgrade
{

private :

public :

	bool virtual isYeux( void ) override =0;
	bool virtual isOreilles( void ) override =0;
	bool virtual isNageoire( void ) override =0;
	bool virtual isCarapace( void ) override =0;
    bool virtual isCamouflage( void ) override =0;
	
	bool capte(const Bestiole& bestiole, int x, int y, double orientation);

};

#endif