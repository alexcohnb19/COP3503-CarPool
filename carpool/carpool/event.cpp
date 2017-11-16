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

