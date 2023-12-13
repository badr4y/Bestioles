#include "Peureuse.h"

#include <iostream>
#include <cmath>
#include <memory>

const double Peureuse::COEFFPEUR = 3. ;
const int Peureuse::DENSITEBESTIOLE = 5;

// Initialisation du pointeur
Peureuse* Peureuse::peureuse=nullptr;
bool Peureuse::initialized = false;

Peureuse::Peureuse() {
	std::cout << "Comportement peureuse créé" << std::endl;
}

Peureuse* Peureuse::getPeureuse() {
	// Méthode statique permettant d'accéder au singleton, 
    // En créant le comportement s'il n'existe pas encore
	if (!Peureuse::initialized)  {
		peureuse = new Peureuse();
	}
	return Peureuse::peureuse;
}

int Peureuse::getDensiteBestioles(std::list<Bestiole> const &bestioles) {
	// La densité est ici définie par le nombre de bestioles proches
	return bestioles.size();
}


double Peureuse::getNouvelleDirection(const std::list<Bestiole> &bestioles, const Bestiole & bestiole) {
	double moyenneX = 0;
	double moyenneY = 0;
	double result = 0;
	// Calcul du barycentre des bestioles proches
	if (bestioles.size() != 0) {
		for (const Bestiole& b : bestioles) {
			moyenneX += b.getCoordx();
			moyenneY += b.getCoordy();
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
	std::list<Bestiole> liste = bestiole.capteBestioles(milieu);
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

