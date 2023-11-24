#include "Peureuse.h"

#include <iostream>
#include <cmath>

const double Peureuse::COEFFPEUR = 3. ;
const int Peureuse::DENSITEBESTIOLE = 5;


Peureuse::Peureuse() {
	std::cout << "Comportement peureuse créé" << std::endl;
}

Peureuse Peureuse::getPeureuse() {
	std::cout << "Voici le comportement peureuse" <<std::endl;
	if (peureuse==null)  {
		peureuse = new Peureuse();
	}
	return peureuse;
}

int Peureuse::getDensiteBestioles(std::vector<Bestiole> * bestioles) {
	return bestioles.size();
}

double Peureuse::getOrientationMoyenne(std::vector<Bestiole> * bestioles) {
	double result = 0;
	if (bestioles.size() != 0) {
		for (size_t i = 0; i < bestioles.size(); ++i) {
			result+= bestioles[i].getOrientation();
}
		result = result%(2*M_PI);
		return result/bestioles.size();
	}
	else {
		return result
	}
}

double Peureuse::getNouvelleDirection(std::vector<Bestiole> *bestioles) {
	if (this.getDensiteBestioles >= this.DENSITEBESTIOLE) {
		return - this.getOrientationMoyenne;
	} 
	else {
		return 0;
	}
}

/* méthode execute à implémenter */