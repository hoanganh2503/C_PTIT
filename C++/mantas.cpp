#include "mantas.h"
#include <string.h>

Manta::Manta(std::string zone, int age, double health, double well_being, double hunger,
         double hydration, double energy, double social, double mental_stim, double comfort, 
         bool water, bool schooling_fish, double daily_food_requirement, bool egg_laying, 
         int wing_span, bool filter_feeder)
    : Fish(zone, age, health, well_being, hunger, hydration, energy, social, mental_stim, comfort,
        water, schooling_fish, daily_food_requirement, egg_laying) {

    this->wing_span = wing_span;
    this->filter_feeder = filter_feeder;
}

std::string Manta::getInfo(){
  return Fish::getInfo() + "\t\t\t\t" + std::to_string(wing_span) + "\t\t\t\t" + (filter_feeder ? "YES" : "NO");
}

void Manta::checkPlanktonAvailability(int amount_food, int total_manta){
  double tmp = (double)amount_food/(double)total_manta;
  if(wing_span > 100 && filter_feeder){
    // If the manta ray's wing span is greater than 100 cm and it is a filter feeder,
    // its hunger level increases by the amount of food divided by the number of Manta Rays
    Animal::setHunger(Animal::getHunger() + tmp > 100 ? 100 : Animal::getHunger() + tmp);

  }else if(wing_span > 80 && filter_feeder){
    // If the manta ray's wing span is greater than 80 cm and it is a filter feeder, 
    // its hunger level decreases by the amount of food divided by the number of Manta Rays
    Animal::setHunger(Animal::getHunger() - tmp < 0 ? 0 : Animal::getHunger() - tmp);

  }else{
    //Otherwise, its hunger level increases by 50 units.
    Animal::setHunger(Animal::getHunger() + 50 > 100 ? 100 : Animal::getHunger() + 50);
  }
}

bool Manta::checkLife(){
  //If the manta ray's hunger level is below 90, it is considered to be in suitable living conditions.
  if(Animal::getHunger() >= 90) return false;
  else return true;
}