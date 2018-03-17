
// File Name: Input.cpp
// Author: James Meli
// Student ID: a738m747
// Assignment Number: 5


#include <iostream>
#include <ctime>
#include <string>
#include "Input.hpp"

using namespace std;

//Enumaration for the different types of grain
enum Type {
  WHEAT,
  SOYBEAN,
  MILO,
};

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

    //Variable to store the type of grain the user wants to enter
    char grainType;
    Type type;

    //Variable to store new ticket user creates
    Ticket newTicket;

    //Prompting user to enter ticket information
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

    cout << "Grain type(w)heat, (s)oybean, (g)rain sorghum: ";
    cin >> grainType;

    if(grainType == 'w') {
      type = WHEAT;
    } else if(grainType == 's') {
      type = SOYBEAN;
    } else {
      type = MILO;
    }

    //Creating ticket based on the grain type the user entered
    if(type == WHEAT) {
      Wheat* wheat = new Wheat(moistureLevel, foreignMaterial);
      newTicket = Ticket(ticketNumber, grossWeight, tareWeight, wheat);
    } else if(type == SOYBEAN) {
      Soybean* soybean = new Soybean(moistureLevel, foreignMaterial);
      newTicket = Ticket(ticketNumber, grossWeight, tareWeight, soybean);
    } else {
      Milo* milo = new Milo(moistureLevel, foreignMaterial);
      newTicket = Ticket(ticketNumber, grossWeight, tareWeight, milo);
    }


    //Checking for duplicate ticket
    for(int i = 0; i < tickets.size(); i++) {
      if( tickets[i] == newTicket) {
         duplicate = false;
      }
    }
    if(duplicate) {
      //Ticket is added to the list
      tickets.add(newTicket);
      ticketCount += 1;
    } else {
      cout << "Sorry a ticket already exists with this number. Please enter a different number" << endl;
    }
    duplicate = true;
    cout << "Enter new ticket ? ('Y' or 'y' for yes, 'N' or 'n' for no): ";
    cin >> x;
  } while(x == 'Y' || x == 'y');
}
