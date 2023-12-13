#include "Kamikaze.h"
#include "../Bestiole.h"
#include "../Milieu.h"
#include <list>

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
        Kamikaze::kamikaze = new Kamikaze();
    }
    return Kamikaze::kamikaze;
}

//Kamikaze* Kamikaze::getKamikaze() {
//    if (kamikaze == nullptr )
//        kamikaze = new Kamikaze();
//    return kamikaze;
//}


std::shared_ptr<Bestiole> Kamikaze::bestiolePlusProche(const Bestiole& bestiole, const std::list<std::shared_ptr<Bestiole>>& listeBestioles) {
    // The case where listeBestioles is empty is handled in the execute() method

    double distanceSquared = 1000000000;
    double currentDistanceSquared;
    std::shared_ptr<Bestiole> bestioleProchePtr = nullptr;
    for (const auto& ptr : listeBestioles) {
        currentDistanceSquared = std::pow(bestiole.getCoordx() - ptr->getCoordx(), 2) +
        std::pow(bestiole.getCoordy() - ptr->getCoordy(), 2);

        if (currentDistanceSquared < distanceSquared) {
            bestioleProchePtr = ptr;
            distanceSquared = currentDistanceSquared;
        }
    }

    return bestioleProchePtr;
}


double Kamikaze::calculNouvelleOrientation(const Bestiole& bestiole, const std::shared_ptr<Bestiole> bestioleProchePtr)  {
    
    double dx = bestioleProchePtr->getCoordx()-bestiole.getCoordx();
    double dy = bestioleProchePtr->getCoordy()-bestiole.getCoordy();
    double nouvelleOrientation;
    if (dy>0){
        nouvelleOrientation= M_PI/2 + atan2(dx, dy);  // atan2(x, y) fait arctan(x/y)
    } else if (dy<0){
        nouvelleOrientation = M_PI/2 - atan2(dx, dy);  
    } else{
        if(dx>0){nouvelleOrientation = 0;}
        else if(dx<0){nouvelleOrientation = M_PI;}
    }

    return nouvelleOrientation + M_PI;
}


void Kamikaze::execute(Bestiole & bestiole, Milieu & milieu) {

    cout << "Appel à execute de kamikaze" << endl;

    //une bestiole kamikaze cherche à provoquer une collision avec la bestiole la plus proche

    std::list<std::shared_ptr<Bestiole>> listeBestioles = bestiole.capteBestioles(milieu);
    if (!listeBestioles.empty()) {
        std::shared_ptr<Bestiole> proiePtr = bestiolePlusProche(bestiole, listeBestioles);
        double nouvelleOrientation = calculNouvelleOrientation(bestiole, proiePtr);
        bestiole.setOrientation(nouvelleOrientation);
    }

    cout << "Fin appel à execute de kamikaze" << endl;
}


