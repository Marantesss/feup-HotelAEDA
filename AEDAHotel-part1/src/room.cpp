#include "room.h"

/****************/
/** Room Class **/
/****************/

Room::Room(int number, int capacity) {
	this->number = number;
	this->capacity = capacity;
	this->supervisor = NULL;
}

Room::Room() {
	this->number = 0;
	this->capacity = 0;
	this->supervisor = NULL;
}

int Room::getNumber() const {
	return this->number;
}

int Room::getCapacity() const {
	return this->capacity;
}

int Room::getPrice() const {
	return 0;
}

void Room::setNumber(int number) {
	this->number = number;
}

void Room::setCapacity(int capacity) {
	this->capacity = capacity;
}

void Room::setSupervisor(Supervisor *s) {
	this->supervisor = s;
}

string Room::getInfo() const {
	stringstream ss;
	ss << "\tNumber - " << number << "\n\tCapacity - " << capacity;
	return ss.str();
}

/***********************/
/** MeetingRoom Class **/
/***********************/

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
}

bool MeetingRoom::getVideo() const {
	return this->video;
}

bool MeetingRoom::getAudio() const {
	return this->audio;
}

int MeetingRoom::getPrice() const {
	return this->price;
}

void MeetingRoom::setVideo(bool video) {
	this->number = number;
}

void MeetingRoom::setAudio(bool audio) {
	this->capacity = capacity;
}

void MeetingRoom::setPricePerHour(int price) {
	this->price = price;
}

string MeetingRoom::getInfo() const {
	stringstream ss;
	string vid;
	string aud;

	if (video) vid = "yes"; else vid = "no";
	if (audio) aud = "yes"; else aud = "no";

	ss << "Meeting Room: \n" << Room::getInfo() << "\n\tVideo - " << vid << "\n\tAudio - " << aud << "\n\tPrice per hour - " << price << " Euros";

	return ss.str();
}



/*******************/
/** Bedroom Class **/
/*******************/

Bedroom::Bedroom(int number, int capacity, string location): Room(number, capacity) {
	this->location = location;
	switch(capacity) {
	case 1:
		this->price = 50;
		break;
	case 2:
		this->price = 75;
		break;
	}
}

string Bedroom::getLocation() const {
	return this->location;
}

int Bedroom::getPrice() const {
	return this->price;
}

void Bedroom::setLocation(string location) {
	this->location = location;
}

void Bedroom::setPrice(int price) {
	this->price = price;
}

string Bedroom::getInfo() const {
	stringstream ss;

	ss << "Bedroom: \n"  << Room::getInfo() << "\nLocation - " << location << "\nPrice per night - " << price << " Euros";

	return ss.str();
}


/*******************************/
/** NonExistingRoom exception **/
/*******************************/

NonExistingRoom::NonExistingRoom(int num): number(num) {}

int NonExistingRoom::getNumber() const {
	return this->number;
}
