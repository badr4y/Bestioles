#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_

#include "UImg.h"

#include <memory>
#include <iostream>
#include <vector>
#include <utility>
#include "Upgrades/Upgrade.h"
#include "comportements/Comportement.h"
#include "ComportementEnum.h"

using namespace std;

class Comportement;

class Bestiole
{

private:
   static const double AFF_SIZE;
   static const double MAX_VITESSE;
   static const double LIMITE_VUE;
   static const double P_MORT_COLLISION;

   static int next;

private:
   int identite;
   int x, y;
   double cumulX, cumulY;
   double orientation;
   double vitesse;
   double currentVitesse;
   Comportement *comportement;
   int stepsToDeath;
   bool isDead;

   T *couleur;

   std::vector<std::shared_ptr<Upgrade>> upgrades;

private:
   void bouge(int xLim, int yLim);

public:                                         // Forme canonique :
   Bestiole(ComportementEnum comportementEnum); // Constructeur par defaut
   Bestiole(const Bestiole &b);                 // Constructeur de copies
   ~Bestiole(void);                             // Destructeur
                                                // Operateur d'affectation binaire par defaut
   void action(Milieu &monMilieu);
   void draw(UImg &support);

   bool jeTeVois(const Bestiole &b) const;

   void initCoords(int xLim, int yLim);

   friend bool operator==(const Bestiole &b1, const Bestiole &b2);

   int getCoordx() const;
   int getCoordy() const;
   double getVitesse();
   void setCurrentVitesse(double newVitesse);
   double getOrientation();
   void setOrientation(double newOrientation);

   bool getIsDead() const;
   void markAsDead();

   std::vector<Bestiole> capteBestioles(Milieu &monMilieu) const;
   double getCamouflage() const;
   double getProbaMortCollision() const;
   double getVitesseReelle() const;
};

#endif
