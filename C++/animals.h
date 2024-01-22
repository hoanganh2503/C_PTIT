// animals.h

#ifndef ANIMALS_H
#define ANIMALS_H

#include <string>

class Animal {
private:
  double health;
  double well_being;
  double hunger;
  double hydration;
  double energy;
  double social;
  double mental_stim;
  double comfort;

public:
  std::string zone;
  int age;
  
public:
  Animal(std::string zone, int age, double health, double well_being, double hunger,
         double hydration, double energy, double social, double mental_stim, double comfort);

  std::string getInfo();
  std::string getZone();
  std::string formatDouble(double value, int precision);
  int getAge();
  double getHealth();
  double getWellBeing();
  double getHunger();
  double getHydration();
  double getEnergy();
  double getSocial();
  double getMentalStim();
  double getComfort();

  void setHealth(double tmp);
  void setWellBeing(double tmp);
  void setHunger(double tmp);
  void setHydration(double tmp);
  void setEnergy(double tmp);
  void setSocial(double tmp);
  void setMentalStim(double tmp);
  void setComfort(double tmp);

};



#endif