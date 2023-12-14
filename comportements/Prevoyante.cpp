#include "Prevoyante.h"
#include "../Bestiole.h"
#include "../Milieu.h"

Prevoyante* Prevoyante::prevoyante = nullptr;
bool Prevoyante::initialized = false;

Prevoyante::Prevoyante() {
    initialized = true;
}

Prevoyante* Prevoyante::getPrevoyante() {
    // Méthode statique permettant d'accéder au singleton, 
    // En créant le comportement s'il n'existe pas encore
    if (!Prevoyante::prevoyante)
        prevoyante = new Prevoyante();
    return Prevoyante::prevoyante;
}


std::shared_ptr<Bestiole> Prevoyante::bestiolePlusProche(const Bestiole& bestiole, const std::list<std::shared_ptr<Bestiole>>& listeBestioles) {
    //le cas où bestioles est vide est traite dans la methode execute()
        
        double currentDistanceSquared;
        double distanceSquared = 10000000000;
        std::shared_ptr<Bestiole> bestioleProchePtr = nullptr;
        for (const auto& ptr : listeBestioles) {
            currentDistanceSquared = std::pow(bestiole.getCoordx() - ptr->getCoordx(), 2) +
                std::pow(bestiole.getCoordy() - ptr->getCoordy(), 2);

            if (currentDistanceSquared < distanceSquared) {
                bestioleProchePtr = ptr;  // Update the closest bestiole
                distanceSquared = currentDistanceSquared;
            }

        }

        return bestioleProchePtr;
    
}


double Prevoyante::calculNouvelleOrientation(const Bestiole& bestiole, const std::shared_ptr<Bestiole> autreBestiole)  {

    double dx = autreBestiole->getCoordx()-bestiole.getCoordx();
    double dy = autreBestiole->getCoordy()-bestiole.getCoordy();
    double nouvelleOrientation = M_PI/2 - atan2(dx, dy);  // atan2(x, y) fait arctan(x/y)

    return nouvelleOrientation;
}


void Prevoyante::execute(Bestiole& bestiole, Milieu& milieu) {
    //une bestiole prevoyante ajuste sa trajectoire à celles des bestioles proches pour eviter les collisions
    std::list<std::shared_ptr<Bestiole>> bestiolesCaptees = bestiole.capteBestioles(milieu);
    if (!bestiolesCaptees.empty()) {
        std::shared_ptr<Bestiole> bestioleProchePtr = bestiolePlusProche(bestiole, bestiolesCaptees);
        double nouvelleOrientation = calculNouvelleOrientation(bestiole, bestioleProchePtr);
        bestiole.setOrientation(nouvelleOrientation);
    }
}