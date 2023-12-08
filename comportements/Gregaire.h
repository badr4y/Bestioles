#ifndef _GREGAIRE_H_
#define _GREGAIRE_H_

#include "Comportement.h"
#include "../Bestiole.h"
#include "../Milieu.h"

#include <memory>
#include <iostream>
using namespace std;

class Gregaire : public Comportement{

private :
   static Gregaire* gregaire;

private :
   Gregaire();

public :                                           
   static Gregaire* getGregaire();    

public : 
   double getOrientationMoyenneVoisins(const std::vector<Bestiole>&);                            
   double getNouvelleOrientation(const std::vector<Bestiole>&); 

   void execute(Bestiole&, Milieu &);                            
};


#endif
