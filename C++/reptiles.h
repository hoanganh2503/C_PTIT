#ifndef REPTILES_H
#define REPTILES_H

#include <string>
#include "animals.h"

class Reptile : public Animal {
private:
  bool cold_blooded;
  bool sheds_skin;
  bool egg_laying;
  std::string preferred_sunning_spot;

public:
  Reptile(std::string zone, int age, double health, double well_being, double hunger,
         double hydration, double energy, double social, double mental_stim, double comfort, 
         bool cold_blooded, bool sheds_skin, bool egg_laying, std::string preferred_sunning_spot);

  std::string getInfo();
  std::string getPreferredSunningType();
  void divideHydrationLevel();
  void divideHungerLevel();
  void checkTemperature();
  void ShedSkin();
};

#endif