#include "Capteur.h"
#include "Yeux.h"
#include "Oreilles.h"

#include <cstdlib>
#include <cmath>
#include <utility>

using namespace std;


bool Capteur::capte(const Bestiole& b, int x, int y, double orientation) {
    double dist;

    int bx = b.getCoordx();
    int by = b.getCoordy();

    dist = std::sqrt((x - bx) * (x - bx) + (y - by) * (y - by));

    cout << "dist" << dist << endl;

    double delta;
    if (isOreilles()) {
        Oreilles* o = dynamic_cast<Oreilles*>(this);
        delta = o->getDelta();
    } else {
        Yeux* y = dynamic_cast<Yeux*>(this);
        delta = y->getDelta();
    }

    cout << "delta" << delta << endl;

    if (dist != 0. && dist <= delta) {
    	cout << "distance smaller than delta" << endl;
        // Distance not too large (within delta)

        double angle = std::atan2(by - y, bx - x);

        double alpha;
        if (isYeux()) {
            Yeux* y = dynamic_cast<Yeux*>(this);
            alpha = y->getAlpha();
        }

        // Angular deviation between the orientation of the bestiole and the angle under which the bestiole is seen
        double ecartAngulaire = std::abs(orientation - angle);
        while (ecartAngulaire > 2 * M_PI)
            ecartAngulaire -= 2 * M_PI;
        while (ecartAngulaire < 0)
            ecartAngulaire += 2 * M_PI;

        if (isOreilles() || ecartAngulaire <= (alpha / 2)) {
            // If the angular deviation is within the field of vision with angular sector alpha, the bestiole is seen
            
            // camouflage à prendre en compte avec b.getCamouflage() a utiliser quand elle sera programmee


            return true;
        }
    }

    return false;
}
