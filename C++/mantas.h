#ifndef MANTAS_H
#define MANTAS_H

#include <string>
#include "fishs.h"

class Manta : public Fish{
private:
  int wing_span;
  bool filter_feeder;

public:
  Manta(std::string zone, int age, double health, double well_being, double hunger,
         double hydration, double energy, double social, double mental_stim, double comfort, 
         bool water, bool schooling_fish, double daily_food_requirement, bool egg_laying, 
         int wing_span, bool filter_feeder);

  std::string getInfo();
  void checkPlanktonAvailability(int amount_food, int total_manta);
  bool checkLife();

};

#endif