
// File Name: Output.cpp
// Author: James Meli
// Student ID: a738m747
// Assignment Number: 5

#include <iostream>
#include <iomanip>
#include "Output.hpp"
#include "Ticket.hpp"
using namespace std;



 void Output::outputTickets(const Tickets& tickets) {
  //Looping through list of tickets to print out each ticket
  for(int i = 0; i < tickets.size(); i++){
    cout << tickets[i] << endl;
  }
}

void Output::outputSummary(const Tickets& tickets) {
  //Variables to hold total gross bushels and total net brushels
  float totGrossBushels = 0;
  float totNetBushels = 0;

  for(int i = 0; i < tickets.size(); i++){
    totGrossBushels += tickets[i].calGrosBushels();
    totNetBushels += tickets[i].calNetBushels();
  }
  //Printing out the total gross bushels and total net brushels
  cout << "\nWheat harvest summary" << endl;
  cout << setprecision(1) << showpoint << fixed;
  cout << "\t" << totGrossBushels << " Gross bushels" << endl;
  cout << "\t" << totNetBushels << " Net bushels" << endl;
}
