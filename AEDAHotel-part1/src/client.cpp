#include "client.h"

using namespace std;


/******************/
/** Client Class **/
/******************/

Client::Client(string name) {
	this->name = name;
}

Client::Client() {
}

Client::~Client() {}

string Client::getName() const {
	return this->name;
}

void Client::setName(string name) {
	this->name = name;
}

bool  Client::operator< (Client &c2) {
	if (this->name <= c2.name) return true;
	else return false;
}

void Client::addReservation(Reservation R) {
	this->reservations.push_back(R);
}

string Client::getInfo() const {
	stringstream ss;
	ss << "Name: " << name << endl;
	if (!this->reservations.empty()) {
		ss << "Reservations:" << endl;
		for (size_t i = 0; i < reservations.size(); i++) {
			ss << i + 1 << ": " << reservations[i].getInfo() << endl;
		}
	}
	else {
		ss << "(This client has no reservations)" << endl;
	}
	return ss.str();
}

bool Client::operator == (string name) {
	if (this->name == name) return true;
	else return false;
}

/********************************/
/* NonExistingClient exception **/
/********************************/

NonExistingClient::NonExistingClient(string nm): name(nm) {}

string NonExistingClient::getName() const {
	return this->name;
}
