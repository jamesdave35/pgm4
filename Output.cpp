
// File Name: Output.cpp
// Author: James Meli
// Student ID: a738m747
// Assignment Number: 6

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Output.hpp"
#include "Ticket.hpp"
using namespace std;



 void Output::outputTickets(const Tickets& tickets) {

   //Variable for file output
   ofstream fileOutput;

   //Opening the file
   fileOutput.open("HarvestTicketReceipts.txt");


   if(!fileOutput.good()) {
     cout << "Sorry file doesn't exist" << endl;
   } else {

     fileOutput << Ticket::headerRow() << endl;

     //Looping through each ticket and outputing their receipts.
     for(int i = 0; i < tickets.size(); i++) {
       fileOutput << tickets[i].receipt() << endl;
     }
   }

   fileOutput.close();
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
