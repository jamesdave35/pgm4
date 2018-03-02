// File Name: Ticket.cpp
// Author: James Meli
// Student ID: a738m747
// Assignment Number: 4

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

}

//Custom constructor
 Ticket::Ticket(const string number, const float grossWeight, const float tareWeight, const Grain &grain)
  : ticketNumber(number), grossWeight(grossWeight), tareWeight(tareWeight), grain(grain), timestamp(timestamp)
  {
    time(&timestamp);
  }

  bool Ticket::operator== (const Ticket &t1) const
  {
    return ( this->ticketNumber == t1.getTicketNumber());
  }

  ostream& operator<< (ostream &out, const Ticket &t)
  {
    out.precision(2);
    out << t.toString();
    return out;
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

//Returns the moisture level
float Ticket::getGrainMoistureLevel() const
{
  return grain.getMoistureLevel();
}

//Returns the foreign material
float Ticket::getGrainForeignMaterial() const
{
  return grain.getForeignMaterial();
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
  return this->calNetWeight() / grain.getAverageTestWeight();
}

//Calculates the moisture dockage
float Ticket::calMoistureDockage() const
{
  if(grain.getMoistureLevel() < 12)
    return 0;
  else
    return this->calGrosBushels() * ((grain.getMoistureLevel()/100) - (grain.getIdealMoistureLevel()/100));
}

//Calculates the net bushels
float Ticket::calNetBushels() const
{
  return this->calGrosBushels() - this->calMoistureDockage() - this->calForeignMaterialDockage();
}

//Calculates the foreign material dockage
float Ticket::calForeignMaterialDockage() const
{

  return this->calGrosBushels() * (grain.getForeignMaterial() / 100);
}

string Ticket::toString() const
{
  char t[20];
   strftime(t, 20, "%D %T", localtime(&timestamp));

   stringstream ss;
   ss << setprecision(1) << showpoint << fixed;
   ss << "\nTicket " << ticketNumber << " - " << t << ":\n";
   ss << "\t" << grossWeight << " Gross Weight\n";
   ss << "\t" << tareWeight << " Tare Weight\n";
   ss << "\t" << this->calNetWeight() << " Net Weight\n\n";
   ss << "\t" << this->calGrosBushels() << " Gross Bushels\n";
   ss << "\t" << this->calMoistureDockage() << " Moisture level" << "(" << this->grain.getMoistureLevel() << "%)\n";
   ss << "\t" << this->calForeignMaterialDockage() << " Foreign Material" << "(" << this->grain.getForeignMaterial() << "%)\n";
   ss << "\t" << this->calNetBushels() << " Net Bushels\n";

  return ss.str();
}
