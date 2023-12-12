#include "Peureuse.h"

#include <iostream>
#include <cmath>
#include <memory>

const double Peureuse::COEFFPEUR = 3. ;
const int Peureuse::DENSITEBESTIOLE = 5;

// Initialisation du pointeur
Peureuse* Peureuse::peureuse=nullptr;

Peureuse::Peureuse() {
	std::cout << "Comportement peureuse créé" << std::endl;
}

Peureuse* Peureuse::getPeureuse() {
	// Méthode statique permettant d'accéder au singleton, 
    // En créant le comportement s'il n'existe pas encore
	if ((peureuse)==nullptr)  {
		peureuse = new Peureuse();
	}
	return (peureuse);
}

int Peureuse::getDensiteBestioles(std::vector<Bestiole> const &bestioles) {
	// La densité est ici définie par le nombre de bestioles proches
	return bestioles.size();
}


double Peureuse::getNouvelleDirection(const std::vector<Bestiole> &bestioles, const Bestiole & bestiole) {
	double moyenneX = 0;
	double moyenneY = 0;
	double result = 0;
	// Calcul du barycentre des bestioles proches
	if (bestioles.size() != 0) {
		for (size_t i = 0; i < bestioles.size(); ++i) {
			moyenneX += bestioles[i].getCoordx();
			moyenneY += bestioles[i].getCoordy();
		}
		moyenneX = moyenneX/bestioles.size();
		moyenneY = moyenneY/bestioles.size();
		// Direction à adopter pour aller à l'opposé du barycentre
		result = (M_PI/2) - std::atan((moyenneX-bestiole.getCoordx())/(moyenneY -bestiole.getCoordy()));
	}
	else {
		result = bestiole.getOrientation();
	}	
	return result;


}

void Peureuse::execute(Bestiole & bestiole, Milieu & milieu)  {
	// On modifie l'orientation pour que la bestiole adopte le comportement
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

