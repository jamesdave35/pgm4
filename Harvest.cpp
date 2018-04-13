// File Name: Harvest.cpp
// Author: James Meli
// Student ID: a738m747
// Assignment Number: 6

//Importing all neccessary libraries and files
#include<iostream>
#include "Tickets.hpp"
#include "Input.hpp"
#include "Output.hpp"
using namespace std;

int main(void) {

  //Variable to hold list of Tickets
  Tickets tickets;

  //Adding tickets to ticket list
  Input::inputTickets(tickets);

  //Printing out each ticket
  Output::outputTickets(tickets);

  //Printing out summary of harvest
  Output::outputSummary(tickets);
  return 0;
}
