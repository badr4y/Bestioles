#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"
#include "Upgrades/Upgrade.h"
#include "Upgrades/Capteur.h"
#include "Upgrades/Yeux.h"

#include <iostream>

using namespace std;


int main()
{

   Yeux yeux;
   cout << "test bool isYeux(), isCarapace(), ... : " << yeux.isYeux() << yeux.isCarapace() << yeux.isNageoire() << endl;

   Aquarium       ecosysteme( 640, 480, 30 );

   for ( int i = 1; i <= 4; ++i )
      ecosysteme.getMilieu().addMember( Bestiole() );
   ecosysteme.run();


   return 0;

}
