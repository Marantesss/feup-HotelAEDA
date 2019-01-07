#include "restaurant.h"

/**********************/
/** Restaurant Class **/
/**********************/

Restaurant::Restaurant() {
	this->name = {};
	this->type = {};
	this->distance = 0;
}


Restaurant::Restaurant(string name, string type, int distance) {
	this->name = name;
	this->type = type;
	this->distance = distance;
}

string Restaurant::getName() {
	return name;
}

string Restaurant::getType() {
	return type;
}

int Restaurant::getDistance() {
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
