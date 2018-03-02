
// File Name: Input.cpp
// Author: James Meli
// Student ID: a738m747
// Assignment Number: 4


#include <iostream>
#include <ctime>
#include "Input.hpp"
using namespace std;



 void Input::inputTickets(Tickets& tickets) {
  int ticketCount = 1;

  //Variable to count number of duplicates
  bool duplicate = true;

  //This variable controls whether the user wants to enter a new ticket or not
  char x;

  //Loop for user to enter all the tickets
  do {

    //Declaring all neccessary variables to store data for each ticket
    string ticketNumber;
    float grossWeight, tareWeight;
    float moistureLevel, foreignMaterial;
    cout << "\nTicket number " << ticketCount << " (alphanumerical): ";
    cin >> ticketNumber;
    cout << "Gross weight (lbs): ";
    cin >> grossWeight;
    cout << "Tare weight (lbs): ";
    cin >> tareWeight;
    cout << "Moisture level(%): ";
    cin >> moistureLevel;
    cout << "Foreign material(%): ";
    cin >> foreignMaterial;
    Grain grain(moistureLevel, foreignMaterial);
    //New ticket is created
    Ticket ticket(ticketNumber, grossWeight, tareWeight, grain);

    //Checking for duplicate ticket
    for(int i = 0; i < tickets.size(); i++) {
      if( tickets[i] == ticket) {
         duplicate = false;
      }
    }
    if(duplicate) {
      //Ticket is added to the list
      tickets.add(ticket);
      ticketCount += 1;
    } else {
      cout << "Sorry a ticket already exists with this number. Please enter a different number" << endl;
    }
    duplicate = true;
    cout << "Enter new ticket ? ('Y' or 'y' for yes, 'N' or 'n' for no): ";
    cin >> x;
  } while(x == 'Y' || x == 'y');
}
