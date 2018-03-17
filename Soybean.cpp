
// File Name: Soybean.cpp
// Author: James Meli
// Student ID: a738m747
// Assignment Number: 5

#include "Soybean.hpp"

namespace {
	const double AVERAGE_TEST_WEIGHT = 60.0;
	const double IDEAL_MOISTURE_LEVEL = 13.5;
}

// Default Constructor
Soybean::Soybean() : Grain()
{}

// Overloaded Custom Constructor
Soybean::Soybean(double moistureLevel, double foreignMaterial) : Grain(moistureLevel, foreignMaterial)
{}

//Returning the ideal moisture level for soybean
const double Soybean::getIdealMoistureLevel() const {
  	return IDEAL_MOISTURE_LEVEL;
}

// Returning average test weight per bushel for soybean
const double Soybean::getAverageTestWeight() const {
	return AVERAGE_TEST_WEIGHT;
}

// Returning clone of an object
Soybean* Soybean::clone() const {
  Soybean* soybean = new Soybean(this->moistureLevel, this->foreignMaterial);
  return soybean;
}

// Returning  the string representation of the derived class name
std::string Soybean::getType() const {
	return "Soybean";
}
