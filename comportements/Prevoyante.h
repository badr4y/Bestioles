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
private :
   Prevoyante();

public :                                           
   static Prevoyante* getPrevoyante();    
public : 
   Bestiole bestiolePlusProche(const std::vector<Bestiole>& );
   double calculNouvelleOrientation(const Bestiole&, const Bestiole&);

   void execute(Bestiole&, Milieu&);
};

#endif