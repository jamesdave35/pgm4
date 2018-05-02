// File Name: Harvest.cpp
// Author: James Meli
// Student ID: a738m747
// Assignment Number: 7

//Importing all neccessary libraries and files
#include<iostream>
#include "Array.h"
#include "Input.hpp"
#include "Output.hpp"

using namespace std;
using namespace ContainerTemplate;

int main(void) {

  //Variable to hold list of Tickets
  Array<Ticket> tickets;

  //Adding tickets to ticket list
  Input::inputTickets(tickets);

  //Sorting the receipts
  sort(tickets.begin(), tickets.end(), Ticket::compare);

  //Printing out each ticket
  Output::outputTickets(tickets);

  //Printing out summary of harvest
  Output::outputSummary(tickets);
  return 0;
}
