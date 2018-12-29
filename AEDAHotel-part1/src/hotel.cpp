#include "hotel.h"

/*****************/
/** Hotel Class **/
/*****************/

Hotel::Hotel() {
	this->floors = 0;
	this->bedrooms = 0;
	this->meetingrooms = 0;
	this->address = "";
};

Hotel::Hotel(int floors, string address) {
	this->floors = floors;
	this->bedrooms = 0;
	this->meetingrooms = 0;
	this->address = address;
}

Hotel::~Hotel() {}

//... Clients
vector<Client> Hotel::getClients() const {
	return this->clients;
}

void Hotel::addClient(Client c) {
	this->clients.push_back(c);
}

void Hotel::removeClient(string name) {
	vector<Client>::iterator it;
	for (it = clients.begin(); it != clients.end(); it++) {
		if (it->getName() == name) {
			this->clients.erase(it);
			return;
		}
	}
	throw (NonExistingClient(name));
}

void Hotel::showClients() {
	for (size_t i = 0; i < clients.size(); i++) {
		cout << clients.at(i).getInfo() << endl;
	}
}

void Hotel::sortClients() {
	insertionSort(clients);
}

void Hotel::importClientsandReservations(string filename) {
	ifstream file;
	int noReservations, room, duration;
	string line,name;
	file.open(filename);
	Client c = Client();
	Date d = Date();
	Reservation r = Reservation();
	if (file.is_open())
	{
		while (getline(file, line))
		{
			name = line;
			c.setName(name);
			this->clients.push_back(c);
			getline(file, line);
			noReservations = atoi(line.c_str());
			getline(file, line);
			for (int i = 1; i <= noReservations; i++) {
				getline(file, line);
				d.setDay(atoi(line.c_str()));
				getline(file, line);
				d.setMonth(atoi(line.c_str()));
				getline(file, line);
				d.setYear(atoi(line.c_str()));
				getline(file, line);
				room = atoi(line.c_str());
				for (size_t i = 0; i < rooms.size(); i++) {
					if (*(rooms.at(i)) == room) {
						r.setRoom(rooms[i]);
					}
				}
				getline(file, line);
				duration = atoi(line.c_str());
				r.setDuration(duration);
				this->reservations.push_back(r);
			}
		}
		file.close();
	}
	else cout << "Unable to open file";
}

int Hotel::sequencialSearchClients(string name) {
	for (unsigned int i = 0; i < clients.size(); i++)
		if (clients[i].getName() == name)
			return i;
	throw (NonExistingClient(name));
	return -1;
}

//... Rooms
vector<Room*> Hotel::getRooms() const{
	return this->rooms;
}

void Hotel::addRoom(Room *r) {
	// Checking if the room is valid
	for (size_t i = 0; i < rooms.size(); i++) {
		if (rooms[i]->getNumber() == r->getNumber()) {
			throw (NonExistingRoom(r->getNumber()));
			return;
		}
	}
	// Adding the room
	this->rooms.push_back(r);
	if (r->getIsBedroom()) {
		bedrooms++;
	}
	else {
		meetingrooms++;
	}
}

void Hotel::removeRoom(int num) {
	for (size_t i = 0; i < rooms.size(); i++) {
		if (rooms[i]->getNumber() == num) {
			if (rooms[i]->getIsBedroom()) {
				bedrooms--;
			}
			else {
				meetingrooms--;
			}
			this->rooms.erase(rooms.begin() + i);
			return;
		}
	}
	throw (NonExistingRoom(num));
}

void Hotel::sortRooms() {
	insertionSort(rooms);
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
			if (rooms[j]->getFloorNumber() == i) {
				if (rooms[j + 1]->getFloorNumber() == i + 1) {
					ss << rooms[j]->getInfo() << endl;
				}
				else if (rooms.size()  == j + 1) {
					ss << rooms[j]->getInfo();
				}
				else {
					ss << rooms[j]->getInfo() << ", ";
				}
			}
		}
	}

	return ss.str();
}

void Hotel::removeRoomsFromTopFloor() {
	for (size_t i = 0; i < rooms.size(); i++) {
		if (rooms[i]->getFloorNumber() == this->floors) {
			removeRoom(rooms[i]->getNumber());
			i--;
		}
	}
}

int Hotel::sequencialSearchRooms(int num) {
	for (unsigned int i = 0; i < rooms.size(); i++)
		if (rooms[i]->getNumber() == num)
			return i;
	throw (NonExistingRoom(num));
	return -1;
}

//... Reservations
vector<Reservation> Hotel::getReservations() const {
	return this->reservations;
}

void Hotel::addReservation(Reservation R) {
	// Checking if the reservation is valid
	vector<Reservation>::iterator it;
	for (it = reservations.begin(); it != reservations.end(); it++) {
		if (it->getDate() == R.getDate() && it->getRoom() == R.getRoom()) {
			throw (NonExistingReservation(R.getDate(), R.getRoom()));
			return;
		}
	}
	// adding the reservation
	this->reservations.push_back(R);
}

void Hotel::sortReservations() {
	insertionSort(rooms);
}

void Hotel::removeReservation(Date d, Room * R) {
	for (size_t i = 0; i < reservations.size(); i++) {
		if (reservations[i].getDate() == d && reservations[i].getRoom() == R) {
			this->reservations.erase(reservations.begin() + i);
			return;
		}
	}
	throw (NonExistingReservation(d, R));
}

void Hotel::removeRoomReservations(Room * R) {
	vector<Reservation>::iterator it;
	for (it = reservations.begin(); it != reservations.end(); it++) {
		if (it->getRoom() == R) {
			removeReservation(it->getDate(), it->getRoom());
		}
	}
}

void Hotel::removeFloorReservations(int floor) {
	vector<Reservation>::iterator it;
	for (it = reservations.begin(); it != reservations.end(); it++) {
		if (it->getRoom()->getFloorNumber() == floor) {
			removeRoomReservations(it->getRoom());
		}
	}
}

void Hotel::showReservations() {
	for (size_t i = 0; i < reservations.size(); i++) {
		cout << i+1 << " - " << reservations.at(i).getInfo() << endl;
	}
}

//... Employees
vector<Employee> Hotel::getEmployees() const {
	return this->employees;
}

void Hotel::addEmployee(Employee E) {
	// Checking if the employee is valid
	vector<Employee>::iterator it;
	for (it = employees.begin(); it != employees.end(); it++) {
		if (it->getId() == E.getId()) {
			throw (NonExistingEmployee(E.getId()));
			return;
		}
	}
	// adding the employee
	this->employees.push_back(E);
}

void Hotel::removeEmployee(int id) {
	vector<Employee>::iterator it;
	for (it = employees.begin(); it != employees.end(); it++) {
		if (it->getId() == id) {
			this->employees.erase(it);
			return;
		}
	}
	throw (NonExistingEmployee(id));
}

void Hotel::sortEmployees() {
	insertionSort(reservations);
}

void Hotel::showEmployees() {
	for (size_t i = 0; i < employees.size(); i++) {
		cout << i+1 << " - " << employees.at(i).getInfo() << endl;
	}
}

void Hotel::allocateEmployees() {
	vector<Employee> tmp;

	for (size_t i = 0;  i < this->employees.size(); i++) {
		if (this->employees.at(i).getIsSupervisor()) {
			tmp.push_back(this->employees.at(i));
		}
	}
}

int Hotel::getNoSupervisors() {
	int counter = 0;
	vector<Employee>::iterator it;
	for (it = employees.begin(); it != employees.end(); it++) {
		if (it->getIsSupervisor()) {
			counter++;
		}
	}
	return counter;
}

void Hotel::importEmployees(string filename){
	string name,line;
	ifstream file;
	int id;
	bool supervisor;
	Employee e = Employee();
	file.open(filename);
	if (file.is_open())
	{
		while(getline(file, line))
		{
			id = atoi(line.c_str());
			e.setId(id);
			getline(file, line);
			name = line;
			e.setName(name);
			getline(file, line);
			if (line == "true") supervisor = true;
			else if (line == "false") supervisor = false;
			e.setIsSupervisor(supervisor);
			this->employees.push_back(e);
		}
		file.close();
	}

	else cout << "Unable to open file";
}

int Hotel::sequencialSearchEmployees(int id) {
	for (unsigned int i = 0; i < employees.size(); i++)
		if (employees[i].getId() == id)
			return i;
	throw (NonExistingEmployee(id));
	return -1;
}

//... Hotel Information
// Floors
int Hotel::getFloors() const {
	return this->floors;
}

void Hotel::addFloor() {
	this->floors++;
}

void Hotel::removeFloor() {
	this->floors--;
}

// Bedrooms
int Hotel::getBedrooms() const {
	return this->bedrooms;
}

// MeetingRooms
int Hotel::getMeetingRooms() const {
	return this->meetingrooms;
}
// Address
string Hotel::getAddress() const {
	return this->address;
}

void Hotel::setAddress(string address) {
	this->address = address;
}
