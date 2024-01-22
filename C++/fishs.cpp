#include "fishs.h"

Fish::Fish(std::string zone, int age, double health, double well_being, double hunger,
         double hydration, double energy, double social, double mental_stim, double comfort, 
        bool water, bool schooling_fish, double daily_food_requirement, bool egg_laying)
    : Animal(zone, age, health, well_being, hunger, hydration, energy, social, mental_stim, comfort) {

    this->water = water;
    this->schooling_fish = schooling_fish;
    this->daily_food_requirement = daily_food_requirement;
    this->egg_laying = egg_laying;
}

std::string Fish::getInfo(){
  return Animal::getInfo() + "\t\t\t\t" + (water ? "YES" : "NO")+ "\t\t\t\t" + (schooling_fish ? "YES" : "NO")
                           + "\t\t\t\t" + Animal::formatDouble(daily_food_requirement, 2) + "\t\t\t\t" +(egg_laying ? "YES" : "NO");
}

void Fish::divideComfortLevel(){
  //Fish often feel uncomfortable in new environments, leading to a 50% decrease in their comfort level
  Animal::setComfort(Animal::getComfort()/2);
}

void Fish::decreaseWellBeing(){
  //Adapting to a new environment can be stressful for fish, leading to a 20% reduction in well-being
  Animal::setWellBeing(Animal::getWellBeing() - 20 < 0 ? 0 : Animal::getWellBeing() - 20);
}

void Fish::checkWaterSalinity(){
  //If the fish is freshwater and the habitat is not "Coastal" or if the fish is saltwater and the habitat is "Coastal
  if((!water && Animal::getZone() == "Coastal") || (water && Animal::getZone() == "Coastal")){
    Animal::setComfort(80);
    Animal::setEnergy(80);
    Animal::setHealth(80);
  }
  else{
    Animal::setComfort(0);
    Animal::setEnergy(0);
    Animal::setHealth(0);
  }
}

void Fish::schoolMovement(int total){
  //If the fish is a schooling type, there are more than 10 fish, and mental stimulation is above 50
  if(schooling_fish && total > 10 && Animal::getMentalStim() > 50){
    Animal::setSocial(80);
  }else{
    Animal::setSocial(30);
  }
}

void Fish::feed(int total, double total_food){
  //If the daily food requirement is less than the available food divided by the fish count
  if(daily_food_requirement < total_food/total){
    //Increase hunger level by 60
    Animal::setHunger(Animal::getHunger() + 60 > 100 ? 100 : Animal::getHunger()+60);
    //Increase hydration level by 40
    Animal::setHydration(Animal::getHydration() + 40 > 100 ? 100 : Animal::getHydration()+40);
    //Decrease energy level by 20
    Animal::setEnergy(Animal::getEnergy() - 20 < 0 ? 0 : Animal::getEnergy()-20);
    //Decrease comfort level by 30
    Animal::setComfort(Animal::getComfort() - 30 < 0 ? 0 : Animal::getComfort()-30);

  }
}
