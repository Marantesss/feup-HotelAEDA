#include "client.h"

using namespace std;


/******************/
/** Client Class **/
/******************/

Client::Client(string name) {
	this->name = name;
	this->reservations = NULL;
}

Client::~Client() {}

string Client::getName() const {
	return this->name;
}

vector<reservation> Client::getReservations() const {
	return this->reservations;
}

void Client::setName(string name) {
	this->name = name;
}


/********************************/
/* NonExistingClient exception **/
/********************************/

NonExistingClient::NonExistingClient(string nm): name(nm) {}

string NonExistingClient::getName() const {
	return this->name;
}
