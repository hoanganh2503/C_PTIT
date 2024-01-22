#include "clowns.h"
#include <string.h>
#include <stdlib.h>

Clown::Clown(std::string zone, int age, double health, double well_being, double hunger,
         double hydration, double energy, double social, double mental_stim, double comfort, 
         bool water, bool schooling_fish, double daily_food_requirement, bool egg_laying, 
         bool symbiotic_relationship, int stripe_pattern)
    : Fish(zone, age, health, well_being, hunger, hydration, energy, social, mental_stim, comfort,
        water, schooling_fish, daily_food_requirement, egg_laying) {

    this->symbiotic_relationship = symbiotic_relationship;
    this->stripe_pattern = stripe_pattern;
}

std::string Clown::getInfo(){
  return Fish::getInfo() + "\t\t\t\t" + (symbiotic_relationship ? "YES" : "NO") + "\t\t\t\t" + std::to_string(stripe_pattern);
}

//Determines if the sea anemone, with which the clownfish has a symbiotic relationship, is healthy.
void Clown::checkAnemoneHealth(){
  if(symbiotic_relationship){
    //If the clownfish has a symbiotic relationship
    if(stripe_pattern == 1){
    //Has 1 stripe: Decrease social interaction by 20%, increase comfort by 20%, and double the hunger. 
      Animal::setSocial(Animal::getSocial() - 20 < 0 ? 0 : Animal::getSocial() - 20);
      Animal::setComfort(Animal::getComfort() + 20 > 100 ? 100 : Animal::getComfort() + 20);
      Animal::setHunger(Animal::getHunger()*2 > 100 ? 100 : Animal::getHunger() * 2);

    }else if(stripe_pattern == 2){
      //Has 2 stripes: Increase social interaction by 90%, increase comfort by 60%, and halve the hunger
      Animal::setSocial(Animal::getSocial() + 90 > 100 ? 100 : Animal::getSocial() + 90);
      Animal::setComfort(Animal::getComfort() + 60 > 100 ? 100 : Animal::getComfort() + 60);
      Animal::setHunger(Animal::getHunger()/2);

    }else if(stripe_pattern == 3){
      //Has 3 stripes: Increase social interaction by 20%, decrease comfort by 50%, and double the hunger.
      Animal::setSocial(Animal::getSocial() + 20 > 100 ? 100 : Animal::getSocial() + 20);
      Animal::setComfort(Animal::getComfort() - 50 < 0 ? 0 : Animal::getComfort() - 50);
      Animal::setHunger(Animal::getHunger()*2 > 100 ? 100 : Animal::getHunger() * 2);

    }else if(stripe_pattern == 4){
      //Has 4 stripes: Double the social interaction, increase comfort by 30%, and reduce hunger to one-third.
      Animal::setSocial(Animal::getSocial()*2 > 100 ? 100 : Animal::getSocial()*2);
      Animal::setComfort(Animal::getComfort() + 30 > 100 ? 100 : Animal::getComfort() + 30);
      Animal::setHunger(Animal::getHunger()/3);
    }
  }
  else{
    //If the clownfish does not have a symbiotic relationship
    if(stripe_pattern == 1 or stripe_pattern == 4){
      //Has 1 or 4 stripes: Reduce social interaction to one-third, decrease comfort by 30%, and triple the hunger.
      Animal::setSocial(Animal::getSocial()/2);
      Animal::setComfort(Animal::getComfort() - 30 < 0 ? 0 : Animal::getComfort() - 30);
      Animal::setHunger(Animal::getHunger()*3 > 100 ? 100  : Animal::getHunger()*3);

    }
    else if(stripe_pattern == 2 or stripe_pattern == 3){
      //Decrease social interaction by 7%, decrease comfort to 0 (or by 100%), and multiply hunger by 50.
      Animal::setSocial(Animal::getSocial() - 7 < 0 ? 0 : Animal::getSocial() - 7);
      Animal::setComfort(0);
      Animal::setHunger(Animal::getHunger()*50 > 100 ? 100  : Animal::getHunger()*50);
      
    }
  }

}

bool Clown::checkLife(){
  //If the clownfish's comfort level is above 50, its social interaction level is above 50, 
  //and its well-being percentage (from the Animal class) is above 50, the clownfish is considered 
  //to be in suitable living conditions.
  if(Animal::getComfort() < 50 || Animal::getSocial() < 50 || Animal::getWellBeing() < 50) return false;
  else return true;
} 