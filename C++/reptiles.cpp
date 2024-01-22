#include "reptiles.h"

Reptile::Reptile(std::string zone, int age, double health, double well_being, double hunger,
         double hydration, double energy, double social, double mental_stim, double comfort, 
          bool cold_blooded, bool sheds_skin, bool egg_laying, std::string preferred_sunning_spot)
    : Animal(zone, age, health, well_being, hunger, hydration, energy, social, mental_stim, comfort) {

    this->cold_blooded = cold_blooded;
    this->sheds_skin = sheds_skin;
    this->egg_laying = egg_laying;
    this->preferred_sunning_spot = preferred_sunning_spot;
}

std::string Reptile::getInfo(){
  return Animal::getInfo() + "\t\t\t\t" + (cold_blooded ? "YES" : "NO")+ "\t\t\t\t" + (sheds_skin ? "YES" : "NO")
                           + "\t\t\t\t" + (egg_laying ? "YES" : "NO") + "\t\t\t\t" + preferred_sunning_spot;
}

void Reptile::divideHydrationLevel(){
  Animal::setHydration(Animal::getHydration()/2);
}

void Reptile::divideHungerLevel(){
  Animal::setHunger(Animal::getHunger()/2);
}

void Reptile::checkTemperature(){
  if(cold_blooded && (Animal::getZone() == "Desert" || Animal::getZone() == "Forest")){
    Animal::setComfort(100);
    Animal::setEnergy(100);
    Animal::setHydration(0);
  }
  else if(!cold_blooded && (Animal::getZone() == "Wetlands" || Animal::getZone() == "Forest")){
    Animal::setComfort(100);
    Animal::setHydration(0);
  }
  else{
    Animal::setComfort(10);
    Animal::setEnergy(10);
    Animal::setHydration(90);
  }
}

void Reptile::ShedSkin(){
  if(sheds_skin){
    if(cold_blooded){
      Animal::setComfort(Animal::getComfort() + 30 > 100 ? 100 : Animal::getComfort() + 30);
      Animal::setHealth(Animal::getHealth() + 10 > 100 ? 100 : Animal::getHealth() + 10);
    }else{
      Animal::setComfort(Animal::getComfort() + 20 > 100 ? 100 : Animal::getComfort() + 20);
      Animal::setHealth(Animal::getHealth() + 20 > 100 ? 100 : Animal::getHealth() + 20);
    }
  }
}

std::string Reptile::getPreferredSunningType(){
  return preferred_sunning_spot;
}
