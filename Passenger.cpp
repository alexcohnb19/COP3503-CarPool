#include <iostream>
#include <string>
#include "Passenger.h"

Passenger::Passenger(std::string name, std::string phoneNum) {
	this->phoneNum = phoneNum;
	this->name = name;
}

std::string Passenger::getName() {
	return this->name;
}

std::string Passenger::getPhoneNum() {
	return this->phoneNum;
}

void Passenger::setName( std::string name ){
	this->name = name;
}

void Passenger::setPhoneNum( std::string phoneNum ){
	this->phoneNum = phoneNum;
}
