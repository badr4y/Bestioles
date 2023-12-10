#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"
#include "Upgrades/Upgrade.h"
#include "Upgrades/Capteur.h"
#include "Upgrades/Yeux.h"
#include "factories/BestioleFactory.h"

#include <iostream>

using namespace std;


int main()
{

    Aquarium       ecosysteme(640, 480, 30);

    BestioleFactory::getFactory()->setMilieu(&(ecosysteme.getMilieu()));
    BestioleFactory::getFactory()->createPopulation();

    /*for (int i = 1; i <= 20; ++i)
       ecosysteme.getMilieu().addMember( Bestiole() );*/
    ecosysteme.run();



   return 0;

}
