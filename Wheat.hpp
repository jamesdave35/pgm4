
// File Name: Wheat.hpp
// Author: James Meli
// Student ID: a738m747
// Assignment Number: 5

#ifndef WHEAT_H_
#define WHEAT_H_

#include "Grain.hpp"

class Wheat: public Grain {
 public:
      //Default Constructor
      Wheat();

      //Overloaded custom constructor to initialize protected member variables from base class
      Wheat(double moistureLevel, double foreignMaterial);

      // Member function to the constant for ideal moisture level for wheat
 	    const double getIdealMoistureLevel() const;

 	    // Member function to the constant for average test weight per bushel for wheat
 	    const double getAverageTestWeight() const;

      // Member function to return clone of an object
	    Wheat* clone() const;

	    // Member function to return  the string representation of the derived class name
	    std::string getType() const;

};

#endif
