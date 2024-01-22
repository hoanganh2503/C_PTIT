#ifndef MAMMAL_H
#define MAMMAL_H

#include <string>
#include "animals.h"

class Mammal : public Animal {
private:
  double daily_food_requirement;
  std::string preferred_habitat_type;
  int gestation_period;
  bool nocturnal_activity;

public:
  Mammal(std::string zone, int age, double health, double well_being, double hunger,
         double hydration, double energy, double social, double mental_stim, double comfort, 
         double daily_food_requirement, std::string preferred_habitat_type, int gestation_period, bool nocturnal_activity);

  std::string getInfo();
  //getter
  double getDailyFoodRequirement();
  std::string getPreferredHabitatType();
  int getGestationPeriod();
  bool getNocturnalActivity();

  //setter
  void setDailyFoodRequirement(double value);
  void setPreferredHabitatType(std::string value);
  void setGestationPeriod(int value);
  

  //specific methods
  void divideComfortLevel();
  void divideEnergyLevel();
  void checkFoodAvailability();
  void setComfort(double comfort);

};

#endif