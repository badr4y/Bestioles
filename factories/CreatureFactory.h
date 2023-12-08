#ifndef _CREATUREFACTORY_H_
#define _CREATUREFACTORY_H_

class CreatureFactory
{
public:
  virtual void createPopulation() = 0;
  virtual void createCreature() = 0;
  virtual ~CreatureFactory() = default;

};

#endif
