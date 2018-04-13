
// File Name: Grain.cpp
// Author: James Meli
// Student ID: a738m747
// Assignment Number: 6

#include "Grain.hpp"



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

//Returning moisture level
double Grain::getMoistureLevel() const {
    return moistureLevel;
}

//Returning Foreign material
double Grain::getForeignMaterial() const {
    return foreignMaterial;
}

//a string representing the calling object’s grain type
std::string Grain::toString() const {
	return getType();
}
