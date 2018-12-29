#include "employee.h"
#include <string>

/********************/
/***** Employee *****/
/********************/

int Employee::nextId = 1;

Employee::Employee() {
	this->id = this->nextId;
	this->name = "";
	this->isSupervisor = false;
	this->nextId++;
}

Employee::Employee(string name, bool supervisor) {
	this->id = this->nextId;
	this->name = name;
	this->isSupervisor = supervisor;
	this->nextId++;
}

int Employee::getId() {
	return this->id;
}

string Employee::getName() {
	return this->name;
}

bool Employee::getIsSupervisor() const {
	return this->isSupervisor;
}

string Employee::getInfo() const {
	stringstream ss;
	string isSupervisor;
	if (this->isSupervisor) isSupervisor = "yes";
	else isSupervisor = "no";
	ss << "Name: " << name << ";  Id: " << id << ";  Supervisor: " << isSupervisor;
	return ss.str();
}

void Employee::setId(int id) {
	this->id = id;
}

void Employee::setName(string name) {
	this->name = name;
}

void Employee::setIsSupervisor(bool supervisor) {
	this->isSupervisor = supervisor;
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

/***********************************/
/** NonExistingEmployee exception **/
/***********************************/

NonExistingEmployee::NonExistingEmployee(int id): id(id) {}

int NonExistingEmployee::getId() const {
	return this->id;
}
