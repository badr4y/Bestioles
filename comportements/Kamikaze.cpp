#include "Kamikaze.h"
#include "../Bestiole.h"
#include "../Milieu.h"

#include <limits>


// initialisation du singleton kamikaze
//pointeur statique ==> unique ==> sûr 
// evite problemes de concurrences d'environnement multithreadés
Kamikaze *Kamikaze::kamikaze = nullptr;
bool Kamikaze::initialized = false;

Kamikaze::Kamikaze() {
    initialized = true;
}

Kamikaze* Kamikaze::getKamikaze() {
    if (!Kamikaze::initialized){
        // Libérer la mémoire précédente si factoryInstance est déjà alloué
        if (kamikaze != nullptr) {
            delete kamikaze;
        }
        Kamikaze::kamikaze = new Kamikaze();
    }
    return Kamikaze::kamikaze;
}

//Kamikaze* Kamikaze::getKamikaze() {
//    if (kamikaze == nullptr )
//        kamikaze = new Kamikaze();
//    return kamikaze;
//}


Bestiole Kamikaze::bestiolePlusProche(const Bestiole& bestiole, const std::vector<Bestiole>& listeBestioles) {
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

double Kamikaze::calculNouvelleOrientation(const Bestiole& bestiole, const Bestiole& bestioleProie)  {
    
    double dx = bestioleProie.getCoordx()-bestiole.getCoordx();
    double dy = bestioleProie.getCoordy()-bestiole.getCoordy();
    double nouvelleOrientation;
    if (dy>0){
        nouvelleOrientation= M_PI/2 - atan2(dx, dy);  // atan2(x, y) fait arctan(x/y)
    } else if (dy<0){
        nouvelleOrientation = M_PI/2 + atan2(dx, dy);  
    } else{
        if(dx>0){nouvelleOrientation = 0;}
        else if(dx<0){nouvelleOrientation = M_PI;}
    }

    return nouvelleOrientation;
}


void Kamikaze::execute(Bestiole & bestiole, Milieu & milieu) {
    //une bestiole kamikaze cherche à provoquer une collision avec la bestiole la plus proche

    std::vector<Bestiole> listeBestioles = bestiole.capteBestioles(milieu);
    if (!listeBestioles.empty()) {
        Bestiole proie = bestiolePlusProche(bestiole, listeBestioles);
        double nouvelleOrientation = calculNouvelleOrientation(bestiole, proie);
        bestiole.setOrientation(nouvelleOrientation);
    }  
}


