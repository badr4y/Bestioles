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

#include "comportements/Comportement.h"
#include "comportements/Gregaire.h"
#include "comportements/Kamikaze.h"
#include "comportements/Peureuse.h"
#include "comportements/Prevoyante.h"
#include "comportements/PersonnalitesMultiples.h"

#include "factories/BestioleFactory.h"

const double Bestiole::AFF_SIZE = 8.;
const double Bestiole::MAX_VITESSE = 10.;
const double Bestiole::LIMITE_VUE = 30.;
const double Bestiole::P_MORT_COLLISION = 0.1;
int Bestiole::next = 0;

Bestiole::Bestiole(ComportementEnum comportementEnum) : isDead(false)
{

   identite = ++next;

   cout << "const Bestiole (" << identite << ") par defaut" << endl;

   x = y = 0;
   cumulX = cumulY = 0.;
   orientation = static_cast<double>(rand()) / RAND_MAX * 2. * M_PI;
   vitesse = static_cast<double>(rand()) / RAND_MAX * MAX_VITESSE;

   stepsToDeath = rand() % (150 - 15 + 1) + 15;

   couleur = new T[3];
   // couleur[ 0 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   // couleur[ 1 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   // couleur[ 2 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   couleur[0] = static_cast<int>(10.); // est bleu au debut
   couleur[1] = static_cast<int>(230.);
   couleur[2] = static_cast<int>(10.);

   switch (comportementEnum)
      {
      case ComportementEnum::gregaire:
         this->comportement = Gregaire::getGregaire();
         break;
      case ComportementEnum::peureuse:
         this->comportement = Peureuse::getPeureuse();
         break;
      case ComportementEnum::kamikaze:
         this->comportement = Kamikaze::getKamikaze();
         break;
      case ComportementEnum::prevoyante:
         this->comportement = Prevoyante::getPrevoyante();
         break;
      case ComportementEnum::personnalitesMultiples:
         PersonnalitesMultiples pm = PersonnalitesMultiples();
         pm.changeComportement();
         this->comportement = &pm;
         break;
      }
   stepsToDeath = rand() % (1000 - 600 + 1) + 600;
   cout << "comportement defini ?" << endl;
   cout << (comportement != nullptr) << endl; // Oui

   Yeux yeux;
   Oreilles oreilles;
   // Camouflage camouflage;
   upgrades.push_back(std::make_shared<Yeux>(yeux));
   upgrades.push_back(std::make_shared<Oreilles>(oreilles));
   // upgrades.push_back(std::make_shared<Camouflage>(camouflage));
}

Bestiole::Bestiole(const Bestiole &b)
{

   identite = ++next;

   cout << "const Bestiole (" << identite << ") par copie" << endl;

   x = b.x + 3;
   y = b.y + 3;
   cumulX = cumulY = 0.;
   orientation = b.orientation;
   vitesse = b.vitesse;
   currentVitesse = b.currentVitesse;
   couleur = new T[3];
   memcpy(couleur, b.couleur, 3 * sizeof(T));

   isDead = b.isDead;
   stepsToDeath = b.stepsToDeath;

   comportement = b.getComportement();

   upgrades = b.upgrades; // deepcopy je crois
}

Bestiole::~Bestiole(void)
{

   delete[] couleur;

   cout << "dest Bestiole" << endl;
}

void Bestiole::initCoords(int xLim, int yLim)
{

   x = rand() % xLim;
   y = rand() % yLim;
}

void Bestiole::bouge(int xLim, int yLim)
{

   double nx, ny;
   double dx = cos(orientation) * vitesse;
   double dy = -sin(orientation) * vitesse;
   int cx, cy;

   cx = static_cast<int>(cumulX);
   cumulX -= cx;
   cy = static_cast<int>(cumulY);
   cumulY -= cy;

   nx = x + dx + cx;
   ny = y + dy + cy;

   if ((nx < 0) || (nx > xLim - 1))
   {
      orientation = M_PI - orientation;
      cumulX = 0.;
   }
   else
   {
      x = static_cast<int>(nx);
      cumulX += nx - x;
   }

   if ((ny < 0) || (ny > yLim - 1))
   {
      orientation = -orientation;
      cumulY = 0.;
   }
   else
   {
      y = static_cast<int>(ny);
      cumulY += ny - y;
   }
}

bool Bestiole::getIsDead() const
{
   return isDead;
}

void Bestiole::markAsDead()
{
   isDead = true;
}

void Bestiole::action(Milieu &monMilieu)
{

   cout << "Debut appel Action bestiole" << endl;

   if (comportement == Kamikaze::getKamikaze())
   { // devient noir si il ne voit aucune bestiole et devient rouge si il voit une ou plusieurs bestioles
      couleur[0] = static_cast<int>(225.);
      couleur[1] = static_cast<int>(174.);
      couleur[2] = static_cast<int>(123.);
   }
   if (comportement == Peureuse::getPeureuse())
   {
      couleur[0] = static_cast<int>(164.);
      couleur[1] = static_cast<int>(113.);
      couleur[2] = static_cast<int>(215.);
   }
   if (comportement == Prevoyante::getPrevoyante())
   {
      couleur[0] = static_cast<int>(153.);
      couleur[1] = static_cast<int>(204.);
      couleur[2] = static_cast<int>(255.);
   }
   if (comportement == Gregaire::getGregaire())
   {
      couleur[0] = static_cast<int>(200.);
      couleur[1] = static_cast<int>(255.);
      couleur[2] = static_cast<int>(200.);
   }



   cout << "Fin maj couleur bestiole et Juste avant l'appel à execute" << endl;

   comportement->execute(*this, monMilieu);

   cout << "Fin execute" << endl;


   int randomValue = std::rand() % 800;

   // Si le nombre aléatoire est égal à 50, appel de la fonction de clonage
   if (randomValue == 50) {
       BestioleFactory::getFactory()->cloneBestiole(*this);  // Assurez-vous que la fonction clone() est définie dans votre classe Bestiole
   }

   cout << "Appel à execute fini" << endl;

   bouge(monMilieu.getWidth(), monMilieu.getHeight());
   stepsToDeath = stepsToDeath - 1;
   if (stepsToDeath == 0)
   {
      markAsDead();
   }

   cout << "Fin appel Action bestiole" << endl;

}

void Bestiole::draw(UImg &support)
{

   double xt = x + cos(orientation) * AFF_SIZE / 2.1;
   double yt = y - sin(orientation) * AFF_SIZE / 2.1;

   support.draw_ellipse(x, y, AFF_SIZE, AFF_SIZE / 5., -orientation / M_PI * 180., couleur);
   support.draw_circle(xt, yt, AFF_SIZE / 2., couleur);

   for (const std::shared_ptr<Upgrade> &u : upgrades)
   {

      Upgrade &upgrade = *u;

      if (upgrade.isYeux())
      {
         if (Yeux *yeuxPtr = dynamic_cast<Yeux *>(&upgrade))
         {
            double delta = yeuxPtr->getDelta();
            double angle = yeuxPtr->getAlpha() / 2;
            // support.draw_line(x, y, x+cos(orientation)*delta, y-sin(orientation)*delta,couleur);
            support.draw_line(x, y, x + cos(orientation + angle) * delta, y - sin(orientation + angle) * delta, couleur);
            support.draw_line(x, y, x + cos(orientation - angle) * delta, y - sin(orientation - angle) * delta, couleur);
         }
      }
      else
      {

         if (upgrade.isOreilles())
         {
            if (Oreilles *oreillesPtr = dynamic_cast<Oreilles *>(&upgrade))
            {
               support.draw_circle(x, y, oreillesPtr->getDelta(), couleur, 1, 0xFFFFFFFF); // opacity, outline (0=none, 1=dots, 0xFFFFFFFF=full)
            }
         }
      }
   }

   // support.draw_line(x, y, x+cos(orientation)*200, y-sin(orientation)*200,couleur);
   // support.draw_line(x, y, x+cos(orientation+0.25)*200, y-sin(orientation+0.25)*200,couleur);
   // support.draw_line(x, y, x+cos(orientation-0.25)*200, y-sin(orientation-0.25)*200,couleur);

   // support.draw_circle(x, y, 100, couleur, 1, 0xFFFFFFFF); // opacity, outline (0=none, 1=dots, 0xFFFFFFFF=full)
}

bool operator==(const Bestiole &b1, const Bestiole &b2)
{

   return (b1.identite == b2.identite);
}

bool Bestiole::jeTeVois(const Bestiole &b) const
{

   double dist;

   dist = std::sqrt((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y));
   return (dist <= LIMITE_VUE);
}

void Bestiole::setOrientation(double o)
{
   orientation = o;
}

double Bestiole::getOrientation() const
{
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

void Bestiole::setCoordx(int newx)
{
   x = newx;
}

void Bestiole::setCoordy(int newy)
{
   y = newy;
}

int Bestiole::getCumulX() const
{
   return cumulX;
}


int Bestiole::getCumulY() const
{
   return cumulY;
}

void Bestiole::setCumulX(int newCumulx)
{
   cumulX = newCumulx;
}

void Bestiole::setCumulY(int newCumuly)
{
   cumulY = newCumuly;
}

Comportement* Bestiole::getComportement() const
{
   return comportement;
}


double Bestiole::getVitesse() const
{
   return vitesse;
}

void Bestiole::setCurrentVitesse(double newVitesse)
{
   currentVitesse = newVitesse;
}

std::list<std::shared_ptr<Bestiole>> Bestiole::capteBestioles(const Milieu& monMilieu) const
{
    std::list<std::shared_ptr<Bestiole>> bestiolesCaptees;

    for (const std::shared_ptr<Bestiole>& bPtr : monMilieu.getListeBestioles())
    {
        const Bestiole& b = *bPtr;

        auto compareBestioles = [&b](const std::shared_ptr<Bestiole>& ptr) {
            return *ptr == b;
        };

        for (const std::shared_ptr<Upgrade>& u : upgrades)
        {
            Upgrade& upgrade = *u;

            if (upgrade.isYeux() || upgrade.isOreilles())
            {
                if (Capteur* capteurPtr = dynamic_cast<Capteur*>(&upgrade))
                {
                    if (!(b == *this) && (std::find_if(bestiolesCaptees.begin(), bestiolesCaptees.end(), compareBestioles) == bestiolesCaptees.end()))
                    {
                        if (capteurPtr->capte(b, x, y, orientation))
                        {
                            bestiolesCaptees.push_back(std::make_shared<Bestiole>(b));
                        }
                    }
                }
            }
            else
            {
                std::cout << "Dynamic cast failed..." << std::endl;
            }
        }
    }

    return bestiolesCaptees;
}





double Bestiole::getCamouflage() const
{
   double camouflageValue = 0;
   double newValue;

   for (const std::shared_ptr<Upgrade> &u : upgrades)
   {
      Upgrade &upgrade = *u;

      if (upgrade.isCamouflage())
      {

         if (Camouflage *camouflagePtr = dynamic_cast<Camouflage *>(&upgrade))
         {
            newValue = camouflagePtr->getPsi();

            if (newValue > camouflageValue)
            {
               camouflageValue = newValue;
            }
         }
         else
         {
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

   for (const std::shared_ptr<Upgrade> &u : upgrades)
   {
      Upgrade &upgrade = *u;

      if (upgrade.isNageoire())
      {
         if (Nageoire *nageoirePtr = dynamic_cast<Nageoire *>(&upgrade))
         {
            newNu = nageoirePtr->getNu();

            vitesseReelle = vitesseReelle * newNu;
         }
      }

      if (upgrade.isCarapace())
      {
         if (Carapace *carapacePtr = dynamic_cast<Carapace *>(&upgrade))
         {
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

   for (const std::shared_ptr<Upgrade> &u : upgrades)
   {
      Upgrade &upgrade = *u;

      if (upgrade.isCarapace())
      {

         if (Carapace *carapacePtr = dynamic_cast<Carapace *>(&upgrade))
         {
            newValue = carapacePtr->getOmega();
            probaMortCollision = probaMortCollision / newValue;
         }
         else
         {
            cout << "Dynamic cast failed..." << endl;
         }
      }
   }
   return probaMortCollision;
}
