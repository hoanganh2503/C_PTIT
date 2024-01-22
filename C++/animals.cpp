#include "animals.h"
#include <string>
#include <iostream>

//Constructer
Animal::Animal(std::string zone, int age, double health, double well_being, double hunger,
         double hydration, double energy, double social, double mental_stim, double comfort) {
  // this->zone: trỏ tới thuộc tính zone của Animal; zone: zone lấy giá trị từ hàm
  // this->zone = zone: gán giá trị zone trong class Animal = giá trị zone được truyền vào từ hàm
  // ban đầu thì các thuộc tính chưa có giá trị, vậy nên cần gán các giá trị khởi tạo cho nó thông qua cú pháp
  // this->att = att
  this->zone = zone;
  this->age = age;
  this->health = health;
  this->well_being = well_being;
  this->hunger = hunger;
  this->hydration = hydration;
  this->energy = energy;
  this->social = social;
  this->mental_stim = mental_stim;
  this->comfort = comfort;
}

//Getter
int Animal::getAge(){
  return age;
}

std::string Animal::getZone(){
  return zone;
}

double Animal::getHealth() {
  return health;
}

double Animal::getWellBeing() {
  return well_being;
}

double Animal::getHunger() {
  return hunger;
}

double Animal::getHydration() {
  return hydration;
}

double Animal::getEnergy() {
  return energy;
}

double Animal::getSocial() {
  return social;
}

double Animal::getMentalStim() {
  return mental_stim;
}

double Animal::getComfort() {
  return comfort;
}

//setter
void Animal::setHealth(double tmp) {
  this->health = tmp;
}

void Animal::setWellBeing(double tmp) {
  this->well_being = tmp;
}

void Animal::setHunger(double tmp) {
  this->hunger = tmp;
}

void Animal::setHydration(double tmp) {
  this->hydration = tmp;
}

void Animal::setEnergy(double tmp) {
  this->energy = tmp;
}

void Animal::setSocial(double tmp) {
  this->social = tmp;
}

void Animal::setMentalStim(double tmp) {
  this->mental_stim = tmp;
}

void Animal::setComfort(double tmp) {
  this->comfort = tmp;
}


std::string Animal::getInfo(){
  return  formatDouble(health, 2) + "\t\t\t\t"
          + formatDouble(well_being, 2) + "\t\t\t\t" + formatDouble(hunger, 2) + "\t\t\t\t"
          + formatDouble(hydration, 2) + "\t\t\t\t"
          + formatDouble(energy, 2) + "\t\t\t\t" + formatDouble(social, 2) + "\t\t\t\t"
          + formatDouble(mental_stim, 2) + "\t\t\t\t" + formatDouble(comfort, 2);
}

std::string Animal::formatDouble(double value, int precision) {
    std::string str = std::to_string(value);
    size_t decimal_pos = str.find('.');

    if (decimal_pos != std::string::npos && decimal_pos + precision + 1 < str.length()) {
        str = str.substr(0, decimal_pos + precision + 1);
    }

    return str;
}