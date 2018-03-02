
// File Name: Grain.cpp
// Author: James Meli
// Student ID: a738m747
// Assignment Number: 4

#include "Grain.hpp"

const double AVERAGE_TEST_WEIGHT = 60.0;
const double IDEAL_MOISTURE_LEVEL = 12.0;

//Default constructor
Grain::Grain(){
  moistureLevel = 0;
  foreignMaterial = 0;
}

//Custom Constructor
Grain::Grain(double moistureLevel, double foreignMaterial) : moistureLevel(moistureLevel), foreignMaterial(foreignMaterial)
{}

//Destructor
Grain::~Grain()
{}

//Returning AVERAGE_TEST_WEIGHT
 const double Grain::getAverageTestWeight() const {
    return AVERAGE_TEST_WEIGHT;
}

//Returning IDEAL_MOISTURE_LEVEL
const double Grain::getIdealMoistureLevel() const{
    return IDEAL_MOISTURE_LEVEL;
}

//Returning moisture level
double Grain::getMoistureLevel() const {
    return moistureLevel;
}

//Returning Foreign material
double Grain::getForeignMaterial() const {
    return foreignMaterial;
}
