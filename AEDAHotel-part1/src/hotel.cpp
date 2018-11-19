#include "hotel.h"

/*****************/
/** Hotel Class **/
/*****************/

Hotel::Hotel(int floors, int bedrooms, int meetingRooms, string address) {
	this->floors = floors;
	this->bedrooms = bedrooms;
	this->meetingRooms = meetingRooms;
	this->address = address;
}

Hotel::~Hotel() {}

//... Clients
vector<Client*> Hotel::getClients() const {
	return this->clients;
}

void Hotel::addClient(Client * c) {
	this->clients.push_back(c);
}

int Hotel::removeClient(string name) {
	for (size_t i = 0; i <= clients.size(); i++) {
		if (clients[i]->getName() == name) {
			this->clients.erase(clients.begin() + i);
			return 0;
		}
	}
	return -1;
}

//... Rooms
vector<Room*> Hotel::getRooms() const {
	return this->rooms;
}

vector<Room*> Hotel::getFloorNumberRooms(int floor) const {
	vector<Room*> returnRooms;

	for (size_t i = 0; i < rooms.size(); i++) {
		if (rooms[i]->getFloorNumber() == floor) {
			returnRooms.push_back(rooms[i]);
		}
	}

	return returnRooms;
}

string Hotel::getRoomsInfo() {
	stringstream ss;
	for (int i = 1; i <= getFloors(); i++) {
		ss << "Floor " << i << ": ";
		for (size_t j = 0; j < rooms.size(); j++) {
			if (rooms[i]->getFloorNumber() == i) {
				if (j == rooms.size() - 1) {
					ss << rooms[j]->getNumber() << endl;
				}
				else {
					ss << rooms[j]->getNumber() << ", ";
				}
			}
		}
	}
	return ss.str();
}

void Hotel::addRoom(Room * r) {
	this->rooms.push_back(r);
}

//TO CHANGE - THROW EXCEPTION
void Hotel::removeRoom(int number) {
	for (size_t i = 0; i < rooms.size(); i++) {
		if (rooms[i]->getNumber() == number) {
			this->rooms.erase(rooms.begin() + i);
		}
	}
}

void Hotel::removeRoomsFromFloor(int floor) {
	for (size_t i = 0; i < rooms.size(); i++) {
		if (floor == rooms[i]->getFloorNumber()) {
			removeRoom(rooms[i]->getNumber());
		}
	}
}


//... Reservations
vector<Reservation*> Hotel::getReservations() const {
	return this->reservations;
}

void Hotel::addReservation(Reservation * R) {
	this->reservations.push_back(R);
}

void Hotel::removeReservation(Date *d, Room *R) {
	//TO DO
}

//... Employees
vector<Employee*> Hotel::getEmployees() const {
	return this->employees;
}

void Hotel::addEmployee(Employee *E) {
	this->employees.push_back(E);
}

void Hotel::removeEmployee(string name) {
	//TO DO
}

//... Hotel Information
// Floors
int Hotel::getFloors() const { return this->floors; }
void Hotel::addFloor() { this->floors++; }
void Hotel::removeFloor() { this->floors--; }
// Bedrooms
int Hotel::getBedrooms() const { return this->bedrooms; }
void Hotel::addBedroom() { this->bedrooms++; }
void Hotel::removeBedroom() { this->bedrooms--; }
// MeetingRooms
int Hotel::getMeetingRooms() const { return this->meetingRooms; }
void Hotel::addMeetingRoom() { this->meetingRooms++; }
void Hotel::removeMeetingRoom() { this->meetingRooms--; }
// Address
string Hotel::getAddress() const { return this->address; }
void Hotel::setAddress(string address) { this->address = address; }
