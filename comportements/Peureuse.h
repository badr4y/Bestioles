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
	static std::unique_ptr<Peureuse> peureuse;

private :
	Peureuse();

public :
	static Peureuse getPeureuse();

public :
	int getDensiteBestioles(const std::vector<Bestiole>*);
	void execute(Bestiole *,Milieu *);
	double getOrientationMoyenneVoisins(const std::vector<Bestiole>*);
	double getNouvelleDirection(const std::vector<Bestiole>*);


};

#endif