#include "BestioleFactory.h"
#include "../Milieu.h"
#include "../Aquarium.h"
#include "../ComportementEnum.h"

#include <random>

BestioleFactory *BestioleFactory::factoryInstance = nullptr;
bool BestioleFactory::initialized = false;

BestioleFactory::BestioleFactory(double gregaire, double peureuse, double kamikaze, double prevoyant, double multiple, int population)
    : PROPORTIONGREGAIRE(gregaire),
      PROPORTIONPEUREUSE(peureuse),
      PROPORTIONKAMIKAZE(kamikaze),
      PROPORTIONPREVOYANT(prevoyant),
      PROPORTIONMULTIPLE(multiple),
      POPULATIONINITIAL(population)
{
    initialized = true;
}

BestioleFactory::~BestioleFactory(){
    if (BestioleFactory::factoryInstance != nullptr) {
        delete BestioleFactory::factoryInstance;
    }
}

double BestioleFactory::getPROPORTIONGREGAIRE() const
{
  return PROPORTIONGREGAIRE;
}
double BestioleFactory::getPROPORTIONPEUREUSE() const
{
  return PROPORTIONPEUREUSE;
}
double BestioleFactory::getPROPORTIONKAMIKAZE() const
{
  return PROPORTIONKAMIKAZE;
}
double BestioleFactory::getPROPORTIONPREVOYANT() const
{
  return PROPORTIONPREVOYANT;
}
double BestioleFactory::getPROPORTIONMULTIPLE() const
{
  return PROPORTIONMULTIPLE;
}

Milieu* BestioleFactory::getMilieu() const
{
   return monMilieu;
}

void BestioleFactory::setMilieu(Milieu* milieu) 
{
   monMilieu = milieu;
}

BestioleFactory* BestioleFactory::getFactory()
{
    if (!BestioleFactory::initialized)
    {
        double gregaire, peureuse, kamikaze, prevoyant, multiple;
        int population;
        std::cout << "Enter Proportion of Gregaire: ";
        std::cin >> gregaire;
        std::cout << "Enter Proportion of Peureuse: ";
        std::cin >> peureuse;
        std::cout << "Enter Proportion of Kamikaze: ";
        std::cin >> kamikaze;
        std::cout << "Enter Proportion of Prevoyant: ";
        std::cin >> prevoyant;
        std::cout << "Enter Proportion of Multiple: ";
        std::cin >> multiple;
        std::cout << "Enter the initial population mass: ";
        std::cin >> population;

        // Libérer la mémoire précédente si factoryInstance est déjà alloué
        if (factoryInstance != nullptr) {
            delete factoryInstance;
        }

        BestioleFactory::factoryInstance = new BestioleFactory(gregaire, peureuse, kamikaze, prevoyant, multiple, population);

    }

    return BestioleFactory::factoryInstance;
}


void BestioleFactory::createPopulation()
{

    std::cout << "Appel à createPopulation lancé" << std::endl;

    int gregaireCount = static_cast<int>(POPULATIONINITIAL * PROPORTIONGREGAIRE);
    int peureuseCount = static_cast<int>(POPULATIONINITIAL * PROPORTIONPEUREUSE);
    int kamikazeCount = static_cast<int>(POPULATIONINITIAL * PROPORTIONKAMIKAZE);
    int prevoyantCount = static_cast<int>(POPULATIONINITIAL * PROPORTIONPREVOYANT);
    int multipleCount = static_cast<int>(POPULATIONINITIAL * PROPORTIONMULTIPLE);

    int remainingCount = POPULATIONINITIAL - (gregaireCount + peureuseCount + kamikazeCount + prevoyantCount + multipleCount);

    // Create Bestiole instances based on proportions
    for (int i = 0; i < gregaireCount; ++i)
        getMilieu()->addMember(Bestiole(ComportementEnum::gregaire));

    for (int i = 0; i < peureuseCount; ++i)
        getMilieu()->addMember(Bestiole(ComportementEnum::peureuse));

    for (int i = 0; i < kamikazeCount; ++i)
        getMilieu()->addMember(Bestiole(ComportementEnum::kamikaze));

    for (int i = 0; i < prevoyantCount; ++i)
        getMilieu()->addMember(Bestiole(ComportementEnum::prevoyante));

    for (int i = 0; i < multipleCount; ++i)
        getMilieu()->addMember(Bestiole(ComportementEnum::personnalitesMultiples));

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 4); // Distribution for indices 0 to 4

    std::cout << "Population pile créée" << std::endl;

    for (int i = 0; i < remainingCount; ++i)
        {
            int randomIndex = dis(gen);
            ComportementEnum randomComportement;

            switch (randomIndex)
            {
            case 0:
                randomComportement = ComportementEnum::gregaire;
                break;
            case 1:
                randomComportement = ComportementEnum::peureuse;
                break;
            case 2:
                randomComportement = ComportementEnum::kamikaze;
                break;
            case 3:
                randomComportement = ComportementEnum::prevoyante;
                break;
            case 4:
                randomComportement = ComportementEnum::personnalitesMultiples;
                break;
            }

            getMilieu()->addMember(Bestiole(randomComportement));
        }

}

  void BestioleFactory::createCreature(ComportementEnum comportementEnum)
  {
    getMilieu()->addMember(Bestiole(comportementEnum));
  }

  void BestioleFactory::cloneBestiole(const Bestiole& b)
  {
    getMilieu()->addMember(Bestiole(b));
  }