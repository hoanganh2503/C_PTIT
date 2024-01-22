#include "lions.h"

Lion::Lion(std::string zone, int age, double health, double well_being, double hunger,
         double hydration, double energy, double social, double mental_stim, double comfort, 
         double daily_food_requirement, std::string preferred_habitat_type, int gestation_period, bool nocturnal_activity, 
         bool has_mane, double territory_size)
    : Mammal(zone, age, health, well_being, hunger, hydration, energy, social, mental_stim, comfort, daily_food_requirement,
              preferred_habitat_type, gestation_period, nocturnal_activity) {

    this->has_mane = has_mane;
    this->territory_size = territory_size;
}

std::string Lion::getInfo(){
  return Mammal::getInfo() + "\t\t\t\t" + (has_mane ? "YES" : "NO") + "\t\t\t\t" + Animal::formatDouble(territory_size,2);
}

void Lion::setTerritorySize(double size){
  this->territory_size = size;
}
bool Lion::checkLife(){
  if(Animal::getHunger() >= 60 or Animal::getEnergy() <= 40 or Animal::getMentalStim() <= 60 or this->territory_size <= 100)
    return false;
  return true;
} 

