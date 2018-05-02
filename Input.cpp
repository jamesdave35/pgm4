
// File Name: Input.cpp
// Author: James Meli
// Student ID: a738m747
// Assignment Number: 7


#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <cstring>
#include "Input.hpp"

using namespace std;
using namespace ContainerTemplate;

//Enumaration for the different types of grain
enum Type {
  WHEAT,
  SOYBEAN,
  MILO,
};

 void Input::inputTickets(Array<Ticket>& tickets) {
   //Variable for file input
   ifstream fileInput;

   //Opening the file
   fileInput.open("HarvestTickets.txt");

   //Checking if the file exists
   if(!fileInput.good()) {
     cout << "Sorry file doesn't exist" << endl;
   } else {
      do {

        //Variable to hold each ticket record
        string ticketRecord;

        getline(fileInput, ticketRecord);

        //Making sure only appropriate data is imported
        if(ticketRecord.length() > 1 && ticketRecord[0] != '#') {
          try {

            //Variable to keep track of every category
            int category = 0;

            //Variables to hold each category
            string type, date, timeOuput, ticketNumber, t_weight, g_weight, f_material, m_level;

            //Variable for while loop
            int x = 0;

            //Looping through each record and storing appropriate data in appropriate variables
            while(x < ticketRecord.length()) {
              if(ticketRecord[x] == '|') {
                category++;
              }

            if(category == 0 && ticketRecord[x] != '|' && ticketRecord[x] != ' ') {
               type += ticketRecord[x];
            } else if(category == 1 && ticketRecord[x] != '|' && ticketRecord[x] != ' ') {
              date += ticketRecord[x];
            } else if(category == 2 && ticketRecord[x] != '|' && ticketRecord[x] != ' ') {
              timeOuput += ticketRecord[x];
            } else if(category == 3 && ticketRecord[x] != '|' && ticketRecord[x] != ' ') {
              ticketNumber += ticketRecord[x];
            } else if(category == 4 && ticketRecord[x] != '|' && ticketRecord[x] != ' ') {
              g_weight += ticketRecord[x];
            } else if(category == 5 && ticketRecord[x] != '|' && ticketRecord[x] != ' ') {
              t_weight += ticketRecord[x];
            } else if(category == 6 && ticketRecord[x] != '|' && ticketRecord[x] != ' ') {
              m_level += ticketRecord[x];
            } else if(category == 7 && ticketRecord[x] != '|' && ticketRecord[x] != ' ') {
              f_material += ticketRecord[x];
            }

            x++;
         }

            if(category < 7) {
              throw category;
            }

            try {
              time_t t_output;
              string timeStamp = date + " " + timeOuput;
              float grossWeight = 0;
              float tareWeight = 0;
              float moistureLevel = 0;
              float foreignMaterial = 0;

              const char *timestamp = timeStamp.c_str();
              struct tm tm;
              strptime(timestamp, "%Y-%m-%d %H:%M:%S", &tm);
              t_output = mktime(&tm);

              grossWeight = stoi(g_weight);
              tareWeight = stoi(t_weight);
              foreignMaterial = stof(f_material);
              moistureLevel = stof(m_level);

              Type grain;

              if(type == "Wheat") {
                grain = WHEAT;
              } else if(type == "Soybean") {
                grain = SOYBEAN;
              } else {
                grain = MILO;
              }

              Ticket newTicket;

              //Creating ticket based on the grain type the user entered
              if(grain == WHEAT) {
                Wheat* wheat = new Wheat(moistureLevel, foreignMaterial);
                newTicket = Ticket(ticketNumber, grossWeight, tareWeight, wheat, t_output);
              } else if(grain == SOYBEAN) {
                Soybean* soybean = new Soybean(moistureLevel, foreignMaterial);
                newTicket = Ticket(ticketNumber, grossWeight, tareWeight, soybean, t_output);
              } else {
                Milo* milo = new Milo(moistureLevel, foreignMaterial);
                newTicket = Ticket(ticketNumber, grossWeight, tareWeight, milo, t_output);
              }

              bool duplicate = true;
              //cout << newTicket.receipt() << endl;
              //Checking for duplicate ticket
              for(int i = 0; i < tickets.size(); i++) {
                if( tickets[i] == newTicket) {
                   duplicate = false;
                }
              }
              if(duplicate) {
                //Ticket is added to the list
                tickets.add(newTicket);

              } else {
                cout << "Sorry a ticket already exists with this number. Please enter a different number" << endl;
              }
              //duplicate = true;
            } catch(const exception& error) {
              cout << "\nInput is invalid: " << error.what();
            }
          } catch(int error) {
            cout << "\nSorry this record doesn't have the required number of fields it has " << error << " fields";
          }
        }

      }while(!fileInput.eof());
   }

   fileInput.close();

}
