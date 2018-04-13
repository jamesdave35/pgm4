// File Name: Ticket.cpp
// Author: James Meli
// Student ID: a738m747
// Assignment Number: 6

//Importing all neccessary libraries
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "Ticket.hpp"
using namespace std;

//Default constructor
 Ticket::Ticket()
 {
  ticketNumber = "";
  grossWeight = 0;
  tareWeight = 0;
  timestamp = 0;
  sample = nullptr;

}

//Custom constructor
 Ticket::Ticket(const string number, const float grossWeight, const float tareWeight, const Grain* newSample, time_t timeStamp)
  : ticketNumber(number), grossWeight(grossWeight), tareWeight(tareWeight), timestamp(timeStamp)
  {
    if(newSample != nullptr){
      this->sample = newSample->clone();
    }
    //time(&timestamp);
  }

//Copy constructor
Ticket::Ticket(const Ticket& ticket) {
    if(ticket.sample != nullptr) {
      this->sample = ticket.sample->clone();
    }

    this->timestamp = ticket.timestamp;
  	this->ticketNumber = ticket.ticketNumber;
  	this->grossWeight = ticket.grossWeight;
  	this->tareWeight = ticket.tareWeight;
}

//Destructor
Ticket::~Ticket() {
  if(sample != nullptr)
     delete this->sample;
}

//Overloading equality operator
bool Ticket::operator== (const Ticket &t1) const
  {
    return ( this->ticketNumber == t1.getTicketNumber());
  }

//Overloading insertion operator
ostream& operator<< (ostream &out, const Ticket &t)
  {
    out.precision(2);
    out << t.toString();
    return out;
  }

//Overloading assignment operator
const Ticket& Ticket::operator =(const Ticket& ticket) {
	if(this != &ticket) {
		if(sample != nullptr)
      delete sample;
    if(ticket.sample != nullptr){
      this->sample = ticket.sample->clone();
    }


	this->timestamp = ticket.getTimestamp();
	this->grossWeight = ticket.getGrossWeight();
	this->tareWeight = ticket.getTareWeight();
	this->ticketNumber = ticket.getTicketNumber();

  return *this;
}
  return *this;
}

//Returns the ticket number
string Ticket::getTicketNumber() const
{
  return ticketNumber;
}

//Returns the gross weight
float Ticket::getGrossWeight() const
{
  return grossWeight;
}

//Returns the tare weight
float Ticket::getTareWeight() const
{
  return tareWeight;
}

Grain* Ticket::getSample() const
{
  return sample;
}



//Returns the moisture level
float Ticket::getGrainMoistureLevel() const
{
  return sample->getMoistureLevel();
}

//Returns the foreign material
float Ticket::getGrainForeignMaterial() const
{
  return sample->getForeignMaterial();
}

time_t Ticket::getTimestamp() const {
  return timestamp;
}

//Calculates the net weight
float Ticket::calNetWeight() const
{
  return grossWeight - tareWeight;
}

//Calculates the gross bushels
float Ticket::calGrosBushels() const
{
  return this->calNetWeight() / sample->getAverageTestWeight();
}

//Calculates the moisture dockage
float Ticket::calMoistureDockage() const
{
  if(sample->getMoistureLevel() < 12)
    return 0;
  else
    return this->calGrosBushels() * ((sample->getMoistureLevel()/100) - (sample->getIdealMoistureLevel()/100));
}

//Calculates the net bushels
float Ticket::calNetBushels() const
{
  return this->calGrosBushels() - this->calMoistureDockage() - this->calForeignMaterialDockage();
}

//Calculates the foreign material dockage
float Ticket::calForeignMaterialDockage() const
{

  return this->calGrosBushels() * (sample->getForeignMaterial() / 100);
}

string Ticket::toString() const
{
  char t[20];
   strftime(t, 20, "%D %T", localtime(&timestamp));

   stringstream stringOutput;
   stringOutput << setprecision(1) << showpoint << fixed;
   stringOutput << "\n" << sample->toString() << " Ticket " << ticketNumber << " - " << t << ":\n";
   stringOutput << "\t" << grossWeight << " Gross Weight\n";
   stringOutput << "\t" << tareWeight << " Tare Weight\n";
   stringOutput << "\t" << this->calNetWeight() << " Net Weight\n\n";
   stringOutput << "\t" << this->calGrosBushels() << " Gross Bushels\n";
   stringOutput << "\t" << this->calMoistureDockage() << " Moisture level" << "(" << this->sample->getMoistureLevel() << "%)\n";
   stringOutput << "\t" << this->calForeignMaterialDockage() << " Foreign Material" << "(" << this->sample->getForeignMaterial() << "%)\n";
   stringOutput << "\t" << this->calNetBushels() << " Net Bushels\n";

  return stringOutput.str();
}

string Ticket::headerRow()  {

  return "Type|Date|Time|Number|GrossWeight|TareWeight|NetWeight|GrossBushels|MoistureLevel|MoistureLevelDockage|ForeignMaterial|ForeignMaterialDockage|NetBushels";

}

string Ticket::receipt() const {
  char date[20];
  strftime(date, 20, "%Y%m%d", localtime(&timestamp));

  char timeOutput[20];
  strftime(timeOutput, 20, "%H%M%S", localtime(&timestamp));


  stringstream stringOutput;
  stringOutput << setprecision(0) << showpoint << fixed;
  stringOutput << "\n" << sample->toString() << "|" << date << "|" << timeOutput << "|" << ticketNumber;
  stringOutput << "|" << grossWeight << "|" << tareWeight << "|";
  stringOutput << setprecision(2);
  stringOutput << this->calNetWeight() << "|" << this->calGrosBushels() << "|" << this->sample->getMoistureLevel();
  stringOutput << "|" << this->calMoistureDockage() << "|" << this->sample->getForeignMaterial() << "|" << this->calForeignMaterialDockage();
  stringOutput << "|" << this->calNetBushels();

  return stringOutput.str();

}
