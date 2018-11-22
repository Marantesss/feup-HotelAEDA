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
					if (rooms.at(i) == room) {
						Room c =  rooms.at(i);
						r.setRoom(&c);
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
	return -1;
}

//... Rooms
vector<Room> Hotel::getRooms() const{
	return this->rooms;
}

void Hotel::addRoom(Room & r) {
	this->rooms.push_back(r);

	if (typeid(r) == typeid(Bedroom)) {
		bedrooms++;
	}
	else if (typeid(r) == typeid(MeetingRoom)) {
		meetingrooms++;
	}
}

void Hotel::removeRoom(int i) {
	vector<Room>::iterator it;
	for (it = rooms.begin(); it != rooms.end(); it++) {
		if (it->getNumber() == i) {
			if (typeid(*it) == typeid(Bedroom)) {
				bedrooms--;
			}
			else if (typeid(*it) == typeid(MeetingRoom)) {
				meetingrooms--;
			}
			this->rooms.erase(it);
			return;
		}
	}
	throw (NonExistingRoom(i));
}

vector<Room> Hotel::getFloorNumberRooms(int floor) const {
	vector<Room> returnRooms;
	for (size_t i = 0; i < rooms.size(); i++) {
		if (rooms[i].getFloorNumber() == floor) {
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
			if (rooms[i].getFloorNumber() == i) {
				if (j == rooms.size() - 1) {
					ss << rooms[j].getNumber() << endl;
				}
				else {
					ss << rooms[j].getNumber() << ", ";
				}
			}
		}
	}

	return ss.str();
}

void Hotel::removeRoomsFromTopFloor() {
	vector<Room>::iterator it;
		for (it = rooms.begin(); it != rooms.end(); it++) {
			if (it->getFloorNumber() == this->floors) {
			removeRoom(it->getNumber());
		}
	}
}

void Hotel::showRooms() {
	for (size_t i = 0; i < rooms.size(); i++) {
		cout << i + 1 << " - " << this->rooms.at(i).getInfo() << endl;
	}
}

int Hotel::sequencialSearchRooms(int num) {
	for (unsigned int i = 0; i < rooms.size(); i++)
		if (rooms[i].getNumber() == num)
			return i;
	return -1;
}

//... Reservations
vector<Reservation> Hotel::getReservations() const {
	return this->reservations;
}

void Hotel::addReservation(Reservation R) {
	this->reservations.push_back(R);
}

void Hotel::removeReservation(Date d, Room R) {
	vector<Reservation>::iterator it;
	for (it = reservations.begin(); it != reservations.end(); it++) {
		if (it->getDate() == d && it->getRoom() == &R) {
			this->rooms.erase(rooms.begin());
			return;
		}
	}
	throw (NonExistingReservation(d, &R));
}

//... Employees
vector<Employee> Hotel::getEmployees() const {
	return this->employees;
}

void Hotel::addEmployee(Employee E) {
	this->employees.push_back(E);
}

void Hotel::removeEmployee(int id) {
	int i = sequencialSearch(this->getEmployees(), id);
	if (i == -1) {
		cout << "Error - Employee with the id " << id << " not found!" << endl;
	}
	this->employees.erase(this->employees.begin() + i);
}

void Hotel::showEmployees() {
	for (size_t i = 0; i < employees.size(); i++) {
		cout << i+1 << "- " << employees.at(i).getInfo() << endl;
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
