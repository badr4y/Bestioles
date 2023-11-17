#include "kamikaze.h"
#include "Bestiole.h"
#include "Milieu.h"

Kamikaze::Kamikaze() {

}

Kamikaze Kamikaze::getKamikaze() {
    if (kamikaze == null)
        kamikaze = new Kamikaze()
    return kamikaze;
    }

Bestiole Kamikaze::getPlusProche(Bestiole b) {
    std::vector<Bestiole> listBestioles = b.capteBestioles();

    if (listBestioles.empty()) {
        return Bestiole();  
    }

    double distanceMin = std::numeric_limits<double>::max();
    Bestiole plusProche;

    for (const auto& autreBestiole : listeBestioles) {
        // calculer la distance entre b et chaque autre bestiole
        double distance = std::sqrt(std::pow(b.getCoord()[0] - autreBestiole.getCoord()[0], 2) +
                                    std::pow(b.getCoord()[0] - autreBestiole.getCoord()[0], 2));

        // mettre à jour la bestiole la plus proche si la distance est plus petite
        if (distance < distanceMin) {
            distanceMin = distance;
            plusProche = autreBestiole;
        }
    }
    return plusProche;
}

void Kamikaze::execute(Bestiole bestiole, Milieu milieu) {
    plusP
}

Kamikaze::~Kamikaze() {

}
