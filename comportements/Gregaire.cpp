#include "Gregaire.h"

#include <iostream>
#include <cmath>

Gregaire::Gregaire() {
    std::cout << "Création du comportement Grégaire" << std::endl;
}

Gregaire Gregaire::getGregaire (){
    if (gregaire ==null) {
        gregaire = new Gregaire();
    }
    return gregaire;
}

double Gregaire::getOrientationMoyenneVoisins() {
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

double Gregaire::getNouvelleOrientation() {
    return this.getOrientationMoyenneVoisins;
}

void Gregaire::execute(Bestiole b, Milieu m){

}

Gregaire::~Gregaire() {
    
}
