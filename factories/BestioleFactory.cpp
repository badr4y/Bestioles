// BestioleFactory.cpp
#include "BestioleFactory.h"
#include "Milieu.h"
#include "Aquarium.h"

BestioleFactory* BestioleFactory::factoryInstance = nullptr;

BestioleFactory::BestioleFactory(int population) : POPULATIONINITIAL(population)
{
}

BestioleFactory& BestioleFactory::getFactory()
{
    if (factoryInstance == nullptr)
    {
        int population;
        std::cout << "Enter the initial population mass: ";
        std::cin >> population;
        factoryInstance = new BestioleFactory(population);
    }
    return *factoryInstance;
}

void BestioleFactory::createPopulation()
{
    for (int i = 0; i <= POPULATIONINITIAL; ++i)
        Aquarium::getMilieu().addMember(Bestiole());
}

void BestioleFactory::createCreature()
{
    Aquarium::getMilieu().addMember(Bestiole());
}

void BestioleFactory::cloneBestiole(const Bestiole& b)
{
    Aquarium::getMilieu().addMember(Bestiole(b));
}
