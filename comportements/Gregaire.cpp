#include "Gregaire.h"
#include "Comportement.h"

#include <memory>
#include <iostream>
#include <cmath>

// Initialisation du pointeur 
Gregaire* Gregaire::gregaire=nullptr;

Gregaire::Gregaire() {
    std::cout << "Création du comportement Grégaire" << std::endl;
}

Gregaire* Gregaire::getGregaire (){
    // Méthode statique permettant d'accéder au singleton, 
    // En créant le comportement s'il n'existe pas encore
    if (gregaire == nullptr) {
        gregaire = new Gregaire();
    }
    return (gregaire);
}

double Gregaire::getOrientationMoyenneVoisins(std::vector<Bestiole> const & bestioles) {
    double result = 0;
    if (bestioles.size() != 0) {
        // Calcul de la somme des orientations
        for (size_t i = 0; i < bestioles.size(); ++i) {
            result+= bestioles[i].getOrientation();
    }
        // On se place entre 0 et 2 PI
        while (result >= 2*M_PI) {
            result = result - 2*M_PI;
        }
        while (result <0) {
            result += 2*M_PI;
        }
        // On renvoie la moyenne de l'orientation
        return result / bestioles.size();
    }
    else {
        return result;
    }
}

double Gregaire::getNouvelleOrientation(std::vector<Bestiole> const &bestioles, const Bestiole&) {
    // La bestiole suit l'orientation moyenne des bestioles proches
    return this->getOrientationMoyenneVoisins(bestioles);
}

void Gregaire::execute(Bestiole &bestiole, Milieu &milieu){
    // On modifie l'orientation pour que la bestiole adopte le comportement
    double direction = this->getNouvelleOrientation(bestiole.capteBestioles(milieu), bestiole);
    bestiole.setOrientation(direction);
}


