#ifndef _MILIEU_H_
#define _MILIEU_H_


#include "../Milieu.h"
#include "../Bestiole.h"

#include <iostream>
#include <vector>

using namespace std;

class Comportement {

public:
    virtual void execute(Bestiole*, Milieu*);
    virtual double getOrientationMoyenneVoisins(const std::vector<Bestiole>*); 
    virtual double getNouvelleOrientation(const std::vector<Bestiole>*); 
};

#endif
