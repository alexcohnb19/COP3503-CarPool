#include "stdafx.h"
#include <iostream>
#include <string>
#include "passenger.h"

Passenger::Passenger(std::string phoneNum, std::string name) {
	this->phoneNum = phoneNum;
	this->name = name;
}

std::string Passenger::getName() {
	return this->name;
}

std::string Passenger::getPhoneNum() {
	return this->phoneNum;
}

