#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_


#include "UImg.h"

#include <memory>
#include <iostream>
#include <vector>
#include <utility>
#include "Upgrades/Upgrade.h"


using namespace std;


class Milieu;


class Bestiole
{

private :
   static const double     AFF_SIZE;
   static const double     MAX_VITESSE;
   static const double     LIMITE_VUE;

   static int              next;

private :
   int               identite;
   int               x, y;
   double            cumulX, cumulY;
   double            orientation;
   double            vitesse;

   T               * couleur;

   std::vector<std::shared_ptr<Upgrade>> upgrades;

private :
   void bouge( int xLim, int yLim );

public :                                           // Forme canonique :
   Bestiole();                         // Constructeur par defaut
   Bestiole( const Bestiole & b );                 // Constructeur de copies
   ~Bestiole( void );                              // Destructeur
                                                   // Operateur d'affectation binaire par defaut
   void action( Milieu & monMilieu );
   void draw( UImg & support );

   bool jeTeVois( const Bestiole & b ) const;

   void initCoords( int xLim, int yLim );

   friend bool operator==( const Bestiole & b1, const Bestiole & b2 );

   int getCoordx() const;
   int getCoordy() const;

   std::vector<Bestiole> capteBestioles( Milieu & monMilieu ) const;
   double getCamouflage() const;

};


#endif
