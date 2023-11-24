#include "Yeux.h"
#include <stdlib.h> // rand()
#include <cmath>

const double Yeux::ALPHA_MIN = 0;
const double Yeux::ALPHA_MAX = M_PI;
const double Yeux::GAMMA_YEUX_MAX = 1.;
const double Yeux::GAMMA_YEUX_MIN = 0;
const double Yeux::DELTA_YEUX_MAX = 30.;
const double Yeux::DELTA_YEUX_MIN = 10.;

Yeux::Yeux(){
	double rand1 = (rand() % 1000)/1000;  // rand() entre 0 et RAND_MAX ; (rand() % 1000) entre 0 et 1000 ; (rand() % 1000)/1000 entre 0.000 et 1.000 
	double rand2 = (rand() % 1000)/1000;  // rand() entre 0 et RAND_MAX ; (rand() % 1000) entre 0 et 1000 ; (rand() % 1000)/1000 entre 0.000 et 1.000 
	double rand3 = (rand() % 1000)/1000;  // rand() entre 0 et RAND_MAX ; (rand() % 1000) entre 0 et 1000 ; (rand() % 1000)/1000 entre 0.000 et 1.000 
	//alpha = ALPHA_MIN + rand1*(ALPHA_MAX - ALPHA_MIN);
	//gamma = GAMMA_YEUX_MIN + rand2*(GAMMA_YEUX_MAX - GAMMA_YEUX_MIN);
	//delta = DELTA_YEUX_MIN + rand3*(DELTA_YEUX_MAX - DELTA_YEUX_MIN);
	alpha = 3.14;
	gamma = 1.;
	delta = 500.;
}

Yeux::Yeux( const Yeux & y )
{
	alpha = y.getAlpha();
    gamma = y.getGamma();
    delta = y.getDelta();
}

bool Yeux::isYeux(){return true;}
bool Yeux::isOreilles(){return false;}
bool Yeux::isNageoire(){return false;}
bool Yeux::isCarapace(){return false;}
bool Yeux::isCamouflage(){return false;}

double Yeux::getAlpha() const {return alpha;};
double Yeux::getDelta() const {return delta;};
double Yeux::getGamma() const {return gamma;};