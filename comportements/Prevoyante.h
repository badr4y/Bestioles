#ifndef _PREVOYANTE_H_
#define _PREVOYANTE_H_

#include "Comportement.h"
#include "Bestiole.h"
#include "Milieu.h"

#include <iostream>
using namespace std;

class Prevoyante : public virtual Comportement{

private :
   Prevoyante prevoyante;

private :
   Prevoyante();
public :                                           
   static Prevoyante getPrevoyante();    

public : 
   double estimeTrajectoire();
   double calculNouvelleDirection();
   void execute(Bestiole, Milieu);
   
   ~Prevoyante();                              
};


#endif
