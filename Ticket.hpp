
// File Name: Ticket.hpp
// Author: James Meli
// Student ID: a738m747
// Assignment Number: 3

//Importing all neccessary libraries to be used
#include <string>
#include <ctime>
#include "Grain.hpp"
#ifndef ticket_hpp
#define ticket_hpp


class Ticket {
private:
   //Declaring all member variabled for the class
   std::string ticketNumber;
   float grossWeight;
   float tareWeight;
   std::time_t timestamp;
   Grain grain;

 public:
   //Default constructor
    Ticket();

   //Custom constructor
    Ticket(const std::string number, const float grossWeight, const float tareWeight, const Grain &grain);

    //Overload functions
    bool operator== (Ticket const &t1) const ;
    friend std::ostream& operator<< (std::ostream &out, const Ticket &t);

   //Accessor Functions
   std::string getTicketNumber() const;
   float getGrossWeight() const;
   float getTareWeight() const;
   std::time_t getTimestamp() const;
   float getGrainMoistureLevel() const;
   float getGrainForeignMaterial() const;

   //Member Functions
   float calNetWeight() const;
   float calGrosBushels() const;
   float calMoistureDockage() const;
   float calNetBushels() const;
   float calForeignMaterialDockage() const;
   std::string toString() const;
};
#endif
