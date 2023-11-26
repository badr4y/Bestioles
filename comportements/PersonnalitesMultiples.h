#ifndef _PERSONNALITESMULTIPLES_H_
#define _PERSONNALITESMULTIPLES_H_

#include "Comportement.h"

class PersonnalitesMultiples : public Comportement{

private :
	static const double PROPORTIONGREGAIRE;
	static const double PROPORTIONPEUREUSE;
	static const double PROPORTIONKAMIKAZE;
	static const double PROPORTIONPREVOYANTE;

private :
	Comportement currentComportement;

public :
	PersonnalitesMultiples();
	void setComportement(const * newComportement);
	void changeComportement();
	void execute();


};

#endif