
/*
 * Grain.h
 *
 *  Created on: Feb 9, 2018
 *      Author: Joe
 */

#ifndef GRAIN_H_
#define GRAIN_H_

#include<string>


/**
 * The Grain class identifies properties of a sample of grain
 */
class Grain {
public:
	// Constructor default
	Grain();

	// Constructor allowing caller to specify sample's moisture level (%) and foreign material (%)
	Grain(double moistureLevel, double foreignMaterial);

	// Destructor
	virtual ~Grain();

	// Pure virtual accessor to return the grain's average test weight (lbs/bushel)
	virtual const double getAverageTestWeight() const = 0;

	// Pure virtual accessor to return the grain's ideal moisture level (percent)
	virtual const double getIdealMoistureLevel() const = 0;

	// Pure virtual function to return a copy of the calling object (percent)
	virtual Grain* clone() const = 0;

	// Pure virtual function to get string representation of the calling object's grain type
	virtual std::string getType() const = 0;

	// Accessor to return sample's moisture level in percentage
	double getMoistureLevel() const;

	// Accessor to return sample's foreign material in percentage
	double getForeignMaterial() const;

	// Member function to return a string representing the calling object’s grain type
	std::string toString() const;

protected:
	// Member variables
	double moistureLevel;
	double foreignMaterial;
};

#endif /* GRAIN_H_ */
