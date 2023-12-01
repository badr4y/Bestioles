#include "Oreilles.h"
#include <stdlib.h> // rand()

#include <cstdlib>
#include <cmath>

const double Oreilles::GAMMA_OREILLES_MAX = 1.;
const double Oreilles::GAMMA_OREILLES_MIN = 0.5;
const double Oreilles::DELTA_OREILLES_MAX = 60.;
const double Oreilles::DELTA_OREILLES_MIN = 10.;

Oreilles::Oreilles(){
	double rand1 = (rand() % 1000)/1000.;  // rand() entre 0 et RAND_MAX ; (rand() % 1000) entre 0 et 1000 ; (rand() % 1000)/1000 entre 0.000 et 1.000 
	double rand2 = (rand() % 1000)/1000.;  // rand() entre 0 et RAND_MAX ; (rand() % 1000) entre 0 et 1000 ; (rand() % 1000)/1000 entre 0.000 et 1.000 
	gamma = GAMMA_OREILLES_MIN + rand1*(GAMMA_OREILLES_MAX - GAMMA_OREILLES_MIN);
	delta = DELTA_OREILLES_MIN + rand2*(DELTA_OREILLES_MAX - DELTA_OREILLES_MIN);
	//gamma = 1.;
	//delta = 100.;
}

Oreilles::Oreilles( const Oreilles & o )
{
    gamma = o.getGamma();
    delta = o.getDelta();
}

bool Oreilles::isYeux(){return false;}
bool Oreilles::isOreilles(){return true;}
bool Oreilles::isNageoire(){return false;}
bool Oreilles::isCarapace(){return false;}
bool Oreilles::isCamouflage(){return false;}

double Oreilles::getDelta() const {return delta;};
double Oreilles::getGamma() const {return gamma;};