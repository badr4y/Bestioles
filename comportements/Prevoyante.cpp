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


Bestiole Prevoyante::bestiolePlusProche(const Bestiole& bestiole, const std::vector<Bestiole>& listeBestioles) {
    //le cas où bestioles est vide est traite dans la methode execute()
    
    Bestiole bestioleProche = listeBestioles[0];
    double distanceSquared = std::pow(bestiole.getCoordx() - bestioleProche.getCoordx(), 2) +
                             std::pow(bestiole.getCoordy() - bestioleProche.getCoordy(), 2);

    for (size_t i = 1; i < listeBestioles.size(); ++i) {
        double currentDistanceSquared = std::pow(bestiole.getCoordx() - listeBestioles[i].getCoordx(), 2) +
                                        std::pow(bestiole.getCoordy() - listeBestioles[i].getCoordy(), 2);

        if (currentDistanceSquared < distanceSquared) {
            bestioleProche = listeBestioles[i];
            distanceSquared = currentDistanceSquared;
        }
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
    std::vector<Bestiole> bestiolesCaptees = bestiole.capteBestioles(milieu);
    if (!bestiolesCaptees.empty()) {
        Bestiole bestioleProche = bestiolePlusProche(bestiole, bestiolesCaptees);
        double nouvelleOrientation = calculNouvelleOrientation(bestiole, bestioleProche);
        bestiole.setOrientation(nouvelleOrientation);
    }
}