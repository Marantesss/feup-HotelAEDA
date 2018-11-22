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

void Employee::setIsSupervisor(bool supervisor) {
	this->isSupervisor = supervisor;
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
	string sup;
	if (this->isSupervisor) {
		sup = "yes";
	}
	else sup = "no";

	ss << "Name - " << name << "   Id - " << id << "   Supervisor - " << sup << endl;
	return ss.str();
}

bool Employee::getIsSupervisor() const {
	return this->isSupervisor;
}

bool Employee::operator == (int id) {
	if (this->id == id) return true;
	else return false;
}

bool Employee::operator == (string name) {
	if (this->name == name) return true;
	else return false;
}

bool Employee::operator < (Employee & e) {
	if (this->id < e.id) return true;
	else return false;
}