#include <iostream>
#include <string>
#include <sstream>
#include "carpool.h"

/* SHIT TO DO
- EDGE SEATS INPUT
- DELETE DRIVERS
- DELETE PASSENGERS
*/

void eventOptions(){
  std::cout << "\n\t\t1. Add Driver\n";
  std::cout << "\t\t2. Add Passenger\n";
  std::cout << "\t\t3. Delete Driver\n";
  std::cout << "\t\t4. Delete Passenger\n";
  std::cout << "\t\t5. View Rides\n";
  std::cout << "\t\t6. Return \n";
}

void mainOptions(){
  std::cout << "\t----------------------------\n";
  std::cout << "\n\t1. Add Event\n";
  std::cout << "\t2. View Events\n";
  std::cout << "\t3. Quit\n";
  std::cout << "\n\tWhat would you like to do? ";

}

bool isDigit( std::string seats ){
	for(int i = 0; i < seats.size(); ++i){
	  bool isDigit = ('0' <= seats[i] && seats[i] <= '9');
	  if( !isDigit ) {
	      return false;
	  }
	}
	return true;
}

void addDriver(Event* event){
  std::string name = "";
  std::string phoneNum = "";
  std::string seats = "";

  std::cin.ignore();
  std::cout << "\n\t\t\tDriver Name: ";
  std::getline(std::cin, name);

  std::cout << "\t\t\tPhone Number: ";
  std::getline(std::cin, phoneNum);

  std::cout << "\t\t\tNumber of seats: ";
 
  std::cin>>seats;
  
  bool invalidInput = true;
  int intSeats = 0;
  while( invalidInput ){
	  std::getline( std::cin, seats );
	  if( isDigit( seats )) {
	      intSeats = std::atoi( seats.c_str() );  
		  if( intSeats > 0 && intSeats < 7 ){
		      invalidInput = false;

		  }
		  else {
		      std::cout << "\t\t------INVALID INPUT FOR SEAT NUM -----" << std::endl;
		  }
	  } else {
	    std::cout << "\t\t------INVALID INPUT FOR SEAT NUM -----" << std::endl;
	  }
  }

  Driver* driver = new Driver(name, phoneNum, intSeats);
  event->addDriver(driver);
  std::cout << "\n\t\tDriver added successfully\n";
  std::cout << "\t\t----------------------------\n";
}

void addPassenger(Event* event){
  Driver * driver = event->getDriverWithSeats();
  if(event->getDrivers().size()==0){
	  std::cout<<"\n\t\t----- No rides available-----\n";
	  return;
  }
  std::string name = "";
  std::string phoneNumber = "";

  std::cin.ignore();
  std::cout << "\n\t\t\tPassenger Name: ";
  std::getline( std::cin, name );

  std::cout << "\t\t\tPhone Number: ";
  std::getline( std::cin, phoneNumber );
  
  Passenger * passenger = new Passenger( name, phoneNumber );

  if( driver->addPassenger( passenger ) ){
    std::cout << "\n\t\tPassenger added successfully\n";
	std::cout << "\t\t----------------------------\n";
  }else{
    std::cout << "\n\t\tFailed to add passenger, no available seats\n";
	std::cout << "\t\t----------------------------\n";
  }
}

void deleteDriver(Event* event, int driverId){
	
}

void deletePassenger(Event* event){
	std::string pass;
	
	std::cin.ignore();
	std::cout<<"Who would you like to remove? ";
	std::getline(std::cin, pass);
	
	//Its pointing to a copy of the VECTOR not the original. LUKE FIX
	for(int i = 0; i < event->getDrivers().size(); ++i){
		std::vector<Passenger*> passengers = event->getDrivers().at(i)->getPassengers();
		for(int k = 0; k < event->getDrivers().at(i)->getPassengers().size(); ++k){
			if(pass == passengers.at(k)->getName()){
				passengers.erase(passengers.begin()+k);
			}
		}
	}
	
}

// This method also needs to take in an event
void eventMenu(Event* event){
  bool stop = false;

  while( !stop ) {
    int userInput;

    // Print out event details
    eventOptions();
	std::cout<<"\n\t\tWhat would you like to do? ";
    std::cin >> userInput;

    if( userInput == 6 ){
      stop = true;
    } else if(userInput == 1){
      addDriver(event);
    } else if(userInput == 2){
      addPassenger(event);
	} else if(userInput == 3){
	  event->printDrivers();
	  int driverId = 0;
	  std::cout << "\t\t\t SELECT A DRIVER" << std::endl;
	  std::cin >> driverId;
	  event->deleteDriver(driverId-1);
	} else if(userInput == 4){
	  deletePassenger(event);
    } else if(userInput == 5){
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
		std::cout << "\n\t\tEvent name: ";
		std::getline(std::cin, name);

		std::cout << "\t\tEvent description: ";
		std::getline(std::cin, description);

		std::cout << "\t\tEvent date: ";
		std::getline(std::cin, date);

		std::cout << "\t\tEvent location: ";
		std::getline(std::cin, location);

		std::cout << "\t\tEvent time: ";
		std::getline(std::cin, time);

		// Create events
		Event* event = new Event(name, date, description, time, location);
		events->push_back(event);
		std::cout << "\n\tEvent successfully created\n";
	}
	else if (userInput == 2) {
		if (events->size() != 0) {
			std::cout << "\n\tSelect an event: \n";
			for (int i = 0; i < events->size(); ++i) {
				std::cout << "\n\t" << i+1 << ". " << (events->at(i))->getName();
				std::cout << "\n\t\tDescription: " << (events->at(i))->getDescription();
				std::cout << "\n\t\tDate: " << (events->at(i))->getDate();
				std::cout << "\n\t\tLocation: " << (events->at(i))->getLocation();
				std::cout << "\n\t\tTime: " << (events->at(i))->getTime();
			}
			std::cout<<"\n\n\tEvent#: ";
			int eventId;
			std::cin >> eventId;
			eventMenu(events->at(eventId-1));
		}
		else {
			std::cout << "\n\t ----- No listed events -----\n\n";
		}
	} else {
    std::cout << "\n\t ----- Invalid input -----\n\n";
  }
}

int main(){
  std::vector<Event*> events; // create std::vector of Event events
  bool stop = false;
  int userInput;
  std::cout << "\n\tUber 2.0" << std::endl;
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
