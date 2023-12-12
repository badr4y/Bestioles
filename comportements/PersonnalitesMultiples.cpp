#include "PersonnalitesMultiples.h"

#include "Gregaire.h"
#include "Peureuse.h"
#include "Kamikaze.h"
#include "Prevoyante.h"
#include <iostream>
#include <stdlib.h>
#include <memory>

// Initialisation des proportions de chaque comportement
const double PersonnalitesMultiples::PROPORTIONGREGAIRE = 0.25 ;
const double PersonnalitesMultiples::PROPORTIONPEUREUSE = 0.5 ;
const double PersonnalitesMultiples::PROPORTIONKAMIKAZE = 0.75 ;
const double PersonnalitesMultiples::PROPORTIONPREVOYANTE = 1. ;

// Initialisation proportion de changer de comportement
const double PersonnalitesMultiples::CHGTCOMPORTEMENT = 0.01 ;


PersonnalitesMultiples::PersonnalitesMultiples() {
	std::cout << "Naissance d'une personnalité multiple" << std::endl;
}

void PersonnalitesMultiples::setComportement( Comportement* newComportement) {
	// Setter du comportement actuel
	this->currentComportement = newComportement;
}

Comportement* PersonnalitesMultiples::getComportement(){
	// Getter du comportement actuel
	return currentComportement;
}

void PersonnalitesMultiples::changeComportement() {
	// On calcule le nouveau comportement selon les probabilités
	double rand1 = (rand()%1000)/(1000.);
	if (rand1 <= PROPORTIONGREGAIRE) {
		this->setComportement(Gregaire::getGregaire());
	}
	else if ((PROPORTIONGREGAIRE < rand1) and (rand1<= PROPORTIONPEUREUSE)) {
		this->setComportement(Peureuse::getPeureuse());
	}
	else if ((PROPORTIONPEUREUSE < rand1) and (rand1 <= PROPORTIONKAMIKAZE)) {
		this->setComportement(Kamikaze::getKamikaze());
	}
	else if ((PROPORTIONKAMIKAZE < rand1) and (rand1<= PROPORTIONPREVOYANTE)) {
		this->setComportement(Prevoyante::getPrevoyante());
	}
}

void PersonnalitesMultiples::execute(Bestiole & bestiole, Milieu & milieu) {
	double rand1 = (rand()%1000)/(1000.);
	if (rand1 <= CHGTCOMPORTEMENT)  {
		this->changeComportement();
	}
	this->getComportement()->execute(bestiole,milieu);
}