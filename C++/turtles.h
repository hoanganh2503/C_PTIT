#ifndef TURTLES_H
#define TURTLES_H

#include <string>
#include "reptiles.h"

class Turtle : public Reptile{
private:
  double shell_length;
  int nesting_frequency;

public:
  Turtle(std::string zone, int age, double health, double well_being, double hunger,
         double hydration, double energy, double social, double mental_stim, double comfort, 
         bool cold_blooded, bool sheds_skin, bool egg_laying, std::string preferred_habitat_type, 
         double shell_length, int nesting_frequency);

  std::string getInfo();
  void divideHungerLevel();
  void divideComfortLevel();
  void checkNestingGrounds();
  bool checkLife();
  
};

#endif