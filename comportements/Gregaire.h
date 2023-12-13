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
   double getOrientationMoyenneVoisins(const std::list<std::shared_ptr<Bestiole>>& bestioles);

   void execute(Bestiole&, Milieu &) override;                            
};


#endif

