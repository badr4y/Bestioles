#ifndef _PEUREUSE_H_
#define _PEUREUSE_H_


#include <iostream>

#include "Comportement.h"
#include "Bestiole.h"
#include "Milieu.h"

class Peureuse : public Comportement{

private :
	static const double COEFFPEUR;
	static const int DENSITEBESTIOLE;

private :
	Peureuse *peureuse;

private :
	Peureuse();

public :
	static Peureuse getPeureuse();

public :
	int getDensiteBestioles(std::vector<Bestiole>);
	void execute(Bestiole,Milieu);
	double getOrientationMoyenne(std::vector<Bestiole>);
	std::pair<int, int> getDirectionMoyenne(std::vector<Bestiole);


}

#endif