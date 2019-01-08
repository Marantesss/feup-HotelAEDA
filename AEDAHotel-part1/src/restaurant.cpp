#include "restaurant.h"

/**********************/
/** Restaurant Class **/
/**********************/

Restaurant::Restaurant() {
	this->name = "";
	this->type = "";
	this->distance = 0;
}


Restaurant::Restaurant(string name, string type, int distance) {
	this->name = name;
	this->type = type;
	this->distance = distance;
}

string Restaurant::getName() const {
	return name;
}

string Restaurant::getType() const {
	return type;
}

int Restaurant::getDistance()const {
	return distance;
}

void Restaurant::setName(string name) {
	this->name = name;
}

void Restaurant::setType(string type) {
	this->type = type;
}

void Restaurant::setDistance(int distance) {
	this->distance = distance;
}

string Restaurant::getInfo() const {
	stringstream ss;
	ss << "Name: " << name << "\t   Type: " << type << "\t   Distance: " << distance << " km";
	return ss.str();
}

bool Restaurant::operator < (const Restaurant &r) const {
	if (this->type != r.type) return this->type < r.type;
	else return this->distance < r.distance;
}

bool Restaurant::operator == (const Restaurant &r) const {
	return this->name == r.name;
}

// NonExistingRestaurant Class

NonExistingRestaurant::NonExistingRestaurant(string name) {
	this->name = name;
}
string NonExistingRestaurant::getName() {
	return this->name;
}

// ExistingRestaurant Class

ExistingRestaurant::ExistingRestaurant(string name) {
	this->name = name;
}

string ExistingRestaurant::getName() {
	return this->name;
}
