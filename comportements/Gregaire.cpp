#include "Gregaire.h"
#include "Comportement.h"

#include <memory>
#include <iostream>
#include <cmath>

Gregaire::Gregaire() {
    std::cout << "Création du comportement Grégaire" << std::endl;
}

Gregaire* Gregaire::getGregaire (){
    if (gregaire == nullptr) {
        gregaire = new Gregaire();
    }
    return (gregaire);
}

double Gregaire::getOrientationMoyenneVoisins(std::vector<Bestiole> const & bestioles) {
    double result = 0;
    if (bestioles.size() != 0) {
        for (size_t i = 0; i < bestioles.size(); ++i) {
            result+= bestioles[i].getOrientation();
    }
        while (result >= 2*M_PI) {
            result = result - 2*M_PI;
        }
        while (result <0) {
            result += 2*M_PI;
        }
        return result / bestioles.size();
    }
    else {
        return result;
    }
}

double Gregaire::getNouvelleOrientation(std::vector<Bestiole> const &bestioles, const Bestiole&) {
    return this->getOrientationMoyenneVoisins(bestioles);
}

void Gregaire::execute(Bestiole &bestiole, Milieu &milieu){
    double direction = this->getNouvelleOrientation(bestiole.capteBestioles(milieu), bestiole);
    bestiole.setOrientation(direction);
}


