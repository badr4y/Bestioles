#ifndef _PERSONNALITESMULTIPLES_H_
#define _PERSONNALITESMULTIPLES_H_

#include "Comportement.h"

#include <memory>

class PersonnalitesMultiples : public Comportement{

private :
	static const double PROPORTIONGREGAIRE;
	static const double PROPORTIONPEUREUSE;
	static const double PROPORTIONKAMIKAZE;
	static const double PROPORTIONPREVOYANTE;

private :
	Comportement* currentComportement;

public :
	PersonnalitesMultiples();
	void setComportement( Comportement * );
	void changeComportement();
	void execute();


};

#endif