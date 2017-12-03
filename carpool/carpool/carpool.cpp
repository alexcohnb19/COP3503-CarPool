#include <iostream>
#include <string>
#include <sstream>
#include "carpool.h"

/* SHIT TO DO
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
		      std::cout << "\t\t------INVALID INPUT: PLEASE PUT IN A SIZE OF 6 OR LESS -----" << std::endl;
			  std::cout << "\t\t\tNumber of seats: ";
		  }
	  } else {
	    std::cout << "\t\t------INVALID INPUT: NOT AN INTEGER -----" << std::endl;
		std::cout << "\t\t\tNumber of seats: ";
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

void deletePassenger(Event* event){
	
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
	  std::string driverId;
	  std::cout << "\t\t\tSelect Driver: ";
	  
	  bool invalidInput = true;
	  int intDriverId = 0;
	  std::cin.ignore();
	  while( invalidInput ){
		std::getline( std::cin, driverId );
		if( isDigit( driverId )) {
			intDriverId = std::atoi( driverId.c_str() );  
			if( intDriverId > 0 && intDriverId <= event->getDrivers().size() ){
				invalidInput = false;
			} else {
				std::cout << "\t\t------INVALID INPUT: PLEASE ENTER A DRIVER NUMBER ON THE LIST -----" << std::endl;
				std::cout << "\n\t\t\tSelect Driver: ";
			}
		} else {
			std::cout << "\t\t------INVALID INPUT: NOT AN INTEGER -----" << std::endl;
			std::cout << "\t\t\tSelect Driver: ";
		}
	}
	  event->deleteDriver(intDriverId-1);
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
			std::string eventId;

			bool invalidInput = true;
			int intEventId = 0;
			std::cin.ignore();
			while( invalidInput ){
				std::getline( std::cin, eventId );
				if( isDigit( eventId )) {
					intEventId = std::atoi( eventId.c_str() );  
					if( intEventId > 0 && intEventId <= events->size() ){
						invalidInput = false;
					} else {
						std::cout << "\t------INVALID INPUT: PLEASE ENTER A EVENT NUMBER ON THE LIST -----" << std::endl;
						std::cout << "\tEvent#: ";
					}
				} else {
					std::cout << "\t------INVALID INPUT: NOT AN INTEGER -----" << std::endl;
					std::cout << "\tEvent#: ";
				}
			}
			
			eventMenu(events->at(intEventId-1));
			
			
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
