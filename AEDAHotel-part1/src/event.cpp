#include <iostream>
#include "event.h"

/*******************/
/*** Event Class ***/
/*******************/

Event::Event() {
	this->name = "";
	this->date = Date();
	this->location = "";
	this->description = "";
}

Event::Event(string name, Date date, string location, string description) {
	this->name = name;
	this->date = date;
	this->location = location;
	this->description = description;
}

Date Event::getDate() const {
	return this->date;
}

string Event::getName() const {
	return this->name;
}

string Event::getLocation() const {
	return this->location;
}

string Event::getDescription() const {
	return this->description;
}

string Event::getInfo() const {
	stringstream ss;

	ss << "Name: " << this->name << endl;
	ss << "Date: " << this->date.getExtendedDate() << endl;
	ss << "Location: " << this->location << endl;
	ss << "Description: " << this->description << endl;

	return ss.str();
}

bool Event::operator < (Event ev) const {
	return ev.getDate() < this->getDate();
}
