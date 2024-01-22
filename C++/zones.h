// animals.h

#ifndef ZONES_H
#define ZONES_H

#include <string>

class Zone {
private:
  std::string name;
  std::string habitat;
  double food_availability;
  double size;
  std::string sunny_spots;

public:
  Zone(std::string name, std::string habitat, double food_availability, double size, std::string sunny_spots);

  std::string formatDouble(double value, int precision);
  std::string getInfo();
  std::string getName();
  std::string getHabitat();
  double getFoodAvailability();
  double getSize();
  std::string getSunnySpots();

  void setName(std::string value);
  void setHabitat(std::string value);
  void setFoodAvailability(double value);
  void setSize(double value);
  void setSunnySpots(std::string value);

};

#endif