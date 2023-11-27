#include "PersonnalitesMultiples.h"

#include <Gregaire.h>
#include <Peureuse.h>
#include <Kamikaze.h>
#include <Prevoyante.h>
#include <iostream>
#include <stdlib.h>

const double PersonnalitesMultiples::PROPORTIONGREGAIRE = 0.25 ;
const double PersonnalitesMultiples::PROPORTIONPEUREUSE = 0.25 ;
const double PersonnalitesMultiples::PROPORTIONKAMIKAZE = 0.25 ;
const double PersonnalitesMultiples::PROPORTIONPREVOYANTE = 0.25 ;

PersonnalitesMultiples::PersonnalitesMultiples() {
	std::cout << "Naissance d'une personnalité multiple" << std::endl;
}

void PersonnalitesMultiples::setComportement(const * newComportement) {
	currentComportement = newComportement;
}

void PersonnalitesMultiples::changeComportement() {
	double rand1 = (rand()%1000)/1000;
	if (rand1 <= PROPORTIONGREGAIRE) {
		this.setComportement(Gregaire);
	}
	else if (PROPORTIONGREGAIRE < rand1 <= PROPORTIONPEUREUSE) {
		this.setComportement(Peureuse);
	}
	else if (PROPORTIONPEUREUSE < rand1 <= PROPORTIONKAMIKAZE) {
		this.setComportement(Kamikaze);
	}
	else if (PROPORTIONKAMIKAZE < rand1 <= PROPORTIONPREVOYANTE) {
		this.setComportement(Prevoyante);
	}
}

void PersonnalitesMultiples::execute() {

}