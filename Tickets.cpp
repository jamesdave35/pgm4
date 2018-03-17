
// File Name: Tickets.cpp
// Author: James Meli
// Student ID: a738m747
// Assignment Number: 5

#include <iostream>
#include "Tickets.hpp"
using namespace std;

//Default Constructor
Tickets::Tickets() {
  ticketArrayCapacity = 0;
  ticketArraySize = 0;
  ticketArray = new Ticket[ticketArrayCapacity];
}

//Copy Constructor
Tickets::Tickets(const Tickets& tickets) : ticketArrayCapacity(tickets.ticketArrayCapacity), ticketArraySize(tickets.ticketArraySize){
  ticketArray = new Ticket[ticketArrayCapacity];
}

//Destructor
Tickets::~Tickets() {
  delete[] ticketArray;
}

//This functions adds a ticket to the list
void Tickets::add(const Ticket& ticket){

  ticketArraySize++;

  if(ticketArraySize > ticketArrayCapacity) {
    ticketArrayCapacity = ticketArraySize + 3;
    Ticket *newTickets = new Ticket[ticketArrayCapacity];

    for(unsigned int i = 0; i < ticketArraySize - 1; i++){
      newTickets[i] = ticketArray[i];
    }

    newTickets[ticketArraySize - 1] = ticket;
    delete[] ticketArray;
		ticketArray = newTickets;

    return;
  }

  ticketArray[ticketArraySize - 1] = ticket;
}

//Returning size of ticket list
int Tickets::size() const {
  return ticketArraySize;
}

//Overiding assignment operator
const Tickets& Tickets::operator =(const Tickets& tickets) {
 if(ticketArrayCapacity != tickets.ticketArrayCapacity){
   delete[] ticketArray;
   ticketArray = new Ticket[tickets.ticketArrayCapacity];
 }

 ticketArrayCapacity = tickets.ticketArrayCapacity;
 ticketArraySize = tickets.ticketArraySize;
 for(int i = 0; i < ticketArraySize; i++){
   ticketArray[i] = tickets[i];
 }

 return *this;
}

//Overriding  array operator
Ticket Tickets::operator [](unsigned int index) const {
  if(index >= ticketArraySize) {
    cout << "Index out of range" << endl;
    exit(0);
  }
  return ticketArray[index];
}
