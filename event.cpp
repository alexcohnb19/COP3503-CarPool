#include <iostream>
#include "event.h"

using namespace std;

Event::Event() {
	name = name;
	date = date;
	description = description;
	time = time;
	location = location;
}

void Event::setName(string newName) {
	name = newName;
}

void Event::setDate(string newDate) {
	date = newDate;
}

void Event::setTime(string newTime) {
	time = newTime;
}

void Event::setLocation(string newLocation) {
	location = newLocation;
}

void Event::setDescription(string newDescription) {
	description = newDescription;
}

string Event::getName() {
	return name;
}

string Event::getDate() {
	return date;
}

string Event::getTime() {
	return time;
}

string Event::getLocation() {
	return location;
}

string Event::getDescription() {
	return description;
}

