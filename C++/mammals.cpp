#include "mammals.h"
#include <iostream>

Mammal::Mammal(std::string zone, int age, double health, double well_being, double hunger,
         double hydration, double energy, double social, double mental_stim, double comfort, 
         double daily_food_requirement, std::string preferred_habitat_type, int gestation_period, bool nocturnal_activity)
    : Animal(zone, age, health, well_being, hunger, hydration, energy, social, mental_stim, comfort) {

    this->daily_food_requirement = daily_food_requirement;
    this->preferred_habitat_type = preferred_habitat_type;
    this->gestation_period = gestation_period;
    this->nocturnal_activity = nocturnal_activity;
}

std::string Mammal::getInfo(){
  return Animal::getInfo() + "\t\t\t\t" + Animal::formatDouble(daily_food_requirement, 2) + "\t\t\t\t" + preferred_habitat_type
                           + "\t\t\t\t" + std::to_string(gestation_period) + "\t\t\t\t" +(nocturnal_activity ? "YES" : "NO");
}

void Mammal::divideComfortLevel(){
  Animal::setComfort(Animal::getComfort() - 50 < 0 ? 0 :Animal::getComfort() - 50);
}

void Mammal::divideEnergyLevel(){
  Animal::setEnergy(Animal::getEnergy() - 50 < 0 ? 0 :Animal::getEnergy() - 50);
}

void Mammal::checkFoodAvailability(){
  Animal::setHunger(60);
  Animal::setHydration(40);
  Animal::setEnergy(15);
  Animal::setComfort(25);
}

double Mammal::getDailyFoodRequirement() {
  return daily_food_requirement;
}

std::string Mammal::getPreferredHabitatType() {
  return preferred_habitat_type;
}

int Mammal::getGestationPeriod() {
  return gestation_period;
}

bool Mammal::getNocturnalActivity() {
  return nocturnal_activity;
}

void Mammal::setDailyFoodRequirement(double value) {
  this->daily_food_requirement = value;
}

void Mammal::setPreferredHabitatType(std::string value) {
  this->preferred_habitat_type = value;
}

void Mammal::setGestationPeriod(int value) {
  this->gestation_period = value;
}
