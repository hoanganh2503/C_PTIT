#include "zones.h"
#include <string>
#include <iostream>

//Constructer
Zone::Zone(std::string name, std::string habitat, double food_availability, double size, std::string sunny_spots) {
  this->name = name;
  this->habitat = habitat;
  this->food_availability = food_availability;
  this->size = size;
  this->sunny_spots = sunny_spots;
}

//Getter
std::string Zone::getName(){
  return name;
}

std::string Zone::getHabitat(){
  return habitat;
}

double Zone::getFoodAvailability() {
  return food_availability;
}

double Zone::getSize() {
  return size;
}

std::string Zone::getSunnySpots(){
  return sunny_spots;
}

//setter
void Zone::setName(std::string value) {
  this->name = value;
}

void Zone::setHabitat(std::string value) {
  this->habitat = value;
}

void Zone::setFoodAvailability(double value) {
  this->food_availability = value;
}

void Zone::setSize(double value) {
  this->size = value;
}

void Zone::setSunnySpots(std::string value) {
  this->sunny_spots = value;
}


std::string Zone::getInfo(){
  return name + "\t\t\t\t" + habitat + "\t\t\t\t" + formatDouble(food_availability, 2) + "\t\t\t\t"
                     + formatDouble(size, 2) + "\t\t\t\t" + sunny_spots;
}

std::string Zone::formatDouble(double value, int precision) {
    std::string str = std::to_string(value);
    size_t decimal_pos = str.find('.');

    if (decimal_pos != std::string::npos && decimal_pos + precision + 1 < str.length()) {
        str = str.substr(0, decimal_pos + precision + 1);
    }

    return str;
}