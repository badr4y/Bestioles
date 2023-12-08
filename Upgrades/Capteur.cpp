#include "Capteur.h"
#include "Yeux.h"
#include "Oreilles.h"
#include "Camouflage.h"

#include <cstdlib>
#include <cmath>
#include <utility>

using namespace std;


bool Capteur::capte(const Bestiole& b, int x, int y, double orientation) {
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
        // Distance not too large (within delta)

        cout << orientation << endl;

        double angle = std::atan2(-(by - y), bx - x);

        double alpha;
        if (isYeux()) {
            Yeux* y = dynamic_cast<Yeux*>(this);
            alpha = y->getAlpha();
        }

        // Angular deviation between the orientation of the bestiole and the angle under which the bestiole is seen
        double ecartAngulaire = std::abs(orientation - angle);
        while (ecartAngulaire > 2 * M_PI)
            ecartAngulaire -= 2 * M_PI;

        if (isOreilles() || ecartAngulaire <= (alpha / 2)) {

        	double gamma;
		    if (isOreilles()) {
		        Oreilles* o = dynamic_cast<Oreilles*>(this);
		        gamma = o->getGamma();
		    } else {
		        Yeux* y = dynamic_cast<Yeux*>(this);
		        gamma = y->getGamma();
		    }        	

            if (b.getCamouflage() < gamma){

            	return true;

            }
        }
    }

    return false;
}
