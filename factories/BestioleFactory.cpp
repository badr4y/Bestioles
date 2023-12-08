#include "BestioleFactory.h"
#include "Milieu.h"
#include "Aquarium.h"
#include "ComportementEnum.h"

BestioleFactory *BestioleFactory::factoryInstance = nullptr;

BestioleFactory::BestioleFactory(double gregaire, double peureuse, double kamikaze, double prevoyant, double multiple, int population)
    : PROPORTIONGREGAIRE(gregaire),
      PROPORTIONPEUREUSE(peureuse),
      PROPORTIONKAMIKAZE(kamikaze),
      PROPORTIONPREVOYANT(prevoyant),
      PROPORTIONMULTIPLE(multiple),
      POPULATIONINITIAL(population)
{
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

static BestioleFactory &BestioleFactory::getFactory()
{
  if (factoryInstance == nullptr)
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
    factoryInstance = new BestioleFactory(gregaire, peureuse, kamikaze, prevoyant, multiple, population);
  }
  return *factoryInstance;
}

void BestioleFactory::createPopulation()
{
    int gregaireCount = static_cast<int>(POPULATIONINITIAL * PROPORTIONGREGAIRE);
    int peureuseCount = static_cast<int>(POPULATIONINITIAL * PROPORTIONPEUREUSE);
    int kamikazeCount = static_cast<int>(POPULATIONINITIAL * PROPORTIONKAMIKAZE);
    int prevoyantCount = static_cast<int>(POPULATIONINITIAL * PROPORTIONPREVOYANT);
    int multipleCount = static_cast<int>(POPULATIONINITIAL * PROPORTIONMULTIPLE);

    int remainingCount = POPULATIONINITIAL - (gregaireCount + peureuseCount + kamikazeCount + prevoyantCount + multipleCount);

    // Create Bestiole instances based on proportions
    for (int i = 0; i < gregaireCount; ++i)
        Aquarium::getMilieu().addMember(Bestiole(ComportementEnum::gregaire));

    for (int i = 0; i < peureuseCount; ++i)
        Aquarium::getMilieu().addMember(Bestiole(ComportementEnum::peureuse));

    for (int i = 0; i < kamikazeCount; ++i)
        Aquarium::getMilieu().addMember(Bestiole(ComportementEnum::kamikaze));

    for (int i = 0; i < prevoyantCount; ++i)
        Aquarium::getMilieu().addMember(Bestiole(ComportementEnum::peureuse));

    for (int i = 0; i < multipleCount; ++i)
        Aquarium::getMilieu().addMember(Bestiole(ComportementEnum::peureuse));

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 4); // Distribution for indices 0 to 4

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

            Aquarium::getMilieu().addMember(Bestiole(randomComportement));
        }

}

  void BestioleFactory::createCreature(ComportementEnum comportementEnum)
  {
    Aquarium::getMilieu.addMember(Bestiole(comportementEnum));
  }

  void BestioleFactory::cloneBestiole(const Bestiole& b)
  {
    Aquarium::getMilieu.addMember(Bestiole(b));
  }