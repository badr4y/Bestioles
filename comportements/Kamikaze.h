#ifndef _KAMIKAZE_H_
#define _KAMIKAZE_H_

#include "Comportement.h"
#include "../Bestiole.h"
#include "../Milieu.h"

#include <iostream>
using namespace std;

class Kamikaze : public virtual Comportement{

private :
   static Kamikaze* kamikaze;
   static bool initialized;
   Kamikaze();

public :                                           
   static Kamikaze* getKamikaze();
   std::shared_ptr<Bestiole> bestiolePlusProche(const Bestiole&, const std::list<std::shared_ptr<Bestiole>>&);
   double calculNouvelleOrientation(const Bestiole&, const std::shared_ptr<Bestiole>);

   void execute(Bestiole&, Milieu&);                           
};

#endif
