// BestioleFactory.h
#ifndef _BESTIOLEFACTORY_H_
#define _BESTIOLEFACTORY_H_

#include "CreatureFactory.h"

class Bestiole;


class BestioleFactory : public CreatureFactory
{
public:
	static BestioleFactory& getFactory();
	void createPopulation();
	void createCreature();
	void cloneBestiole(const Bestiole& b);

private:
	const int POPULATIONINITIAL;
	static BestioleFactory* factoryInstance;

	BestioleFactory(int population);
};

#endif
