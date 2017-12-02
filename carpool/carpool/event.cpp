#include <iostream>
#include <string>
#include "event.h"

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


void Event::viewRides() {
	if(drivers.size()==0){
		std::cout<<"\n\t\t----- No rides available-----\n";
	    return;
	}else{
		for (int i = 0; i < drivers.size(); ++i) {
			if( drivers.at(i)->getSeats() >= 0 ) {
				std::cout<<"\n\t\t\t" << drivers.at(i)->getName() << "\t\tPhone#: " << drivers.at(i)->getPhoneNum() << "\tNumber of seats: " << drivers.at(i)->getSeats() << std::endl;
				std::vector<Passenger*> passengers = drivers.at(i)->getPassengers();
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

Driver* Event::getDriverWithSeats() {
	int length = drivers.size();
	for (int i = 0; i < length; ++i) {
		if ( drivers.at(i)->getSeats() > 0 ){
			return drivers.at(i);
		}
	}
}

std::vector<Driver*> Event::getDrivers(){
	return drivers;
}

void Event::printDrivers(){
	for(int i = 0; i < drivers.size(); ++i){
		if( drivers.at(i)->getSeats() >= 0 ){
			std::cout << "\t\t\t"<< i+1 << ". " << drivers.at(i)->getName() << "\n";
		}
	}
}

//Remove driver from list and relocate passengers
void Event::deleteDriver(int driverId){
	Driver * driver = drivers.at(driverId);
	std::vector<Passenger*> passengers = driver->getPassengers();
	drivers.at(driverId)->setSeats(-1);
	for(int i = 0; i < passengers.size(); ++i){
		Driver * driver = this->getDriverWithSeats();
		if( driver == NULL ){
			std::cout << "\t\t\t" << passengers.at(i)->getName() << " does not have ride! Need more drivers." << std::endl;
		} else {
			driver->addPassenger( passengers.at(i) );
		}
	}
}
