#include "Peureuse.h"

#include <iostream>
#include <cmath>
#include <memory>

const double Peureuse::COEFFPEUR = 3. ;
const int Peureuse::DENSITEBESTIOLE = 5;


Peureuse::Peureuse() {
	std::cout << "Comportement peureuse créé" << std::endl;
}

Peureuse* Peureuse::getPeureuse() {
	if ((peureuse)==nullptr)  {
		peureuse = new Peureuse();
	}
	return (peureuse);
}

int Peureuse::getDensiteBestioles(std::vector<Bestiole> const &bestioles) {
	return bestioles.size();
}


double Peureuse::getNouvelleDirection(const std::vector<Bestiole> &bestioles, const Bestiole & bestiole) {
	double moyenneX = 0;
	double moyenneY = 0;
	double result = 0;
	if (bestioles.size() != 0) {
		for (size_t i = 0; i < bestioles.size(); ++i) {
			moyenneX += bestioles[i].getCoordx();
			moyenneY += bestioles[i].getCoordy();
		}
		moyenneX = moyenneX/bestioles.size();
		moyenneY = moyenneY/bestioles.size();
		result = (M_PI/2) - std::atan((moyenneX-bestiole.getCoordx())/(moyenneY -bestiole.getCoordy()));
	}
	else {
		result = bestiole.getOrientation();
	}	
	return result;


}

void Peureuse::execute(Bestiole & bestiole, Milieu & milieu)  {
	std::vector<Bestiole> liste = bestiole.capteBestioles(milieu);
	double direction = this->getNouvelleDirection(liste,bestiole);
	if (this->getDensiteBestioles(liste)>= DENSITEBESTIOLE) {
		bestiole.setOrientation(direction);
		bestiole.setCurrentVitesse(bestiole.getVitesse() * COEFFPEUR);
	}
	else {
		bestiole.setOrientation(direction);
		bestiole.setCurrentVitesse(bestiole.getVitesse());
}


}

