#include "hotel.h"

/*****************/
/** Hotel Class **/
/*****************/

Hotel::Hotel(int floors, int bedrooms, int meetingRooms, string address) {
	this->floors = floors;
	this->nbedrooms = bedrooms;
	this->nmeetingrooms = meetingRooms;
	this->address = address;
}

Hotel::~Hotel() {}

void Hotel::sortClients() {
	insertionSort(clients);
}

//... Clients
vector<Client> Hotel::getClients() const {
	return this->clients;
}

void Hotel::addClient(Client c) {
	this->clients.push_back(c);
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
				for (int i = 0; i < rooms.size(); i++) {
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

int Hotel::removeClient(string name) {
	for (size_t i = 0; i <= clients.size(); i++) {
		if (clients[i].getName() == name) {
			this->clients.erase(clients.begin() + i);
			return 0;
		}
	}
	return -1;
}

//... Rooms
vector<Room> Hotel::getRooms() const{
	return rooms;
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

void Hotel::addRoom(Room r) {
	this->rooms.push_back(r);
}

void Hotel::removeRoom(int i) {
	this->rooms.erase(rooms.begin() + 1);
}

void Hotel::removeRoomsFromTopFloor() {
	for (size_t i = 0; i < rooms.size(); i++) {
		if (floors == rooms[i].getFloorNumber()) {
			removeRoom(rooms[i].getNumber());
		}
	}
}

void Hotel::showRooms() {
	for (int i = 0; i < rooms.size(); i++) {
		cout << i + 1 << "- " << this->rooms.at(i).getInfo() << endl;
	}
}


//... Reservations
vector<Reservation> Hotel::getReservations() const {
	return this->reservations;
}

void Hotel::addReservation(Reservation R) {
	this->reservations.push_back(R);
}

void Hotel::removeReservation(Date d, Room R) {
	//TO DO
}

//... Employees
vector<Employee> Hotel::getEmployees() const {
	return this->employees;
}

void Hotel::addEmployee(Employee E) {
	this->employees.push_back(E);
}

void Hotel::removeEmployee(int id) {
	int i;
	if (i = sequencialSearch(this->getEmployees(), id) == -1) {
		cout << "Error - Employee with the id " << id << " not found!" << endl;
	}
	this->employees.erase(this->employees.begin() + i);
}

void Hotel::showEmployees() {
	for (int i = 0; i < employees.size(); i++) {
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

	//for (unsigned int i = 0; i < rooms.size(); i++)
		//this->rooms.at(i).setSupervisor(tmp.at(i%tmp.size()));
}

int Hotel::getNoSupervisors() {
	int counter = 0;

	for (size_t i = 0; i < this->employees.size(); i++) {
		if (this->employees.at(i).getIsSupervisor()) {
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

int Hotel::getNoMeetingRooms() {
	int counter = 0;
	for (int i = 0; i < rooms.size(); i++) {
		if (!rooms.at(i).getisBedRoom()) counter++;
	}
	return counter;
}

int Hotel::getNoBedrooms() {
	int counter = 0;
	for (int i = 0; i < rooms.size(); i++) {
		if (rooms.at(i).getisBedRoom()) counter++;
	}
	return counter;
}

//... Hotel Information
// Floors
int Hotel::getFloors() const { return this->floors; }
void Hotel::addFloor() { this->floors++; }
void Hotel::removeFloor() { this->floors--; }
// Bedrooms
int Hotel::getnBedrooms() const { return this->nbedrooms; }
void Hotel::addBedroom() { this->nbedrooms++; }
// MeetingRooms
int Hotel::getnMeetingRooms() const { return this->nmeetingrooms; }
void Hotel::addMeetingRoom() { this->nmeetingrooms++; }
// Address
string Hotel::getAddress() const { return this->address; }
void Hotel::setAddress(string address) { this->address = address; }
