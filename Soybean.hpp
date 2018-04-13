
// File Name: Soybean.hpp
// Author: James Meli
// Student ID: a738m747
// Assignment Number: 6

#ifndef SOYBEAN_H_
#define SOYBEAN_H_

#include "Grain.hpp"

class Soybean: public Grain {
  public:
     // Default Constructor
     Soybean();

     // Overloaded custom constructor to initialize protected member variables from base class
     Soybean(double moistureLevel, double foreignMaterial);

     // Member function to the constant for ideal moisture level for soybean
     const double getIdealMoistureLevel() const;

     // Member function to the constant for average test weight per bushel for soybean
     const double getAverageTestWeight() const;

     // Member function to return clone of an object
     Soybean* clone() const;

     // Member function to return  the string representation of the derived class name
     std::string getType() const;
};

#endif
