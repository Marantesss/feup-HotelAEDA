#include "hotel.h"

/*****************/
/** Hotel Class **/
/*****************/

Hotel::Hotel():restaurants(Restaurant()) {
	this->floors = 0;
	this->bedrooms = 0;
	this->meetingrooms = 0;
	this->trips = 0;
	this->address = "";
};

Hotel::Hotel(int floors, string address, int trips):restaurants(Restaurant()) {
	this->floors = floors;
	this->bedrooms = 0;
	this->meetingrooms = 0;
	this->trips = 0;
	this->address = address;
}

Hotel::~Hotel() {}

//... Clients
vector<Client*> Hotel::getClients() const {
	return this->clients;
}

void Hotel::addClient(Client *c) {
	this->clients.push_back(c);
}

void Hotel::removeClient(string name) {
	for (size_t i = 0; i < clients.size(); i++) {
		if (clients[i]->getName() == name) {
			this->clients.erase(clients.begin() + i);
			return;
		}
	}
	throw (NonExistingClient(name));
}

void Hotel::showClients() {
	for (size_t i = 0; i < clients.size(); i++) {
		cout << clients.at(i)->getInfo() << endl;
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
			this->clients.push_back(&c);
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
	else cout << "Unable to open file" << endl;
	this->importVans("vans.txt");
}

int Hotel::sequencialSearchClients(string name) {
	for (unsigned int i = 0; i < clients.size(); i++)
		if (clients[i]->getName() == name)
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

string Hotel::getRoomsInfo() const {
	stringstream ss;
	for (int i = 1; i <= getFloors(); i++) {
		ss << "_____________________________________" << endl;
		ss << " ------------ Floor " << i << " ------------ " << endl;
		for (size_t j = 0; j < rooms.size(); j++) {
			if (rooms[j]->getFloorNumber() == i) {
				ss << rooms[j]->getInfo() << endl;
				ss << " ------------------------ " << endl;
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

	else cout << "Unable to open file" << endl;
}

int Hotel::sequencialSearchEmployees(int id) {
	for (unsigned int i = 0; i < employees.size(); i++)
		if (employees[i].getId() == id)
			return i;
	throw (NonExistingEmployee(id));
	return -1;
}

//... Vans
void Hotel::addGroup(vector<Client*>& group) {
	vector<Van> vanVec;
	Van van = Van();
	unsigned i = 0;
	int gr = (int) group.size();

	if (vans.size() == 0)
		addVan(van);

	if (group.size() > 10) {
		vector<Client*> gr = group;
		gr.erase(gr.begin() + 10, gr.end());
		group.erase(group.begin(), group.begin() + 10);
		van.addGroup(gr);
		vans.push(van);
		this->addGroup(group);
	}
	else
		do {
			vanVec.push_back(vans.top());
			vans.pop();
			i++;

			if (vans.empty())
				vans.push(van);
		} while (vanVec[i - 1].getVacancies() < gr);

		vanVec[i - 1].addGroup(group);

		for (int j = 0; j < vanVec.size(); j++) {
			vans.push(vanVec[j]);
		}
		cout << "Group added to van " << vanVec[i - 1].getId();
}

priority_queue<Van> Hotel::getVans() const {
	return vans;
}

unsigned Hotel::getTrips() const {
	return trips;
}

void Hotel::tripDone(int id) {
	this->removeVan(id);
	this->trips++;
}

void Hotel::removeVan(int id) {
	int total = (int) vans.size();
	vector<Van> van;
	do {
		van.push_back(vans.top());
		vans.pop();
	} while (!vans.empty());

	vector<Van>::iterator it;
	for (it = van.begin(); it != van.end(); it++) {
		if (it->getId() == id) {
			van.erase(it);

			for (unsigned i = 0; i < van.size(); i++) {
				vans.push(van[i]);
			}
			return;
		}
	}
	for (unsigned i = 0; i < van.size(); i++) {
		vans.push(van[i]);
	}
	throw (NonExistingVan(id));
}

void Hotel::showVans() {
	vector<Van> van;
	if (vans.size() == 0)
		cout << "There are no vans available";
	else {
		do {
			cout << vans.top().getInfo() << endl;
			van.push_back(vans.top());
			vans.pop();
		} while (!vans.empty());

		for (unsigned i = 0; i < van.size(); i++) {
			vans.push(van[i]);
		}
	}
}

void Hotel::addVan(Van V) {
	this->vans.push(V);
}

void Hotel::importVans(string filename) {
	vector<Client*>cli;
	string line, name;
	ifstream file;
	int id, noOnBoard;
	Van v = Van();
	file.open(filename);
	if (file.is_open())
	{
		while (getline(file, line))
		{
			id = atoi(line.c_str());
			v.setId(id);
			getline(file, line);
			noOnBoard = atoi(line.c_str());
			for (int i = 0; i < noOnBoard; i++) {
				getline(file, line);
				name = line;
				cli.push_back(this->getClients()[sequencialSearchClients(name)]);
				v.addGroup(cli);
			}
			this->vans.push(v);
		}
		file.close();
	}

	else cout << "Unable to open file" << endl;
}

//... Events
priority_queue<Event> Hotel::getEvents() const {
	return this->events;
}

void Hotel::addEvent(Event Ev) {
	this->events.push(Ev);
}

void Hotel::removeEvent() {
	this->events.pop();
}

string Hotel::getEventsInfo() {
	stack<Event> tempEvents;
	stringstream ss;
	int numberOfEvents = (int) events.size();

	// Getting every event's information
	for (int i = 1; i <= numberOfEvents; i++) {
		ss << i << ": " << endl << events.top().getInfo() << endl;
		tempEvents.push(events.top());
		events.pop();
	}
	// Returning them to the queue
	for (int i = 0; i < numberOfEvents; i++) {
		events.push(tempEvents.top());
		tempEvents.pop();
	}

	return ss.str();
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


//... Restaurants

int Hotel::addRestaurant(Restaurant r) {
	Restaurant res = restaurants.find(r);
	Restaurant resNotFound("", "", 0);
	if (res == resNotFound) {
		this->restaurants.insert(r);
		return 1;
	}
	else return 0;
}

int Hotel::addRestaurant(string name, string type, int distance) {
	Restaurant r = Restaurant(name, type, distance);
	Restaurant res = restaurants.find(r);
	Restaurant resNotFound("", "", 0);
	if (res == resNotFound) {
		this->restaurants.insert(r);
		return 1;
	}
	else return 0;
}

vector<Restaurant> Hotel::addRestaurants(vector<Restaurant> res) {
	vector<Restaurant> nAddedRestaurants;
	for (size_t i = 0; i < res.size(); i++) {
		if (addRestaurant(res.at(i)) == 0) nAddedRestaurants.push_back((res.at(i)));
	}
	return nAddedRestaurants;
}

Restaurant Hotel::searchRestaurant(string name) {
	BSTItrIn<Restaurant> it(restaurants);
	while (!it.isAtEnd()) {
		if (it.retrieve().getName() == name) return it.retrieve();
		it.advance();
	}
	throw(NonExistingRestaurant(name));
}

BST<Restaurant> Hotel::getRestaurants() {
	return this->restaurants;
}

void Hotel::removeRestaurant(string name) {
	BSTItrIn<Restaurant> it(restaurants);
	while (!it.isAtEnd()) {
		if (it.retrieve().getName() == name) {
			this->restaurants.remove(it.retrieve());
		}
		it.advance();
	}
	throw(NonExistingRestaurant(name));
}

Restaurant Hotel::getClosestRestaurant() {
	BSTItrIn<Restaurant> it(restaurants);
	Restaurant r = it.retrieve();
	int minDistance = it.retrieve().getDistance();
	it.advance();

	while (!it.isAtEnd()) {
		if (it.retrieve().getDistance() < minDistance) {
			minDistance = it.retrieve().getDistance();
			r = it.retrieve();
			it.advance();
		}
		else it.advance();
	}
	return r;
}

vector<Restaurant> Hotel::getRestaurantsOfType(string type) {
	vector<Restaurant> res;
	BSTItrIn<Restaurant> it(restaurants);
	while (!it.isAtEnd()) {
		if (it.retrieve().getType() == type) {
			res.push_back(it.retrieve());
			it.advance();
		}
		else it.advance();
	}
	return res;
}

//needs testing
void Hotel::importRestaurants(string filename) {
	vector<Restaurant*> res;
	string line, name, type;
	ifstream file;
	int distance;
	Restaurant r = Restaurant("","",0);
	file.open(filename);
	if (file.is_open())
	{
		while (getline(file, line))
		{
			name = line;
			r.setName(name);
			getline(file, line);
			type = line;
			r.setType(type);
			getline(file, line);
			distance = atoi(line.c_str());
			r.setDistance(distance);
			addRestaurant(r);
		}
		file.close();
	}

	else cout << "Unable to open file" << endl;
}


int Hotel::getNoRestaurants() {
	int counter = 0;
	BSTItrIn<Restaurant> it(restaurants);
	while (!it.isAtEnd()) {
		counter++;
		it.advance();
	}
	return counter;
}

string Hotel::getRestaurantsInfo() {
	if (getNoRestaurants() != 0) {
		BSTItrIn<Restaurant> it(restaurants);
		stringstream ss;
		while (!it.isAtEnd()) {
			ss << it.retrieve().getInfo() << "\n";
			it.advance();
		}
		return ss.str();
	}
	else return "No Restaurants available! Press enter...";
	cin.get();
}

string Hotel::getTypesOfRestaurants() {
	stringstream ss;
	vector<string> types;
	BSTItrIn<Restaurant> it(restaurants);
	while (!it.isAtEnd()) {
		types.push_back(it.retrieve().getType());
		it.advance();
	}
	unique(types.begin(), types.end());
	
	for (size_t i = 0; i < types.size(); i++) {
		ss << "\t-" << types[i] << "\n";
	}

	if (types.size() == 0)  ss << "No restaurants available\n";

	return ss.str();
}
