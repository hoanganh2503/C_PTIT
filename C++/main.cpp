#include <iostream>
#include <fstream> 
#include <stdio.h> 
#include <string> 
#include <vector> 
#include <array> 
#include <stdlib.h> 
#include <cmath> 

#include "lions.h"
#include "elephants.h"
#include "turtles.h"
#include "snakes.h"
#include "clowns.h"
#include "mantas.h"
#include "zones.h"

std::vector<Lion> lions;
std::vector<Elephant> elephants;
std::vector<Turtle> turtles;
std::vector<Snake> snakes;
std::vector<Clown> clowns;
std::vector<Manta> mantas;
std::vector<Zone> zones;
std::ofstream outputFile("output.txt");
  FILE *a =fopen("output.txt", "w");

  // 2. Open a file and check if it exists
  // a = 
  // if (a == NULL) {
  //     printf("Error: Unable to open the file.\n");
  //     return 1;
  // }


void initAnimals(){
  for(int i = 0; i < 5 ; i ++){
    if(i%2 == 0){
      Lion a = Lion("Whispering Woods", 2, 100, 100, 0, 0, 100, 100, 100, 100, 22.2, "Forest", 50, false, true, 0);
      lions.push_back(a);
    }
    else{
      Lion a = Lion("Whispering Woods", 2, 100, 100, 0, 0, 100, 100, 100, 100, 22.2, "Oceans", 50, false, false, 0);
      lions.push_back(a);
    }
  }

  for(int i = 0; i < 3; i ++){
    if(i%2 == 0){
      Elephant a = Elephant("Savannah Safari", 2, 100, 100, 0, 0, 100, 100, 100, 100, 65.2, "Grassland", 100, false, 100, 100);
      elephants.push_back(a);         
    }else{
      Elephant a = Elephant("Savannah Safari", 2, 100, 100, 0, 0, 100, 100, 100, 100, 65.2, "Grassland", 100, false, 101, 100);
      elephants.push_back(a);         
    }

  }

  for(int i = 0; i < 4; i ++){
    if(i%2 == 0){
      Turtle a = Turtle("Coral Cove", 2, 100, 100, 0, 0, 100, 100, 100, 100, false, true, true, "Rock", 101, 100);
      turtles.push_back(a);
    }else{
      Turtle a = Turtle("Coral Cove", 2, 100, 100, 0, 0, 100, 100, 100, 100, false, true, true, "Log", 99, 100);
      turtles.push_back(a);      
    }
       
  }

  for(int i = 0; i < 8; i ++){
    Snake a = Snake("Lagoon Landing", 2, 100, 100, 0, 0, 100, 100, 100, 100, false, true, false, "Log", 140, "Spots");
    snakes.push_back(a);   
  }

  for(int i = 0; i < 6; i ++){
    Clown a = Clown("Coral Cove", 1, 100, 100, 0, 0, 100, 100, 100, 100, false, true, 1.2, false, true, 3);
    clowns.push_back(a);   
  }

  for(int i = 0; i < 10; i ++){
    Manta a = Manta("Coral Cove", 1, 100, 100, 0, 0, 100, 100, 100, 100, false, true, 1.2, false, 101, true);
    a.checkPlanktonAvailability(452, 10);
    mantas.push_back(a);   
  }
}

void initZones(){
  Zone a = Zone("Whispering Woods", "Forest", 350, 305, "Rock");
  Zone b = Zone("Savannah Safari", "Grassland", 400, 50, "Mound");
  Zone c = Zone("Sunbaked Sands", "Desert", 150, 20, "Sand Dune");
  Zone d = Zone("Lagoon Landing", "Wetlands", 200, 30, "Log");
  Zone e = Zone("Coral Cove", "Coastal", 500, 90, "Rock");
  zones.push_back(a);
  zones.push_back(b);
  zones.push_back(c);
  zones.push_back(d);
  zones.push_back(e);

}

void initValue(){
  initAnimals();
  initZones();
}

void printLions(){
  outputFile << "Lions\t\t\t Total: " << lions.size() << std::endl;
  std::string s = "Health\t\t\t\tWell Being\t\t\t\tHunger\t\t\t\tHydration\t\t\tEnergy\t\t\t\tSocial\t\t\t\tMentalStim\t\t\tComfort";
      fprintf(a, "\nValue: %.2f", 42000000);

  for(auto it:lions){
    outputFile << it.getHealth()  << it.getComfort()<< std::endl;
  }
  outputFile << "\n";
}

void printElephants(){
  outputFile << "Elephants\t\t\t Total: " << elephants.size() << std::endl;
  std::string s = "Health\t\t\t\tWell Being\t\t\t\tHunger\t\t\t\tHydration\t\t\tEnergy\t\t\t\tSocial\t\t\t\tMentalStim\t\t\tComfort";
  outputFile << s << std::endl;
  for(auto it:elephants){
    outputFile << it.getInfo() << std::endl;
  }
  outputFile << "\n";
}

void printTurtles(){
  outputFile << "Turtles\t\t\t Total: " << turtles.size() << std::endl;
  std::string s = "Health\t\t\t\tWell Being\t\t\t\tHunger\t\t\t\tHydration\t\t\tEnergy\t\t\t\tSocial\t\t\t\tMentalStim\t\t\tComfort";
  outputFile << s << std::endl; 
  for(auto it:turtles){
    outputFile << it.getInfo() << std::endl;
  }
  outputFile << "\n";
}

void printSnakes(){
  outputFile << "Snakes\t\t\t Total: " << snakes.size() << std::endl;
  std::string s = "Health\t\t\t\tWell Being\t\t\t\tHunger\t\t\t\tHydration\t\t\tEnergy\t\t\t\tSocial\t\t\t\tMentalStim\t\t\tComfort";
  outputFile << s << std::endl; 
  for(auto it:snakes){
    outputFile << it.getInfo() << std::endl;
  }
  outputFile << "\n";
}

void printClowns(){
  outputFile << "Clowns\t\t\t Total: " << clowns.size() << std::endl;
  std::string s = "Health\t\t\t\tWell Being\t\t\t\tHunger\t\t\t\tHydration\t\t\tEnergy\t\t\t\tSocial\t\t\t\tMentalStim\t\t\tComfort";
  outputFile << s << std::endl; 
  for(auto it:clowns){
    outputFile << it.getInfo() << std::endl;
  }
  outputFile << "\n";
}

void printMantas(){
  outputFile << "Mantas\t\t\t Total: " << mantas.size() << std::endl;
  std::string s = "Health\t\t\t\tWell Being\t\t\t\tHunger\t\t\t\tHydration\t\t\tEnergy\t\t\t\tSocial\t\t\t\tMentalStim\t\t\tComfort";
  outputFile << s << std::endl; 
  for(auto it:mantas){
    outputFile << it.getInfo() << std::endl;
  }
  outputFile << "\n";
}

void printZones(){
  outputFile << "Zones\t\t\t Total: " << zones.size() << std::endl;
  std::string s = "Name\t\t\t\tHabitat\t\t\t\tDaily Food\t\t\tSize\t\t\t\tSunny Spots";
  outputFile << s << std::endl; 
  for(auto it:zones){
    outputFile << it.getInfo() << std::endl;
  }
  outputFile << "\n";
}

void PrintProperties(){
  if (outputFile.is_open()) {
    outputFile << " ################################# After 1 month ################################### \n\n";
    printLions();
    printElephants();
    printTurtles();
    printSnakes();
    printClowns();
    printMantas();
    outputFile << " ################################# Animal Check ################################### \n\n";
    // printZones();
  } else {
    std::cout << "Unable to open output.txt." << std::endl;
  }

}
//----------------------------------- Actions for Lion -----------------------------------
void checkTerriroty(){
  int zone_sz;
  for(auto &it:lions){
    std::string zone = it.getZone();
    for(auto it2:zones){
      if(it2.getName() == zone){
         zone_sz = it2.getSize();
         break;
      }
    }
  }
  for(auto &it:lions){
    it.setTerritorySize(zone_sz/lions.size());
  }
}

void adaptingEnvironment(){
  for(auto &it:lions){
    int zone_sz;
    std::string preferred_habitat = it.getPreferredHabitatType();
    std::string zone = it.getZone();
    //Adapting to a new environment can be energy-draining for lions, leading to a 50% reduction in energy levels.
    std::string  zone_type;
    for(auto it2:zones){
      if(it2.getName() == zone){
         zone_type = it2.getHabitat();
         zone_sz = it2.getSize();
         break;
      }
    }
    if(zone_type != preferred_habitat){
      it.divideEnergyLevel();
    }
  }  
}

void checkLifeLions(){
 for (int i = 0; i < lions.size(); i++) {
    if (!lions[i].checkLife()) {
        lions.erase(lions.begin() + i);
        i--;
        checkTerriroty();
    }
  }
}

void actionsForLion(){
  //Adapting to a new environment
  adaptingEnvironment();
  //Check Territory
  checkTerriroty();
  //Check Life
  checkLifeLions();
}


//----------------------------------- Actions for Elephant -----------------------------------
void checkTrunkHealth(){
  for(auto &it:elephants){
    it.checkTrunkHealth();
  }
}

void checkLifeElephant(){
 for (int i = 0; i < elephants.size(); i++) {
    if (!elephants[i].checkLife()) {
        elephants.erase(elephants.begin() + i);
        i--;
    }
  }
}

void actionsForElephant(){
  checkTrunkHealth();
  checkLifeElephant();
}


//----------------------------------- Actions for Turtle -----------------------------------
void adaptingEnvironmentTurtle(){
  for(auto &it:turtles){
    std::string preferred_sunning = it.getPreferredSunningType();
    std::string zone = it.getZone();
    std::string sunny_type;
    for(auto it2:zones){
      if(it2.getName() == zone){
         sunny_type = it2.getSunnySpots();
         break;
      }
    }
    if(sunny_type != preferred_sunning){
      it.divideHungerLevel();
      it.divideComfortLevel();
    }
  }  
}

void checkNestingGrounds(){
  for(auto &it:turtles){
    it.checkNestingGrounds();
  }
}

void checkLifeTurtle(){
 for (int i = 0; i < turtles.size(); i++) {
    if (!turtles[i].checkLife()) {
        turtles.erase(turtles.begin() + i);
        i--;
    }
  }
}

void actionsForTurtle(){
  adaptingEnvironmentTurtle();
  checkNestingGrounds();
  checkLifeTurtle();
}


//----------------------------------- Actions for Snake -----------------------------------
void checkShedding(){
  for(auto &it:snakes){
    it.checkShedding();
  }
}

void checkLifeSnake(){
 for (int i = 0; i < snakes.size(); i++) {
    if (!snakes[i].checkLife()) {
        snakes.erase(snakes.begin() + i);
        i--;
    }
  }
}

void actionsForSnake(){
    checkShedding();
    checkLifeSnake();
}


//----------------------------------- Actions for Clown -----------------------------------
void checkAnemoneHealth(){
  for(auto &it:clowns){
    it.checkAnemoneHealth();
  }
}

void checkLifeClown(){
 for (int i = 0; i < clowns.size(); i++) {
    if (!clowns[i].checkLife()) {
        clowns.erase(clowns.begin() + i);
        i--;
    }
  }
}

void actionsForClown(){
  checkAnemoneHealth();
  checkLifeClown();
}


//----------------------------------- Actions for Clown -----------------------------------
void checkPlanktonAvailability(){
  for(auto &it:mantas){
    it.checkPlanktonAvailability(400, mantas.size());
  }
}

void checkLifeManta(){
 for (int i = 0; i < mantas.size(); i++) {
    if (!mantas[i].checkLife()) {
        mantas.erase(mantas.begin() + i);
        i--;
    }
  }
}

void actionsForManta(){
  checkPlanktonAvailability();
  checkLifeManta();
}

void One_Month(){
  int cnt_lion = lions.size();
  int cnt_elephant = elephants.size();
  int cnt_turtle = turtles.size();
  int cnt_snake = snakes.size();
  int cnt_clown = clowns.size();
  int cnt_manta = mantas.size();

  actionsForLion();
  actionsForElephant();
  actionsForTurtle();
  actionsForSnake();
  actionsForClown();
  actionsForManta();
  for(int i = 0 ; i < cnt_lion - lions.size() ; i++){
    outputFile << i << " Lion Death\n";
  }
  for(int i = 0 ; i < cnt_elephant -elephants.size() ; i++){
    outputFile << i << " Elephant Death\n";
  }
  for(int i = 0 ; i < cnt_turtle -turtles.size() ; i++){
    outputFile << i << " Turtle Death\n";
  }
  for(int i = 0 ; i < cnt_snake -snakes.size() ; i++){
    outputFile << i << " Snake Death\n";
  }
  for(int i = 0 ; i < cnt_clown -clowns.size() ; i++){
    outputFile << i << " Clown Fish Death\n";
  }
  for(int i = 0 ; i < cnt_manta -mantas.size() ; i++){
    outputFile << i << " Manta Ray Death\n";
  }
  outputFile <<"\n\n\n";
}


int main(){

  initValue();
  outputFile << " ################################# Initial Values ################################### \n";
  PrintProperties();
  One_Month();
  PrintProperties();
  outputFile.close();
  return 1;
}
