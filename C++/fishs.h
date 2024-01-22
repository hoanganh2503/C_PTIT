#ifndef FISHS_H
#define FISHS_H

#include <string>
#include "animals.h"

class Fish : public Animal {
private:
  bool water;
  bool schooling_fish;
  double daily_food_requirement;
  bool egg_laying;

public:
  Fish(std::string zone, int age, double health, double well_being, double hunger,
         double hydration, double energy, double social, double mental_stim, double comfort, 
         bool water, bool schooling_fish, double daily_food_requirement, bool egg_laying);

  std::string getInfo();
  void divideComfortLevel();
  void decreaseWellBeing();
  void checkWaterSalinity();
  void schoolMovement(int total);
  void feed(int total, double total_food);
};

#endif