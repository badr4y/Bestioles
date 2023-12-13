#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"
#include "factories/BestioleFactory.h"

#include <iostream>

using namespace std;

class BestioleFactory;

int main()
{
    Aquarium       ecosysteme(640, 480, 30);

    BestioleFactory::getFactory()->createPopulation();

    ecosysteme.run();

    return 0;

}