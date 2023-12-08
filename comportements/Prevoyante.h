#ifndef _PREVOYANTE_H_
#define _PREVOYANTE_H_

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
   double estimeTrajectoire(const Bestiole&, const Bestiole&);
   double calculNouvelleDirection(const Bestiole&, const Milieu&);
   void execute(const Bestiole&, const Milieu&);
                                
};


#endif
