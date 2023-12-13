#include "Prevoyante.h"
#include "../Bestiole.h"
#include "../Milieu.h"

Prevoyante* Prevoyante::prevoyante = nullptr;
bool Prevoyante::initialized = false;

Prevoyante::Prevoyante() {
    initialized = true;
}

Prevoyante* Prevoyante::getPrevoyante() {
    if (!Prevoyante::prevoyante)
        prevoyante = new Prevoyante();
    return Prevoyante::prevoyante;
}


Bestiole Prevoyante::bestiolePlusProche(const Bestiole& bestiole, const std::list<Bestiole>& listeBestioles) {
    //le cas où bestioles est vide est traite dans la methode execute()
    
        // Use an iterator to traverse the list
        auto it = listeBestioles.begin();
        Bestiole bestioleProche = *it;  // Initialize with the first element
        double distanceSquared = std::pow(bestiole.getCoordx() - bestioleProche.getCoordx(), 2) +
            std::pow(bestiole.getCoordy() - bestioleProche.getCoordy(), 2);

        ++it;  // Move to the second element
        while (it != listeBestioles.end()) {
            double currentDistanceSquared = std::pow(bestiole.getCoordx() - it->getCoordx(), 2) +
                std::pow(bestiole.getCoordy() - it->getCoordy(), 2);

            if (currentDistanceSquared < distanceSquared) {
                bestioleProche = *it;  // Update the closest bestiole
                distanceSquared = currentDistanceSquared;
            }

            ++it;  // Move to the next element
        }

        return bestioleProche;
    
}


double Prevoyante::calculNouvelleOrientation(const Bestiole& bestiole, const Bestiole& autreBestiole)  {

    double dx = autreBestiole.getCoordx()-bestiole.getCoordx();
    double dy = autreBestiole.getCoordy()-bestiole.getCoordy();
    double nouvelleOrientation = M_PI/2 - atan2(dx, dy);  // atan2(x, y) fait arctan(x/y)

    return nouvelleOrientation;
}


void Prevoyante::execute(Bestiole& bestiole, Milieu& milieu) {
    //une bestiole prevoyante ajuste sa trajectoire à celles des bestioles proches pour eviter les collisions
    std::list<Bestiole> bestiolesCaptees = bestiole.capteBestioles(milieu);
    if (!bestiolesCaptees.empty()) {
        Bestiole bestioleProche = bestiolePlusProche(bestiole, bestiolesCaptees);
        double nouvelleOrientation = calculNouvelleOrientation(bestiole, bestioleProche);
        bestiole.setOrientation(nouvelleOrientation);
    }
}