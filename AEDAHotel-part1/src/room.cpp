#include "room.h"

/****************/
/** Room Class **/
/****************/

Room::Room() {
	this->number = 0;
	this->capacity = 0;
	this->price = 0;
	this->isBedroom = true;
}

Room::Room(int number, int capacity) {
	this->number = number;
	this->capacity = capacity;
	this->price = 0;
	this->isBedroom = true;
}

Room::~Room() {};


int Room::getNumber() const {
	return this->number;
}

int Room::getCapacity() const {
	return this->capacity;
}

int Room::getFloorNumber() const {
	return this->number/100;
}

double Room::getPrice() const {
	return this->price;
}

bool Room::getIsBedroom() const {
	return this->isBedroom;
}

void Room::setNumber(int number) {
	this->number = number;
}

void Room::setCapacity(int capacity) {
	this->capacity = capacity;
}

void Room::setSupervisor(Employee e) {
	this->supervisor = e;
}

bool Room::operator== (int number) {
	if (this->number == number) return true;
	else return false;
}

bool Room::operator< (Room & room) {
	if (this->number < room.number) return true;
	else return false;
}

/***********************/
/** MeetingRoom Class **/
/***********************/

MeetingRoom::MeetingRoom():Room() {
	this->video = false;
	this->audio = false;
	this->price = 0;
	this->isBedroom = false;
}

MeetingRoom::MeetingRoom(int number, int capacity, bool video, bool audio): Room(number, capacity) {
	this->video = video;
	this->audio = audio;
	switch(capacity) {
	case 10:
		if (video && audio)
			this->price = 120;
		else if(video || audio)
			this->price = 110;
		else
			this->price = 100;
		break;
	case 25:
		if (video && audio)
			this->price = 220;
		else if(video || audio)
			this->price = 210;
		else
			this->price = 200;
		break;
	case 50:
		if (video && audio)
			this->price = 320;
		else if(video || audio)
			this->price = 310;
		else
			this->price = 300;
		break;
	}
	this->isBedroom = false;
}

bool MeetingRoom::getVideo() const {
	return this->video;
}

bool MeetingRoom::getAudio() const {
	return this->audio;
}

string MeetingRoom::getInfo() {
	stringstream ss;
	string vid;
	string aud;

	if (video) vid = "yes"; else vid = "no";
	if (audio) aud = "yes"; else aud = "no";

	// type
	ss << "Meeting Room:" << endl;
	// number and capacity
	ss << "No: " << number << "\tCapacity: " << capacity << endl;
	// video and audio
	ss << "Video: " << vid << "\tAudio: " << aud << endl;
	// price
	ss << "Price per hour: " << price << " Euros";

	return ss.str();
}

void MeetingRoom::setVideo(bool video) {
	this->number = number;
}

void MeetingRoom::setAudio(bool audio) {
	this->capacity = capacity;
}

void MeetingRoom::setPricePerHour(double price) {
	this->price = price;
}

void MeetingRoom::setDefaultPrice() {
	switch (capacity) {
	case 10:
		if (video && audio)
			this->price = 120;
		else if (video || audio)
			this->price = 110;
		else
			this->price = 100;
		break;
	case 25:
		if (video && audio)
			this->price = 220;
		else if (video || audio)
			this->price = 210;
		else
			this->price = 200;
		break;
	case 50:
		if (video && audio)
			this->price = 320;
		else if (video || audio)
			this->price = 310;
		else
			this->price = 300;
		break;
	}
}

/*******************/
/** Bedroom Class **/
/*******************/

Bedroom::Bedroom():Room() {
	this->location = { };
}

Bedroom::Bedroom(int number, int capacity, string location): Room(number, capacity) {
	this->location = location;
	switch(capacity) {
	case 1:
		if (location == "Front")
			this->price = 50;
		else if (location == "Back")
			this->price = 40;
		break;
	case 2:
		if (location == "Front")
			this->price = 75;
		else if (location == "Back")
			this->price = 60;
		break;
	}
}

string Bedroom::getLocation() const {
	return this->location;
}

string Bedroom::getInfo() {
	stringstream ss;

	// type
	ss << "Bedroom:" << endl;
	// number and capacity
	ss << "No: " << number << "\tCapacity: " << capacity << endl;
	// location
	ss << "Location: " << location << endl;
	// price
	ss << "Price per night: " << price << " Euros";

	return ss.str();
}

void Bedroom::setLocation(string location) {
	this->location = location;
}

void Bedroom::setPricePerDay(double price) {
	this->price = price;
}

void Bedroom::setDefaultPrice() {
	switch (capacity) {
	case 1:
		if (location == "Front")
			this->price = 50;
		else if (location == "Back")
			this->price = 40;
		break;
	case 2:
		if (location == "Front")
			this->price = 75;
		else if (location == "Back")
			this->price = 60;
		break;
	}
}


/*******************************/
/** NonExistingRoom exception **/
/*******************************/

NonExistingRoom::NonExistingRoom(int num): number(num) {}

int NonExistingRoom::getNumber() const {
	return this->number;
}
