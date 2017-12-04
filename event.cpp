#include <iostream>
#include "event.h"

bool isInt( std::string seats ){
	//Loop through the string
	for(int i = 0; i < seats.size(); ++i){ //If the char at a certain index is not an integer,
	  //break the loop
	  bool isDigit = ('0' <= seats[i] && seats[i] <= '9');
	  if( !isDigit ) {
	      return false;
	  }
	}

	//Return true otherwise
	return true;
}


//Constructor
Event::Event(std::string name, std::string date, std::string description, std::string time, std::string location) {
	this->name = name;
	this->date = date;
	this->description = description;
	this->time = time;
	this->location = location;
	this->drivers = drivers;
}

void Event::setName(std::string newName) {
	name = newName;
}

void Event::setDate(std::string newDate) {
	date = newDate;
}

void Event::setTime(std::string newTime) {
	time = newTime;
}

void Event::setLocation(std::string newLocation) {
	location = newLocation;
}

void Event::setDescription(std::string newDescription) {
	description = newDescription;
}

void Event::addDriver(Driver * driver) {
	drivers.push_back(driver);
}


//Print out drivers for a given event
void Event::viewRides() {
	//If there are no drivers, do nothing
	if(drivers.size()==0){
		std::cout<<"\n\t\t----- No rides available-----\n";
	    return;
	}else{
		//Loop through all drivers
		for (int i = 0; i < drivers.size(); ++i) {
			//Print out relevent info if driver has empty seats
			if( drivers.at(i)->getSeats() >= 0 ) {
				std::cout<<"\n\t\t\t" << i+1 << ". " << drivers.at(i)->getName() << "\t\tPhone#: " << drivers.at(i)->getPhoneNum() << "\tNumber of seats: " << drivers.at(i)->getSeats() << std::endl;
				std::vector<Passenger*> passengers = drivers.at(i)->getPassengers();
				//Print out all passengers of each driver
				for(int k = 0; k < passengers.size(); ++k){
					std::cout<<"\t\t\t\t" << passengers.at(k)->getName() << "\t" << passengers.at(k)->getPhoneNum() << std::endl;
				}
			}
		}
	}
	std::cout << "\t\t----------------------------\n";
}

std::string Event::getName() {
	return name;
}

std::string Event::getDate() {
	return date;
}

std::string Event::getTime() {
	return time;
}

std::string Event::getLocation() {
	return location;
}

std::string Event::getDescription() {
	return description;
}

//Find the first driver with an empty seat
Driver* Event::getDriverWithSeats() {
	int length = drivers.size();
	//Loop through all drivers on a given event
	for (int i = 0; i < length; ++i) {
		//If a driver has an empty seat, return that driver
		if ( drivers.at(i)->getSeats() > 0 ){
			return drivers.at(i);
		}
	}
}

std::vector<Driver*> Event::getDrivers(){
	return drivers;
}

//Print out a list of drivers
void Event::printDrivers(){
	//Loop through drivers and print out revelent information
	for(int i = 0; i < drivers.size(); ++i){
		if( drivers.at(i)->getSeats() >= 0 ){
			std::cout << "\t\t\t"<< i+1 << ". " << drivers.at(i)->getName() << "\n";
		}
	}
}

//Remove driver from list and relocate passengers
void Event::deleteDriver(int driverId){
	//Initialize variables
	Driver * driver = drivers.at(driverId);
	std::vector<Passenger*> passengers = driver->getPassengers();
	drivers.at(driverId)->setSeats(-1);

	//Loop through passengers
	for(int i = 0; i < passengers.size(); ++i){
		Driver * driver = this->getDriverWithSeats();
		//If the driver is NULL, odo nothing! We need more drivers
		if( driver == NULL ){
			std::cout << "\t\t\t" << passengers.at(i)->getName() << " does not have ride! Need more drivers." << std::endl;
		} else {
			//Add passenger to the driver's passengers vector
			driver->addPassenger( passengers.at(i) );
		}
	}
}


void Event::deletePassenger(){
	this->viewRides();
	std::string driverId = "";
	bool invalidInput = true;
	int intDriver = 0;
	std::cout << "\t\t\tSelect a driver: ";
	while( invalidInput ){
		std::getline( std::cin, driverId );
		//Check if integer for input for seats
		if( isInt( driverId )) {
		    intDriver = std::atoi( driverId.c_str() );  
			//Ensure seats are not obscenly huge
			if( intDriver > 0 && intDriver <= this->drivers.size() ){
			    invalidInput = false;
			} else {
			     std::cout << "\t\t------INVALID INPUT: NOT IN RANGE----" << std::endl;
			     std::cout << "\t\t\tDriver Id: ";
			}
		} else {
		    std::cout << "\t\t------INVALID INPUT-----" << std::endl;
			std::cout << "\t\t\tDriver Id: ";
		}
	}

	this->drivers.at(intDriver-1)->deletePassenger();
}
