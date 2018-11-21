#include "employee.h"
#include <string>

// Employee Class


Employee::Employee(int id, string name, bool supervisor) {
	this->id = id;
	this->name = name;
	this->isSupervisor = supervisor;
}

Employee::Employee() {
	this->id = 0;
	this->name = {};
	this->isSupervisor = false;
}

void Employee::setId(int id) {
	this->id = id;
}

void Employee::setName(string name) {
	this->name = name;
}

int Employee::getId() {
	return id;
}

string Employee::getName() {
	return name;
}

string Employee::getInfo() const {
	stringstream ss;
	ss << "Name - " << name << "Id - " << id;
	return ss.str();
}

bool Employee::getIsSupervisor() const {
	return this->isSupervisor;
}

bool Employee::operator == (int id) {
	if (this->id == id) return true;
	else return false;
}

bool Employee::operator < (Employee & e) {
	if (this->id < e.id) return true;
	else return false;
}


/* Supervisor Class

Supervisor::Supervisor(int id, string name) :Employee(id,name)
{}

string Supervisor::getInfo() const {
	stringstream ss;
	ss << "Supervisor:\n" << Employee::getInfo() << endl;
	return ss.str();
}

bool Supervisor::isSupervisor() const {
	return true;
}*/
