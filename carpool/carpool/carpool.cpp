#include "stdafx.h"
#include <iostream>
#include <string>
#include "carpool.h"

void viewRides(Event* event){
  std::cout << "\n\t\t 1. Eric - 2 empty seats\n";
  std::cout << "\n\t\t 2. Bill - 1 empty seats\n";
  std::cout << "\n\t\t 3. Robert - 0 empty seats\n";
  std::cout << "\n\t\t 4. Timothy - 3 empty seats\n";
  std::cout << "\n\t\t 0. Henry ugly god - 0 empty seats\n";
  std::cout << "\n\t\t";
}

void eventOptions(){
  std::cout << "\n\t\t1. Add Driver\n";
  std::cout << "\t\t2. Add Passenger\n";
  std::cout << "\t\t3. View Rides\n";
  std::cout << "\t\t4. Return \n";
  std::cout << "\t\t\n";
}

void mainOptions(){
  std::cout << "\n\t1. Add Event\n";
  std::cout << "\t2. View Events\n";
  std::cout << "\t3. Done\n";
}

void addDriver(Event* event){
  std::string name = "";
  std::string phoneNum = "";
  int seats = 0;

  std::cin.ignore();
  std::cout << "\n\t\t\tDriver name:\n";
  std::getline(std::cin, name);

  std::cout << "\n\t\t\tPhone Number:\n";
  std::getline(std::cin, phoneNum);

  std::cout << "\n\t\t\tNumber of seats:\n";
  std::cin >> seats;
  if(seats < 1){
    std::cout << "\t\t\tFailed to add driver, no available seats.\n"; 
  }else{
    //put in std::vector	
	Driver* driver = new Driver(name, phoneNum, seats);
	event->addDriver(driver);

    std::cout << "\t\t\tDriver added successfully\n";
  }
}

void addPassenger(Event* event){
  std::string name = "";
  std::string phoneNumber = "";

  std::cin.ignore();
  std::cout << "\n\t\t\tDriver name:\n";
  std::getline( std::cin, name );

  std::cout << "\n\t\t\tPhone Number:\n";
  std::getline( std::cin, phoneNumber );
  
  if(true){
    //put passenger in std::vector and under car with most seats available
    event->addPassenger(name,phoneNumber);
    std::cout << "\t\t\tPassenger added successfully\n";
  }else{
    std::cout << "\t\t\tFailed to add passenger, no available seats\n";
  }
}


// This method also needs to take in an event
void eventMenu(Event* event){
  bool stop = false;

  while( !stop ) {
    int userInput;

    // Print out event details
    eventOptions();
    std::cin >> userInput;

    if( userInput == 4 ){
      stop = true;
    } else if(userInput == 1){
      addDriver(event);
    } else if(userInput == 2){
      addPassenger(event);
    } else if(userInput == 3){
      event->viewRides();
    } else {
      std::cout << "\n\t ----- Invalid input -----\n\n";
    }
  }
}

void mainMenu(int userInput, std::vector<Event*>* events) {
	if (userInput == 1) {
		std::string name = "";
		std::string description = "";
		std::string date = "";
		std::string location = "";
		std::string time = "";

		std::cin.ignore();
		std::cout << "\n\tEvent name:\n";
		std::getline(std::cin, name);

		std::cout << "\n\tEvent description:\n";
		std::getline(std::cin, description);

		std::cout << "\n\tEvent date:\n";
		std::getline(std::cin, date);

		std::cout << "\n\tEvent location:\n";
		std::getline(std::cin, location);

		std::cout << "\n\tEvent time:\n";
		std::getline(std::cin, time);

		// Create events
		Event* event = new Event(name, date, description, time, location);
		events->push_back(event);
		std::cout << "Event successfully created\n";
	}
	else if (userInput == 2) {
		/* SELECT AN EVENT OPTION*/
		std::cout << "\n\tSelect an event: \n";
	for (int i = 0; i < events->size(); ++i) {
		std::cout << "\n\t" << i << ". " << (events->at(i))->getName();
	}
	/* User input*/
	int eventId;
	std::cin >> eventId;
	eventMenu(events->at(eventId));
	} else {
    std::cout << "\n\t ----- Invalid input -----\n\n";
  }
}

int main(){
  std::vector<Event*> events; // create std::vector of Event events
  bool stop = false;
  int userInput;

  while( !stop ) {
    mainOptions();
    std::cin >> userInput;
    if(userInput == 3 ){
      stop = true;
    } else {
      mainMenu( userInput,&events);
    }
  }
}
