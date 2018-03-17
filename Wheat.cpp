
// File Name: Wheat.cpp
// Author: James Meli
// Student ID: a738m747
// Assignment Number: 5

#include "Wheat.hpp"

namespace {
	const double AVERAGE_TEST_WEIGHT = 60.0;
	const double IDEAL_MOISTURE_LEVEL = 13.5;
}

// Default Constructor
Wheat::Wheat() : Grain()
{}

// Overloaded Custom Constructor
Wheat::Wheat(double moistureLevel, double foreignMaterial) : Grain(moistureLevel, foreignMaterial)
{}

//Returning the ideal moisture level for wheat
const double Wheat::getIdealMoistureLevel() const {
  	return IDEAL_MOISTURE_LEVEL;
}

// Returning average test weight per bushel for wheat
const double Wheat::getAverageTestWeight() const {
	return AVERAGE_TEST_WEIGHT;
}

// Returning clone of an object
Wheat* Wheat::clone() const {
  Wheat* wheat = new Wheat(this->moistureLevel, this->foreignMaterial);
  return wheat;
}

// Returning  the string representation of the derived class name
std::string Wheat::getType() const {
	return "Wheat";
}
