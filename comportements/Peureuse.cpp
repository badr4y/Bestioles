#include "Peureuse.h"

#include <iostream>
#include <cmath>
#include <memory>

const double Peureuse::COEFFPEUR = 3. ;
const int Peureuse::DENSITEBESTIOLE = 5;


Peureuse::Peureuse() {
	std::cout << "Comportement peureuse créé" << std::endl;
}

Peureuse Peureuse::getPeureuse() {
	if ((peureuse)==nullptr)  {
		std::unique_ptr<Peureuse> peureuse(new Peureuse());
	}
	return (*peureuse);
}

int Peureuse::getDensiteBestioles(std::vector<Bestiole> const *bestioles) {
	return bestioles->size();
}

double Peureuse::getOrientationMoyenneVoisins(std::vector<Bestiole> const *bestioles) {
	double result = 0;
	if (bestioles->size() != 0) {
		for (size_t i = 0; i < bestioles->size(); ++i) {
			result+= bestioles[i].getOrientation();
	}
		while (result >= 2*M_PI) {
			result = result - 2*M_PI;
		}
		while (result <0) {
			result += 2*M_PI;
		}
		return result / bestioles->size();
	}
	else {
		return result;
	}
}

double Peureuse::getNouvelleDirection(const std::vector<Bestiole> *bestioles) {
	if (this->getDensiteBestioles(bestioles) >= this->DENSITEBESTIOLE) {
		return - this->getOrientationMoyenneVoisins(bestioles);
	} 
	else {
		return 0;
	}
}

/* méthode execute à implémenter */