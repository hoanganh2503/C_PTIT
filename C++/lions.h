#ifndef LION_H
#define LION_H

#include <string>
#include "mammals.h"

class Lion : public Mammal{
private:
  bool has_mane;
  double territory_size;

public:
  Lion(std::string zone, int age, double health, double well_being, double hunger,
         double hydration, double energy, double social, double mental_stim, double comfort, 
         double daily_food_requirement, std::string preferred_habitat_type, int gestation_period, bool nocturnal_activity, 
         bool has_mane, double territory_size);

  std::string getInfo();
  void setTerritorySize(double size);
  bool checkLife();

};

#endif