#include "Bestiole.h"

#include "Milieu.h"

#include <memory>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <utility>

#include "Upgrades/Upgrade.h"
#include "Upgrades/Capteur.h"
#include "Upgrades/Yeux.h"
#include "Upgrades/Oreilles.h"
#include "Upgrades/Camouflage.h"
#include "Upgrades/Carapace.h"
#include "Upgrades/Nageoire.h"


const double      Bestiole::AFF_SIZE = 8.;
const double      Bestiole::MAX_VITESSE = 10.;
const double      Bestiole::LIMITE_VUE = 30.;
const double      Bestiole::P_MORT_COLLISION = 0.1; 
int               Bestiole::next = 0;


Bestiole::Bestiole()
{

   identite = ++next;

   cout << "const Bestiole (" << identite << ") par defaut" << endl;

   x = y = 0;
   cumulX = cumulY = 0.;
   orientation = static_cast<double>( rand() )/RAND_MAX*2.*M_PI;
   vitesse = static_cast<double>( rand() )/RAND_MAX*MAX_VITESSE;

   couleur = new T[ 3 ];
   //couleur[ 0 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   //couleur[ 1 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   //couleur[ 2 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   couleur[ 0 ] = static_cast<int>( 10. );  // est bleu au debut
   couleur[ 1 ] = static_cast<int>( 230. );
   couleur[ 2 ] = static_cast<int>( 10. );

   Yeux yeux;
   Oreilles oreilles;
   //Camouflage camouflage;
   upgrades.push_back(std::make_shared<Yeux>(yeux));
   upgrades.push_back(std::make_shared<Oreilles>(oreilles));
   //upgrades.push_back(std::make_shared<Camouflage>(camouflage));


}


Bestiole::Bestiole( const Bestiole & b )
{

   identite = ++next;

   cout << "const Bestiole (" << identite << ") par copie" << endl;

   x = b.x;
   y = b.y;
   cumulX = cumulY = 0.;
   orientation = b.orientation;
   vitesse = b.vitesse;
   couleur = new T[ 3 ];
   memcpy( couleur, b.couleur, 3*sizeof(T) );

   upgrades = b.upgrades; // deepcopy je crois 

}


Bestiole::~Bestiole( void )
{

   delete[] couleur;

   cout << "dest Bestiole" << endl;

}


void Bestiole::initCoords( int xLim, int yLim )
{

   x = rand() % xLim;
   y = rand() % yLim;

}


void Bestiole::bouge( int xLim, int yLim )
{

   double         nx, ny;
   double         dx = cos( orientation )*vitesse;
   double         dy = -sin( orientation )*vitesse;
   int            cx, cy;


   cx = static_cast<int>( cumulX ); cumulX -= cx;
   cy = static_cast<int>( cumulY ); cumulY -= cy;

   nx = x + dx + cx;
   ny = y + dy + cy;

   if ( (nx < 0) || (nx > xLim - 1) ) {
      orientation = M_PI - orientation;
      cumulX = 0.;
   }
   else {
      x = static_cast<int>( nx );
      cumulX += nx - x;
   }

   if ( (ny < 0) || (ny > yLim - 1) ) {
      orientation = -orientation;
      cumulY = 0.;
   }
   else {
      y = static_cast<int>( ny );
      cumulY += ny - y;
   }

}


void Bestiole::action( Milieu & monMilieu )
{

   std::vector<Bestiole> bestiolesCaptees = capteBestioles(monMilieu);

   if (bestiolesCaptees.size() == 0 ){ // devient noir si il ne voit aucune bestiole et devient rouge si il voit une ou plusieurs bestioles
      couleur[ 0 ] = static_cast<int>( 10. );
      couleur[ 1 ] = static_cast<int>( 10. );
      couleur[ 2 ] = static_cast<int>( 10. );
   } else {
      couleur[ 0 ] = static_cast<int>( 230. );
      couleur[ 1 ] = static_cast<int>( 10. );
      couleur[ 2 ] = static_cast<int>( 10. );
   }



   bouge( monMilieu.getWidth(), monMilieu.getHeight() );
   
}


void Bestiole::draw( UImg & support )
{

   double         xt = x + cos( orientation )*AFF_SIZE/2.1;
   double         yt = y - sin( orientation )*AFF_SIZE/2.1;


   support.draw_ellipse( x, y, AFF_SIZE, AFF_SIZE/5., -orientation/M_PI*180., couleur );
   support.draw_circle( xt, yt, AFF_SIZE/2., couleur );

   for (const std::shared_ptr<Upgrade>& u : upgrades) {
      
      Upgrade& upgrade = *u;

      if (upgrade.isYeux()) {
         if (Yeux* yeuxPtr = dynamic_cast<Yeux*>(&upgrade)) {
            double delta = yeuxPtr->getDelta();
            double angle = yeuxPtr->getAlpha()/2;
            //support.draw_line(x, y, x+cos(orientation)*delta, y-sin(orientation)*delta,couleur);
            support.draw_line(x, y, x+cos(orientation+angle)*delta, y-sin(orientation+angle)*delta,couleur);
            support.draw_line(x, y, x+cos(orientation-angle)*delta, y-sin(orientation-angle)*delta,couleur);
         }
      } else {

         if (upgrade.isOreilles()) {
            if (Oreilles* oreillesPtr = dynamic_cast<Oreilles*>(&upgrade)) {
               support.draw_circle(x, y, oreillesPtr->getDelta(), couleur, 1, 0xFFFFFFFF); // opacity, outline (0=none, 1=dots, 0xFFFFFFFF=full)
            }
         }

      }

   }

   //support.draw_line(x, y, x+cos(orientation)*200, y-sin(orientation)*200,couleur);
   //support.draw_line(x, y, x+cos(orientation+0.25)*200, y-sin(orientation+0.25)*200,couleur);
   //support.draw_line(x, y, x+cos(orientation-0.25)*200, y-sin(orientation-0.25)*200,couleur);

   //support.draw_circle(x, y, 100, couleur, 1, 0xFFFFFFFF); // opacity, outline (0=none, 1=dots, 0xFFFFFFFF=full)

}


bool operator==( const Bestiole & b1, const Bestiole & b2 )
{

   return ( b1.identite == b2.identite );

}


bool Bestiole::jeTeVois( const Bestiole & b ) const
{

   double         dist;


   dist = std::sqrt( (x-b.x)*(x-b.x) + (y-b.y)*(y-b.y) );
   return ( dist <= LIMITE_VUE );

}

void setOrientation(double o){
   orientation = o;
}

double getOrientation(){
   return orientation;
}

int Bestiole::getCoordx() const
{
   return x;
}

int Bestiole::getCoordy() const
{
   return y;
}

int Bestiole::getVitesse() const
{
   return vitesse;
}

int Bestiole::setCurrentVitesse(double newVitesse) const
{
   currentVitesse = newVitesse;
}


std::vector<Bestiole> Bestiole::capteBestioles( Milieu & monMilieu ) const
{
   std::vector<Bestiole> bestiolesCaptees;

   for (const std::shared_ptr<Upgrade>& u : upgrades) {
      Upgrade& upgrade = *u;

      if (upgrade.isYeux() || upgrade.isOreilles()) {

         if (Capteur* capteurPtr = dynamic_cast<Capteur*>(&upgrade)) {

            for (const Bestiole& b : monMilieu.getListeBestioles()) {

               if (!(b == *this)) { // if not the current bestiole

                  if ((std::find(bestiolesCaptees.begin(), bestiolesCaptees.end(), b) == bestiolesCaptees.end())) { // if not in bestiolesCaptees already

                     if (capteurPtr->capte(b, x, y, orientation)) {
                        bestiolesCaptees.push_back(b);
                     }
                  }
               }
            }
         } else {
            cout << "Dynamic cast failed..." << endl; 
         }
      }
   }
   return bestiolesCaptees;
}




double Bestiole::getCamouflage() const
{
   double camouflageValue = 0;
   double newValue;

   for (const std::shared_ptr<Upgrade>& u : upgrades) {
      Upgrade& upgrade = *u;

      if (upgrade.isCamouflage()) {

         if (Camouflage* camouflagePtr = dynamic_cast<Camouflage*>(&upgrade)) {
            newValue = camouflagePtr->getPsi();

            if (newValue > camouflageValue){
               camouflageValue = newValue;

            }

         } else {
            cout << "Dynamic cast failed..." << endl; 
         }
      }
   }
   return camouflageValue;
}

double Bestiole::getVitesseReelle() const
{   
    double vitesseReelle = currentVitesse;
    double newNu;
    double newEta;

    for (const std::shared_ptr<Upgrade>& u : upgrades) {
        Upgrade& upgrade = *u;

        if (upgrade.isNageoire()) {
            if (Nageoire* nageoirePtr = dynamic_cast<Nageoire*>(&upgrade)) {
                newNu = nageoirePtr->getNu();

                vitesseReelle = vitesseReelle * newNu;
            }
        }

        if (upgrade.isCarapace()) {
            if (Carapace* carapacePtr = dynamic_cast<Carapace*>(&upgrade)) {
                newEta = carapacePtr->getEta();

                vitesseReelle = vitesseReelle / newEta;
            }
        }

    }
    return vitesseReelle;

}


double Bestiole::getProbaMortCollision() const
{
   double probaMortCollision = Bestiole::P_MORT_COLLISION;
   double newValue;

   for (const std::shared_ptr<Upgrade>& u : upgrades) {
      Upgrade& upgrade = *u;

      if (upgrade.isCarapace()) {

         if (Carapace* carapacePtr = dynamic_cast<Carapace*>(&upgrade)) {
            newValue = carapacePtr->getOmega();
            probaMortCollision = probaMortCollision/newValue;

         } else {
            cout << "Dynamic cast failed..." << endl; 
         }
      }
   }
   return probaMortCollision;
}
