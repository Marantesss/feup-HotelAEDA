#include "room.h"

/****************/
/** Room Class **/
/****************/

Room::Room(int number, int capacity) {
	this->number = number;
	this->capacity = capacity;
}

Room::~Room() {}

int Room::getNumber() const {
	return this->number;
}

int Room::getCapacity() const {
	return this->capacity;
}

void Room::setNumber(int number) {
	this->number = number;
}

void Room::setCapacity(int capacity) {
	this->capacity = capacity;
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

MeetingRoom::~MeetingRoom() {}

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

void MeetingRoom::setPrice(int price) {
	this->price = price;
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

Bedroom::~Bedroom() {}

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


/*******************************/
/** NonExistingRoom exception **/
/*******************************/

NonExistingRoom::NonExistingRoom(int num): number(num) {}

int NonExistingRoom::getNumber() const {
	return this->number;
}
