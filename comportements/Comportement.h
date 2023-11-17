#ifndef _MILIEU_H_
#define _MILIEU_H_


#include "../Milieu.h"
#include "../Bestiole.h"

#include <iostream>
#include <vector>

using namespace std;

class Comportement {

public:
    virtual void execute(Bestiole, Milieu);
    virtual double getOrientationMoyenneVoisins()=0; 
    virtual int,int getDirectionMoyenne()=0; 
    virtual ~Comportement{};
};
