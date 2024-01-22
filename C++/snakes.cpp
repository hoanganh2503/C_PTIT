#include "snakes.h"
#include <string.h>

Snake::Snake(std::string zone, int age, double health, double well_being, double hunger,
         double hydration, double energy, double social, double mental_stim, double comfort, 
          bool cold_blooded, bool sheds_skin, bool egg_laying, std::string preferred_habitat_type, 
          double length, std::string color)
    : Reptile(zone, age, health, well_being, hunger, hydration, energy, social, mental_stim, comfort, cold_blooded,
              sheds_skin, egg_laying, preferred_habitat_type) {

    this->length = length;
    this->color = color;
}

std::string Snake::getInfo(){
  return Reptile::getInfo() + "\t\t\t\t" + Animal::formatDouble(length, 2) + "\t\t\t\t" + color;
}

void Snake::checkShedding(){
  //If the snake's length is greater than 130 cm
  if(length > 130){
    Animal::setComfort(Animal::getComfort() - 20 < 0 ? 0 : Animal::getComfort() - 20);
    Animal::setMentalStim(Animal::getMentalStim() - 30 < 0 ? 0 : Animal::getMentalStim() - 30);
    Animal::setWellBeing(Animal::getWellBeing() - 50 < 0 ? 0 : Animal::getWellBeing() - 50);
  }
  if(color == "Spots"){
    Animal::setComfort(Animal::getComfort() - 10 < 0 ? 0 : Animal::getComfort() - 10);
    Animal::setMentalStim(Animal::getMentalStim() - 20 < 0 ? 0 : Animal::getMentalStim() - 20);
    Animal::setWellBeing(Animal::getWellBeing() - 25 < 0 ? 0 : Animal::getWellBeing() - 25);    
  }
}

bool Snake::checkLife(){
  //If the comfort, mental stimulation, and well-being values are all above 50,
  //the snake's living conditions are suitable.
  if(Animal::getComfort() < 50 || Animal::getMentalStim() < 50 || Animal::getWellBeing() < 50)
    return false;
  return true;

}