#include "stdafx.h"
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
	for (int i = 0; i < drivers.size(); ++i) {
		std::cout << drivers.at(i)->getName() << " Num seats: " << drivers.at(i)->getSeats() << std::endl;
	}
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

