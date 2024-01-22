#include "elephants.h"
#include <string.h>

Elephant::Elephant(std::string zone, int age, double health, double well_being, double hunger,
         double hydration, double energy, double social, double mental_stim, double comfort, 
         double daily_food_requirement, std::string preferred_habitat_type, int gestation_period, bool nocturnal_activity, 
         int tusk_length, int trunk_dexterity)
    : Mammal(zone, age, health, well_being, hunger, hydration, energy, social, mental_stim, comfort, daily_food_requirement,
              preferred_habitat_type, gestation_period, nocturnal_activity) {

    this->tusk_length = tusk_length;
    this->trunk_dexterity = trunk_dexterity;
    checkTrunkHealth();
}

std::string Elephant::getInfo(){
  return Mammal::getInfo() + "\t\t\t\t" + std::to_string(tusk_length) + "\t\t\t\t" + std::to_string(trunk_dexterity);
}

void Elephant::checkTrunkHealth(){
  if((tusk_length + trunk_dexterity) % 2 == 0) Animal::setHealth(100);
  else Animal::setHealth(0);
}

bool Elephant::checkLife(){
  if(Animal::getHunger() >= 80 or Animal::getEnergy() <= 30 or Animal::getMentalStim() <= 20 or Animal::getHealth() <= 20)
    return false;
  return true;
}

