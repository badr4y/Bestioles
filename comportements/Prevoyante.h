#ifndef PREVOYANTE_H
#define PREVOYANTE_H

#include "Comportement.h"
#include "../Bestiole.h"
#include "../Milieu.h"

#include <iostream>
using namespace std;

class Prevoyante : public virtual Comportement{

private :
   static Prevoyante* prevoyante;
   static bool initialized;
   Prevoyante();

public :                                           
   static Prevoyante* getPrevoyante();    
   std::shared_ptr<Bestiole> bestiolePlusProche(const Bestiole&, const std::list<std::shared_ptr<Bestiole>>& );
   double calculNouvelleOrientation(const Bestiole&, const std::shared_ptr<Bestiole>);

   void execute(Bestiole&, Milieu&);
};

#endif