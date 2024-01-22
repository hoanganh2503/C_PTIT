#ifndef ELEPHANT_H
#define ELEPHANT_H

#include <string>
#include "mammals.h"

class Elephant : public Mammal{
private:
  int tusk_length;
  int trunk_dexterity;

public:
  Elephant(std::string zone, int age, double health, double well_being, double hunger,
         double hydration, double energy, double social, double mental_stim, double comfort, 
         double daily_food_requirement, std::string preferred_habitat_type, int gestation_period, bool nocturnal_activity, 
         int tusk_length, int trunk_dexterity);

  std::string getInfo();
  void checkTrunkHealth();
  bool checkLife();

};

#endif