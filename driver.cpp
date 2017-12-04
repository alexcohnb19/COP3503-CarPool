#include <iostream>
#include "driver.h"

bool isNum( std::string seats ){
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
Driver::Driver(std::string name, std::string phoneNum,  int seats){
  this->phoneNum = phoneNum;
  this->name = name;
  this->seats = seats;
}

std::string Driver::getPhoneNum(){
  return this->phoneNum;
}

std::string Driver::getName(){
  return this->name;
}

int Driver::getSeats(){
  return this->seats;
}

void Driver::setSeats(int seats){
  this->seats = seats;
}

bool Driver::addPassenger( Passenger * passenger ) {
	passengers.push_back(passenger);
	seats = seats - 1;
	return true;
}

std::vector<Passenger*> Driver::getPassengers(){
	return passengers;
}

void Driver::viewPassengers(){
	for(int k = 0; k < passengers.size(); ++k){
		std::cout<<"\t\t\t\t" << k+1 << ". " << passengers.at(k)->getName() << "\t" << passengers.at(k)->getPhoneNum() << std::endl;
	}
}

void Driver::deletePass(int passengerId){
	this->passengers.at(passengerId)->setName("");
	this->passengers.at(passengerId)->setPhoneNum("");
}

void Driver::deletePassenger(){
	this->viewPassengers();
	std::string passengerId = "";
	bool invalidInput = true;
	int intPassenger = 0;
	std::cout << "\t\t\tSelect a driver: ";
	while( invalidInput ){
		std::getline( std::cin, passengerId );
		//Check if integer for input for seats
		if( isNum( passengerId )) {
		    intPassenger = std::atoi( passengerId.c_str() );  
			//Ensure seats are not obscenly huge
			if( intPassenger > 0 && intPassenger <= this->passengers.size() ){
			    invalidInput = false;
			} else {
			     std::cout << "\t\t------INVALID INPUT-----" << std::endl;
			     std::cout << "\t\t\tDriver Id: ";
			}
		} else {
		    std::cout << "\t\t------INVALID INPUT-----" << std::endl;
			std::cout << "\t\t\tDriver Id: ";
		}
	}

	this->deletePass(intPassenger-1);
	this->seats = ++this->seats;
}
