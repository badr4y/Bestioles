#include "Capteur.h"
#include "Yeux.h"
#include "Oreilles.h"
#include "Camouflage.h"

#include <cstdlib>
#include <cmath>
#include <utility>

using namespace std;


bool Capteur::capte(const Bestiole& b, int x, int y, double orientation) {
	// Capte les bestioles vues ou entendues par la bestiole b
	// Même calcul pour les Yeux et les Oreilles donc factorisation du code.
    
    double dist;

    int bx = b.getCoordx();
    int by = b.getCoordy();

    dist = std::sqrt((x - bx) * (x - bx) + (y - by) * (y - by));

    double delta;
    if (isOreilles()) {
        Oreilles* o = dynamic_cast<Oreilles*>(this);
        delta = o->getDelta();
    } else {
        Yeux* y = dynamic_cast<Yeux*>(this);
        delta = y->getDelta();
    }


    if (dist != 0. && dist <= delta) {
        // La distance est suffisemment faible pour être capté
        // Sinon le reste du calcul est inutile

        cout << orientation << endl;

        double angle = std::atan2(-(by - y), bx - x);

        double alpha;
        if (isYeux()) {
            Yeux* y = dynamic_cast<Yeux*>(this);
            alpha = y->getAlpha();
        }

        // Déviation angulaire entre la bestiole captante et la bestiole captée
        double ecartAngulaire = std::abs(orientation - angle);
        while (ecartAngulaire > 2 * M_PI)
            ecartAngulaire -= 2 * M_PI;


        if (isOreilles() || ecartAngulaire <= (alpha / 2)) {
        	// L'angle est dans le secteur angulaire (forcément si Oreilles)
        	// Sinon le reste du calcul est inutile

        	double gamma;
		    if (isOreilles()) {
		        Oreilles* o = dynamic_cast<Oreilles*>(this);
		        gamma = o->getGamma();
		    } else {
		        Yeux* y = dynamic_cast<Yeux*>(this);
		        gamma = y->getGamma();
		    }        	


            if (b.getCamouflage() < gamma){
            	// La valeur de comouflage de la cible est plus faible que la valeur gamma de la bestiole

            	return true;

            }
        }
    }

    return false;
}
