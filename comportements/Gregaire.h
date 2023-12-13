#ifndef _GREGAIRE_H_
#define _GREGAIRE_H_

#include "Comportement.h"
#include "../Bestiole.h"
#include "../Milieu.h"

#include <list>
#include <memory>
#include <iostream>
using namespace std;


class Gregaire : public Comportement{

private :
   static Gregaire* gregaire;
   static bool initialized;
   Gregaire();

public :                                           
   static Gregaire* getGregaire();
   double getOrientationMoyenneVoisins(const list<Bestiole>& bestioles);
   double getNouvelleOrientation(const list<Bestiole>& bestioles, const Bestiole&);

   void execute(Bestiole&, Milieu &) override;                            
};


#endif

