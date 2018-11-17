#include "client.h"

using namespace std;


/******************/
/** Client Class **/
/******************/

Client::Client(string name) {
	this->name = name;
	this->reservations = {};
}

Client::~Client() {}

string Client::getName() const {
	return this->name;
}

vector<Reservation> Client::getReservations() const {
	return this->reservations;
}

void Client::setName(string name) {
	this->name = name;
}

void Client::addReservation(Reservation reservation) {
	reservations.push_back(reservation);
}

bool  Client::operator< (Client &c2) {
	if (this->name <= c2.name) return true;
	else return false;
}

// To be completed -- Add reservations
string Client::getInfo() const {
	stringstream ss;
	ss << "Name: " << name;
	return ss.str();
}

/********************************/
/* NonExistingClient exception **/
/********************************/

NonExistingClient::NonExistingClient(string nm): name(nm) {}

string NonExistingClient::getName() const {
	return this->name;
}
