
// File Name: Milo.hpp
// Author: James Meli
// Student ID: a738m747
// Assignment Number: 6

#ifndef MILO_H_
#define MILO_H_

#include "Grain.hpp"

class Milo : public Grain {
  public:
      //Default Constructor
      Milo();

      //Overloaded custom constructor to initialize protected member variables from base class
      Milo(double moistureLevel, double foreignMaterial);

      // Member function to the constant for ideal moisture level for milo
 	    const double getIdealMoistureLevel() const;

 	    // Member function to the constant for average test weight per bushel for milo
 	    const double getAverageTestWeight() const;

      // Member function to return clone of an object
	    Milo* clone() const;

	    // Member function to return  the string representation of the derived class name
	    std::string getType() const;

};

#endif
