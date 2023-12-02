#ifndef _BESTIOLEFACTORY_H_
#define _BESTIOLEFACTORY_H_

#include "CreatureFactory.h"

class BestioleFactory : public CreatureFactory
{
public:
  static BestioleFactory getFactory();
  void createPopulation();
  void createCreature();

private:
  const double PROPORTIONGREGAIRE;
  const double PROPORTIONPEUREUSE;
  const double PROPORTIONKAMIKAZE;
  const double PROPORTIONPREVOYANT;
  const double PROPORTIONMULTIPLE;
  const int POPULATIONINITIAL;

  static BestioleFactory* factoryInstance;

  BestioleFactory(double gregaire, double peureuse, double kamikaze, double prevoyant, double multiple, int population);
};
#endif