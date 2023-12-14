#include "Peureuse.h"

#include <iostream>
#include <cmath>
#include <memory>

const double Peureuse::COEFFPEUR = 3. ;
const int Peureuse::DENSITEBESTIOLE = 2;

// Initialisation du pointeur
Peureuse* Peureuse::peureuse=nullptr;
bool Peureuse::initialized = false;

Peureuse::Peureuse() {
	//std::cout << "Comportement peureuse créé" << std::endl;
}

Peureuse* Peureuse::getPeureuse() {
	// Méthode statique permettant d'accéder au singleton, 
    // En créant le comportement s'il n'existe pas encore
	if (!Peureuse::initialized)  {
		peureuse = new Peureuse();
	}
	return Peureuse::peureuse;
}

int Peureuse::getDensiteBestioles(std::list<std::shared_ptr<Bestiole>> const &bestioles) {
	// La densité est ici définie par le nombre de bestioles proches
	return bestioles.size();
}


double Peureuse::getNouvelleDirection(const std::list<std::shared_ptr<Bestiole>> &bestioles, const Bestiole & bestiole) {
	double moyenneX = 0;
	double moyenneY = 0;

	// Calcul du barycentre des bestioles proches
	double nouvelleOrientation;
	if (bestioles.size() != 0) {
		for (const auto& ptr : bestioles) {
			moyenneX += ptr->getCoordx();
			moyenneY += ptr->getCoordy();
		}
		moyenneX = moyenneX/bestioles.size();
		moyenneY = moyenneY/bestioles.size();
		// Direction à adopter pour aller à l'opposé du barycentre

		double dx = moyenneX-bestiole.getCoordx();
	    double dy = moyenneY-bestiole.getCoordy();
	    if (dy>0){
	        nouvelleOrientation= M_PI/2 - atan2(dx, dy);  // atan2(x, y) fait arctan(x/y)
	    } else if (dy<0){
	        nouvelleOrientation = M_PI/2 + atan2(dx, dy);  
	    } else{
	        if(dx>0){nouvelleOrientation = 0;}
	        else if(dx<0){nouvelleOrientation = M_PI;}
	    }
	}
	else {
		nouvelleOrientation = bestiole.getOrientation();
	}	
	return nouvelleOrientation;

}

void Peureuse::execute(Bestiole & bestiole, Milieu & milieu)  {
	// On modifie l'orientation pour que la bestiole adopte le comportement
	std::list<std::shared_ptr<Bestiole>> liste = bestiole.capteBestioles(milieu);
	double direction = this->getNouvelleDirection(liste,bestiole);
	if (this->getDensiteBestioles(liste)>= DENSITEBESTIOLE) {
		bestiole.setOrientation(direction);
		bestiole.setCurrentVitesse(bestiole.getVitesse() * COEFFPEUR);
	}
	else {
		bestiole.setCurrentVitesse(bestiole.getVitesse());
}


}

