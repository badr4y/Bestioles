#ifndef _GREGAIRE_H_
#define _GREGAIRE_H_

#include "Comportement.h"
#include "Bestiole.h"
#include "Milieu.h"

#include <iostream>
using namespace std;

class Gregaire : public virtual Comportement{

private :
   Gregaire gregaire;

private :
   Gregaire();
public :                                           
   static Gregaire getGregaire();    

public : 
   double getOrientationMoyenneVoisins();                            
   double getNouvelleOrientation(); 

   void execute(Bestiole, Milieu)
   ~Gregaire();                              
};


#endif
