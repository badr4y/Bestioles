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

private :
   Kamikaze();
public :                                           
   static Kamikaze* getKamikaze();    

public : 
   Bestiole& getPlusProche(Bestiole &, const Milieu & milieu);
   void execute(Bestiole&, const Milieu&);
                                
};


#endif
