#ifndef _COMPORTEMENT_H_
#define _COMPORTEMENT_H_


#include "../Bestiole.h"
#include "../Milieu.h"

#include <iostream>
#include <vector>

using namespace std;

class Milieu;
class Bestiole;

class Comportement {

public:
    virtual void execute(Bestiole&, Milieu&) = 0;
    virtual ~Comportement() = default;
};

#endif
