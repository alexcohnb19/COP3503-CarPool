#include <iostream>
#include <string>
#include "driver.h"

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