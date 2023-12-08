#include "PersonnalitesMultiples.h"

#include "Gregaire.h"
#include "Peureuse.h"
#include "Kamikaze.h"
#include "Prevoyante.h"
#include <iostream>
#include <stdlib.h>
#include <memory>


const double PersonnalitesMultiples::PROPORTIONGREGAIRE = 0.25 ;
const double PersonnalitesMultiples::PROPORTIONPEUREUSE = 0.5 ;
const double PersonnalitesMultiples::PROPORTIONKAMIKAZE = 0.75 ;
const double PersonnalitesMultiples::PROPORTIONPREVOYANTE = 1. ;


PersonnalitesMultiples::PersonnalitesMultiples() {
	std::cout << "Naissance d'une personnalité multiple" << std::endl;
}

void PersonnalitesMultiples::setComportement( Comportement* newComportement) {
	this->currentComportement = newComportement;
}

void PersonnalitesMultiples::changeComportement() {
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

void PersonnalitesMultiples::execute() {

}