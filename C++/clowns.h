#ifndef CLOWNS_H
#define CLOWNS_H

#include <string>
#include "fishs.h"

class Clown : public Fish{
private:
  bool symbiotic_relationship;
  int stripe_pattern;

public:
  Clown(std::string zone, int age, double health, double well_being, double hunger,
         double hydration, double energy, double social, double mental_stim, double comfort, 
         bool water, bool schooling_fish, double daily_food_requirement, bool egg_laying, 
         bool symbiotic_relationship, int stripe_pattern);

  std::string getInfo();
  void checkAnemoneHealth();
  bool checkLife();

};

#endif 