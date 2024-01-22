#include "turtles.h"
#include <string.h>

Turtle::Turtle(std::string zone, int age, double health, double well_being, double hunger,
         double hydration, double energy, double social, double mental_stim, double comfort, 
          bool cold_blooded, bool sheds_skin, bool egg_laying, std::string preferred_habitat_type, 
         double shell_length, int nesting_frequency)
    : Reptile(zone, age, health, well_being, hunger, hydration, energy, social, mental_stim, comfort, cold_blooded,
              sheds_skin, egg_laying, preferred_habitat_type) {

    this->shell_length = shell_length;
    this->nesting_frequency = nesting_frequency;
}

std::string Turtle::getInfo(){
  return Reptile::getInfo() + "\t\t\t\t" + Animal::formatDouble(shell_length, 2) + "\t\t\t\t" + std::to_string(nesting_frequency);
}

void Turtle::divideComfortLevel(){
  Animal::setComfort(Animal::getComfort() - 50 < 0 ? 0 :Animal::getComfort() - 50);
}

void Turtle::divideHungerLevel(){
  Animal::setHunger(Animal::getHunger() - 50 < 0 ? 0 :Animal::getHunger() - 50);
}

void Turtle::checkNestingGrounds(){
  // If the Shell Length is less than 100 cm or the Nesting Frequency is 5 times or less per year, 
  //reduce the turtle's comfort, social interaction, and energy levels by half.
  if(shell_length < 100 || nesting_frequency < 5){
    Animal::setComfort(Animal::getComfort()/2);
    Animal::setSocial(Animal::getSocial()/2);
    Animal::setEnergy(Animal::getEnergy()/2);
  }
}

bool Turtle::checkLife(){
  //If the comfort level is greater than 30 and the social interaction level is greater than 20,
  // the turtle's living conditions are suitable
  if(Animal::getComfort() <= 30 || Animal::getSocial() <= 20) return false;
  return true;
}