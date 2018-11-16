#include "employee.h"
#include <string>

// Employee Class


Employee::Employee(int id, string name) {
	this->id = id;
	this->getName = name;
}

void Employee::setId(int id) {
	this->id = id;
}

void Employee::setName(string name) {
	this->getName = name;
}

int Employee::getId() {
	return id;
}

string Employee::getName() {
	return name;
}

// Supervisor Class

Supervisor::Supervisor(int id, string name) :Employee(id,name)
{}

void Supervisor::addARoom(Room *r) { //!!!Finish when serch function is implemented
	this->appointedRooms.push_back(*r);
}

vector<Room> Supervisor::getARooms() {
	return this->appointedRooms;
}
