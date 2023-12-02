#include "BestioleFactory.h"
#include "Milieu.h"
#include "Aquarium.h"

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

static BestioleFactory &BestioleFactory::getFactory()
{
    if (factoryInstance == nullptr)
    {
        double gregaire;
        double peureuse;
        double kamikaze;
        double prevoyant;
        double multiple;
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
        Aquarium.getMilieu().addMember(Bestiole(/* parameters for Gregaire */));

    for (int i = 0; i < peureuseCount; ++i)
        Aquarium.getMilieu().addMember(Bestiole(/* parameters for Peureuse */));

    for (int i = 0; i < kamikazeCount; ++i)
        Aquarium.getMilieu().addMember(Bestiole(/* parameters for Kamikaze */));

    for (int i = 0; i < prevoyantCount; ++i)
        Aquarium.getMilieu().addMember(Bestiole(/* parameters for Prevoyant */));

    for (int i = 0; i < multipleCount; ++i)
        Aquarium.getMilieu().addMember(Bestiole(/* parameters for Multiple */));

    // Add remaining Bestiole instances randomly
    for (int i = 0; i < remainingCount; ++i)
        Aquarium.getMilieu().addMember(Bestiole(/* parameters for a random type */));
}


void BestioleFactory::createCreature()
{
    Aquarium.getMilieu.addMember(Bestiole());
}
