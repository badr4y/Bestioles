#include "Kamikaze.h"
#include "../Bestiole.h"
#include "../Milieu.h"


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

Bestiole Kamikaze::getPlusProche(Bestiole b) {
    std::vector<Bestiole> listeBestioles = b.capteBestioles();

    if (listeBestioles.empty()) {
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



void Kamikaze::execute(Bestiole& bestiole, Milieu& milieu) {
    // Obtenir la bestiole la plus proche
    Bestiole proie = getPlusProche(bestiole);

    // Logique de déplacement de la bestiole kamikaze vers sa proie
    double dx = cos(bestiole.getOrientation()) * bestiole.getVitesse();
    double dy = -sin(bestiole.getOrientation()) * bestiole.getVitesse();

    int cx = static_cast<int>(bestiole.getCumulX());
    bestiole.setCumulX(bestiole.getCumulX() - cx);

    int cy = static_cast<int>(bestiole.getCumulY());
    bestiole.setCumulY(bestiole.getCumulY() - cy);

    double nx = bestiole.getX() + dx + cx;
    double ny = bestiole.getY() + dy + cy;

    // Vérifier les collisions
    for (const Bestiole& autreBestiole : milieu.getListeBestioles()) {
    if (&bestiole != &autreBestiole) { // Éviter de comparer une bestiole avec elle-même
        double distance = std::sqrt(std::pow(nx - autreBestiole.getX(), 2) +
                                    std::pow(ny - autreBestiole.getY(), 2));

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


    // Mettre à jour la position si aucune collision n'a eu lieu
    if (nx < 0 || nx > milieu.getXLim() - 1) {
        bestiole.setOrientation(M_PI - bestiole.getOrientation());
        bestiole.setCumulX(0.0);
    } else {
        bestiole.setX(static_cast<int>(nx));
        bestiole.setCumulX(bestiole.getCumulX() + nx - bestiole.getX());
    }

    if (ny < 0 || ny > milieu.getYLim() - 1) {
        bestiole.setOrientation(-bestiole.getOrientation());
        bestiole.setCumulY(0.0);
    } else {
        bestiole.setY(static_cast<int>(ny));
        bestiole.setCumulY(bestiole.getCumulY() + ny - bestiole.getY());
    }
}

Kamikaze::~Kamikaze() {
    delete kamikaze;
}
