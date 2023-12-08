#include "Prevoyante.h"
#include "../Bestiole.h"
#include "../Milieu.h"

Prevoyante* Prevoyante::prevoyante = nullptr;

Prevoyante::Prevoyante() {}

Prevoyante* Prevoyante::getPrevoyante() {
    if (prevoyante == nullptr )
        prevoyante = new Prevoyante();
    return prevoyante;
    }

double Prevoyante::estimeTrajectoire(const Bestiole& bestiole, const Bestiole& autreBestiole)  {
    // distance relative 
    double dx = autreBestiole.getX() - bestiole.getX();
    double dy = autreBestiole.getY() - bestiole.getY();

    double distance = std::sqrt(dx * dx + dy * dy);
    return distance;

    // Direction relative (angle par rapport à l'axe x)
    //double angle = std::atan2(dy, dx);
    //return distance * std::cos(angle - bestiole.getOrientation());
}




double Prevoyante::calculNouvelleDirection(const Bestiole& bestiole, const Milieu& milieu)  {
    // Initialisation de la somme des directions relatives et du nombre de bestioles prises en compte
    double sommeDirections = 0.0;
    int count = 0;

    // Parcourir les bestioles dans le milieu
    for (const Bestiole& autreBestiole : milieu.getListeBestioles()) { //pourquoi parcourir toutes les bestioles ?
        if (&bestiole != &autreBestiole) { // Éviter de comparer une bestiole avec elle-même
            // Estimer la trajectoire de l'autre bestiole par rapport à la bestiole prévoyante
            double trajectoire = estimeTrajectoire(bestiole, autreBestiole);
            sommeDirections += trajectoire;
            count++;
        }
    }

    // Calcul de la nouvelle direction moyenne basée sur les trajectoires estimées
    double nouvelleDirection = (count > 0) ? sommeDirections / count : 0.0;

    return nouvelleDirection;
}

void Prevoyante::execute(const Bestiole& bestiole, const Milieu& milieu) {
    double nouvelleDirection = calculNouvelleDirection(bestiole, milieu);
    bestiole.ajusterTrajectoire(nouvelleDirection);
}

