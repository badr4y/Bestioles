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


Bestiole Prevoyante::bestiolePlusProche(const std::vector<Bestiole>& bestioles) {
    //le cas où bestioles est vide est traite dans la methode execute()
    Bestiole bestioleProche = bestioles[0];

    double distanceSquared = std::pow(bestioleProche.getCoordx() - bestioles[0].getCoordx(), 2) +
                             std::pow(bestioleProche.getCoordy() - bestioles[0].getCoordy(), 2);

    for (size_t i = 1; i < bestioles.size(); ++i) {
        double currentDistanceSquared = std::pow(bestioleProche.getCoordx() - bestioles[i].getCoordx(), 2) +
                                        std::pow(bestioleProche.getCoordy() - bestioles[i].getCoordy(), 2);

        if (currentDistanceSquared < distanceSquared) {
            bestioleProche = bestioles[i];
            distanceSquared = currentDistanceSquared;
        }
    }
    
    return bestioleProche;
}


double Prevoyante::calculNouvelleOrientation(const Bestiole& bestiole, const Bestiole& autreBestiole)  {
    // Initialisation de la somme des directions relatives et du nombre de bestioles prises en compte
    double dx = autreBestiole.getCoordx()-bestiole.getCoordx();
    double dy = autreBestiole.getCoordy()-bestiole.getCoordy();
    double nouvelleOrientation = M_PI/2 - atan2(dx, dy);  // atan2(x, y) fait arctan(x/y)

    return nouvelleOrientation;
}


void Prevoyante::execute(Bestiole& bestiole, const Milieu& milieu) {

    std::vector<Bestiole> bestiolesCaptees = bestiole.capteBestioles(milieu);
    if (!bestiolesCaptees.empty()) {
        Bestiole bestioleProche = bestiolePlusProche(bestiolesCaptees);
        double nouvelleOrientation = calculNouvelleOrientation(bestiole, bestioleProche);
        bestiole.setOrientation(nouvelleOrientation);
    }
}