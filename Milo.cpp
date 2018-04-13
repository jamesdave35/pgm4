

// File Name: Wheat.cpp
// Author: James Meli
// Student ID: a738m747
// Assignment Number: 6

#include "Milo.hpp"

namespace {
	const double AVERAGE_TEST_WEIGHT = 56.0;
	const double IDEAL_MOISTURE_LEVEL = 13.5;
}

// Default Constructor
Milo::Milo() : Grain()
{}

// Overloaded Custom Constructor
Milo::Milo(double moistureLevel, double foreignMaterial) : Grain(moistureLevel, foreignMaterial)
{}

//Returning the ideal moisture level for milo
const double Milo::getIdealMoistureLevel() const {
  	return IDEAL_MOISTURE_LEVEL;
}

// Returning average test weight per bushel for milo
const double Milo::getAverageTestWeight() const {
	return AVERAGE_TEST_WEIGHT;
}

// Returning clone of an object
Milo* Milo::clone() const {
  Milo* milo = new Milo(this->moistureLevel, this->foreignMaterial);
  return milo;
}

// Returning  the string representation of the derived class name
std::string Milo::getType() const {
	return "Grain Sorghum";
}
