#ifndef _PERSONNALITESMULTIPLES_H_
#define _PERSONNALITESMULTIPLES_H_

#include "Comportement.h"
#include "../Bestiole.h"
#include "../Milieu.h"

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
	Comportement* getComportement();
	void changeComportement();
	void execute(Bestiole &, Milieu &);


};

#endif