#ifndef _KAMIKAZE_H_
#define _KAMIKAZE_H_

#include "Comportement.h"
#include "Bestiole.h"
#include "Milieu.h"

#include <iostream>
using namespace std;

class Kamikaz : public virtual Comportement{

private :
   Kamikaze kamikaze;

private :
   Kamikaze();
public :                                           
   static Kamikaze getKamikaze();    

public : 
   Bestiole getPlusProche();
   void execute(Bestiole, Milieu);
   
   ~Kamikaze();                              
};


#endif
