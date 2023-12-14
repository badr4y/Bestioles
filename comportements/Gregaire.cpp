#include "Gregaire.h"
#include "Comportement.h"

#include <list>
#include <memory>
#include <iostream>
#include <cmath>

// Initialisation du pointeur 
Gregaire* Gregaire::gregaire=nullptr;
bool Gregaire::initialized = false;

Gregaire::Gregaire() {
    //std::cout << "Création du comportement Grégaire" << std::endl;
    initialized = true;
}

Gregaire* Gregaire::getGregaire (){
    // Méthode statique permettant d'accéder au singleton, 
    // En créant le comportement s'il n'existe pas encore
    if (!Gregaire::initialized) {
        gregaire = new Gregaire();
    }
    return Gregaire::gregaire;
}

double Gregaire::getOrientationMoyenneVoisins(const std::list<std::shared_ptr<Bestiole>>& bestioles) {
    double result = 0;
    if (!bestioles.empty()) {

        // Calcul de la somme des orientations
        for (const auto& ptr : bestioles) {
            result += ptr->getOrientation();
        }

        // On se place entre 0 et 2 PI
        while (result >= 2 * M_PI) {
            result = result - 2 * M_PI;
        }
        while (result < 0) {
            result += 2 * M_PI;
        }
        // On renvoie la moyenne de l'orientation
        return result / bestioles.size();
    }
    else {
        return result;
    }
}


void Gregaire::execute(Bestiole &bestiole, Milieu &milieu){
    // On modifie l'orientation pour que la bestiole adopte le comportement
    double direction = this->getOrientationMoyenneVoisins(bestiole.capteBestioles(milieu));
    if (direction == 0)
    {
        bestiole.setOrientation(bestiole.getOrientation());   
    }
    else
    {
        bestiole.setOrientation(direction);
    }
}


