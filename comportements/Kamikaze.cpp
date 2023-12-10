#include "Kamikaze.h"
#include "../Bestiole.h"
#include "../Milieu.h"

#include <limits>


// initialisation du singleton kamikaze
//pointeur statique ==> unique ==> sûr 
// evite problemes de concurrences d'environnement multithreadés
Kamikaze* Kamikaze::kamikaze = nullptr;

Kamikaze::Kamikaze() {}

Kamikaze* Kamikaze::getKamikaze() {
    if (kamikaze == nullptr )
        kamikaze = new Kamikaze();
    return kamikaze;
    }

Bestiole& Kamikaze::getPlusProche(Bestiole & b, const Milieu & milieu) {
    std::vector<Bestiole> listeBestioles = b.capteBestioles(milieu);

    if (listeBestioles.empty()) {
        return b;  
    }

    double distanceMin = std::numeric_limits<double>::max();
    Bestiole &plusProche = listeBestioles.front();

    for (const auto& autreBestiole : listeBestioles) {
        // calculer la distance entre b et chaque autre bestiole
        double distance = std::sqrt(std::pow(b.getCoordx() - autreBestiole.getCoordx(), 2) +
                                    std::pow(b.getCoordy() - autreBestiole.getCoordy(), 2));

        // mettre à jour la bestiole la plus proche si la distance est plus petite
        if (distance < distanceMin) {
            distanceMin = distance;
            plusProche = autreBestiole;
        }
    }
    return plusProche;
}



void Kamikaze::execute(Bestiole & bestiole,const Milieu & milieu) {
    // Obtenir la bestiole la plus proche
    Bestiole proie = getPlusProche(bestiole,milieu);

    // Logique de déplacement de la bestiole kamikaze vers sa proie
    double dx = cos(bestiole.getOrientation()) * bestiole.getVitesse();
    double dy = -sin(bestiole.getOrientation()) * bestiole.getVitesse();

    int cx = static_cast<int>(bestiole.getCumulX());
    bestiole.setCumulX(bestiole.getCumulX() - cx);

    int cy = static_cast<int>(bestiole.getCumulY());
    bestiole.setCumulY(bestiole.getCumulY() - cy);

    double nx = bestiole.getCoordx() + dx + cx;
    double ny = bestiole.getCoordy() + dy + cy;

    // Vérifier les collisions
    /*
    for (const Bestiole& autreBestiole : milieu.getListeBestioles()) {
    if (&bestiole != &autreBestiole) { // Éviter de comparer une bestiole avec elle-même
        double distance = std::sqrt(std::pow(nx - autreBestiole.getCoordx(), 2) +
                                    std::pow(ny - autreBestiole.getCoordy(), 2));

        // Vérifier si une collision a eu lieu
        if (distance < bestiole.getRayon() + autreBestiole.getRayon()) {
            // Simuler la collision
            if (rand() % 2 == 0) {
                // La bestiole meurt avec une probabilité de 50%
                bestiole.~Bestiole();
            } else {
                // La bestiole rebondit dans la direction opposée
                bestiole.setOrientation(M_PI + bestiole.getOrientation());
                bestiole.setCumulX(0.0);
                bestiole.setCumulY(0.0);
            }
        }
    }
    */


    // Mettre à jour la position si aucune collision n'a eu lieu
    /*
    if ((nx < 0 ) || (nx > milieu.getXLim() - 1)) {
        bestiole.setOrientation(M_PI - bestiole.getOrientation());
        bestiole.setCumulX(0.0);
    } else {
        bestiole.setCoordx(static_cast<int>(nx));
        bestiole.setCumulX(bestiole.getCumulX() + nx - bestiole.getCoordx());
    }

    if ((ny < 0) || (ny > milieu.getYLim() - 1)) {
        bestiole.setOrientation(-bestiole.getOrientation());
        bestiole.setCumulY(0.0);
    } else {
        bestiole.setCoordy(static_cast<int>(ny));
        bestiole.setCumulY(bestiole.getCumulY() + ny - bestiole.getCoordy());
    }
    */
}


