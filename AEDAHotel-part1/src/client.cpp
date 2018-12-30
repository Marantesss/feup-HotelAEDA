#include "client.h"

using namespace std;


/******************/
/** Client Class **/
/******************/

int Client::nextId = 1;

Client::Client(string name, Date birthday) {
	this->name = name;
	this->birthday = birthday;
	this->id = this->nextId;
	nextId++;
}

Client::Client() {
	this->id = this->nextId;
	nextId++;
}

Client::~Client() {}

string Client::getName() const {
	return this->name;
}

void Client::setName(string name) {
	this->name = name;
}

int Client::getId() const {
	return this->id;
}

bool  Client::operator< (Client &c2) {
	if (this->id < c2.id) return true;
	else return false;
}

void Client::addReservation(Reservation * R) {
	this->reservations.push_back(R);
}

vector<Reservation*> Client::getReservations() const {
	return this->reservations;
}


string Client::getInfo() const {
	stringstream ss;
	ss << "ID: " << id << endl;
	ss << "Name: " << name << endl;
	ss << "Birthday: " << this->birthday.showExtendedDate() << endl;

	if (!this->reservations.empty()) {
		ss << "Reservations:" << endl;
		for (size_t i = 0; i < reservations.size(); i++) {
			ss << i + 1 << ": " << reservations[i]->getInfo() << endl;
		}
	}
	else {
		ss << "(This client has no reservations)" << endl;
	}

	return ss.str();
}

bool Client::operator == (Client c) {
	if (this->id == c.id)
		return true;
	else
		return false;
}

/********************************/
/* NonExistingClient exception **/
/********************************/

NonExistingClient::NonExistingClient(string nm): name(nm) {}

string NonExistingClient::getName() const {
	return this->name;
}
