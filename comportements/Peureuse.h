#ifndef _PEUREUSE_H_
#define _PEUREUSE_H_


#include <iostream>
#include <memory>

#include "Comportement.h"
#include "../Bestiole.h"
#include "../Milieu.h"

class Peureuse : public Comportement{

private :
	static const double COEFFPEUR;
	static const int DENSITEBESTIOLE;

private :
	static Peureuse* peureuse;
	static bool initialized;
	Peureuse();

public :
	static Peureuse* getPeureuse();
	int getDensiteBestioles(const std::list<Bestiole>&);
	void execute(Bestiole &,Milieu &);
	double getNouvelleDirection(const std::list<Bestiole>&, const Bestiole&);


};


#endif