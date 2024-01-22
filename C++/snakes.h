#ifndef SNAKES_H
#define SNAKES_H

#include <string>
#include "reptiles.h"

class Snake : public Reptile{
private:
  double length;
  std::string color;

public:
  Snake(std::string zone, int age, double health, double well_being, double hunger,
         double hydration, double energy, double social, double mental_stim, double comfort, 
         bool cold_blooded, bool sheds_skin, bool egg_laying, std::string preferred_habitat_type, 
         double length, std::string color);

  std::string getInfo();
  void checkShedding();
  bool checkLife();

};

#endif