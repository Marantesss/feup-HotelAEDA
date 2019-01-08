#include "menu.h"

void clearBuffer() {
	cin.clear();
	cin.ignore(1000, '\n');
}

void sendHappyBirthayEmail(Date date, Hotel* h) {
	vector<Client*> clients = h->checkBirthdays(date);

	if (clients.size() != 0) {
		cout << "Birthdays: ";
		for (size_t i = 0; i < clients.size(); i++) {
			if (i + 1 == clients.size())
				cout << clients[i]->getName() << endl;
			else
				cout << clients[i]->getName() << ", ";
		}
		writeHappyBirthdayEmail(clients, h);
	}
	else
		cout << "No birthday's today!" << endl;
}

void writeHappyBirthdayEmail(vector<Client*> clients, Hotel* h) {
	cout << " ____________________________________ " << endl;
	cout << " ---------- Email content ---------- " << endl;

	cout << "To: ";
	for (size_t i = 0; i < clients.size(); i++) {
		if (i + 1 == clients.size())
			cout << clients[i]->getName() << endl;
		else
			cout << clients[i]->getName() << ", ";
	}

	cout << "From: AEDA Hotel Management" << endl;
	cout << "Happy birthday esteemed client" << endl;
	cout << "As a present for choosing us to spend quality time we invite you to our future events" << endl;
	cout << endl << h->getEventsInfo();
	cout << "Please feel free to visit us again!" << endl;
	cout << "Hotel AEDA Management" << endl;
	cout << " ____________________________________ " << endl;
}

/********** Hotel Information **********/

int menu(Date *date) {
	int menuOption;

	cout << date->getExtendedDate() << endl;

	do {
		menuOption = showMenu();
		if (menuOption < 0 || menuOption > 8) {
			cout << "ERROR: Not a valid Operation! Please try again..." << endl;
		}
	} while (menuOption < 0 || menuOption > 8);

	return menuOption;
}

int showMenu() {
	int menuOption;

	cout << " ____________________________________ " << endl;
	cout << "| --- What would you like to do? --- |" << endl;
	cout << "| 1 - Hotel Information              |" << endl;
	cout << "| 2 - Clients                        |" << endl;
	cout << "| 3 - Reservations                   |" << endl;
	cout << "| 4 - Rooms                          |" << endl;
	cout << "| 5 - Employees                      |" << endl;
	cout << "| 6 - Excursions                     |" << endl;
	cout << "| 7 - Events                         |" << endl;
	cout << "| 8 - Next Day                       |" << endl;
	cout << "| 0 - Exit                           |" << endl;
	cout << "|____________________________________|" << endl;
	cout << "Option: ";
	cin >> menuOption;
	clearBuffer();

	return menuOption;
}

void hotelInformationMenu(Hotel *h) {
	int menuOption;

	do {
		menuOption = showHotelInformationOptions(h);
		switch (menuOption) {
		case 0:
			break;
		case 1:
			changeHotelAddress(h);
			break;
		case 2:
			h->addFloor();
			cout << "Floor added!" << endl;
			break;
		case 3:
			removeHotelTopFloor(h);
			break;
		default:
			cout << "ERROR: Not a valid Operation! Please try again..." << endl;
		}
	} while (menuOption != 0);
}

int showHotelInformationOptions(Hotel *h) {
	int menuOption;

	cout << "_____________________________________" << endl;
	cout << " -------- HOTEL INFORMATION -------- " << endl;
	cout << "Address: " << h->getAddress() << endl;
	cout << "Total Rooms: " << h->getBedrooms() + h->getMeetingRooms() << endl;
	cout << "Bedrooms: " << h->getBedrooms() << ", ";
	cout << "Meeting Rooms: " << h->getMeetingRooms() << endl;
	cout << "Total Clients: " << h->getClientsCheckedIn().size() << endl;
	cout << "Total Employees: " << h->getEmployees().size() << endl;
	cout << "_____________________________________" << endl;
	cout << " ---- What would you like to do? ---- " << endl;
	cout << " 1 - Change address" << endl;
	cout << " 2 - Add floor" << endl;
	cout << " 3 - Remove top floor" << endl;
	cout << " 0 - Back" << endl << endl;
	cout << "Option: ";
	cin >> menuOption;

	return menuOption;
}

void changeHotelAddress(Hotel *h) {
	string newAddress;

	clearBuffer();
	cout << "Enter new address: ";
	getline(cin, newAddress);
	h->setAddress(newAddress);
	cout << "Address updated!" << endl << endl;
}

void removeHotelTopFloor(Hotel *h) {
	int floorOperation;

	if (h->getFloors() == 0) {
		cout << "ERROR: No floors to remove" << endl;
	}
	else {
		cout << "_____________________________________" << endl;
		cout << h->getRoomsInfo() << endl;
		cout << "Are you sure you want to remove floor " << h->getFloors() << " ?" << endl;
		cout << "This action will remove all existing reservations and rooms in the floor." << endl;
		cout << "_____________________________________" << endl;
		cout << "Enter 1 to remove top floor or 0 to go back: ";
		clearBuffer();
		cin >> floorOperation;

		if (floorOperation == 1) {
			h->removeFloorReservations(h->getFloors());
			h->removeRoomsFromTopFloor();
			h->removeFloor();
			cout << "Top floor removed!" << endl;
		}
	}
}


/********** Client Information **********/

void clientMenu(Hotel *h) {
	int menuOption;

	do {
		menuOption = showClientOptions(h);
		switch (menuOption) {
		case 0:
			break;
		case 1:
			addNewClient(h);
			break;
		case 2:
			checkInOldClient(h);
			break;
		case 3:
			checkoutClient(h);
			break;
		case 4:
			h->showClientsCheckedIn();
			break;
		case 5:
			h->showClientRecords();
			break;
		case 6:
			searchClient(h);
			break;
		case 7:
			importClient(h);
			break;
		default:
			cout << "ERROR: Not a valid Operation! Please try again..." << endl;
		}
	} while (menuOption != 0);
}

int showClientOptions(Hotel *h) {
	int menuOption;

	cout << "_____________________________________" << endl;
	cout << " ----------- CLIENT MENU ----------- " << endl;
	cout << "Clients Checked-In - " << h->getClientsCheckedIn().size() << endl;
	cout << "Clients - " << h->getClientRecords().size() << endl;
	cout << "_____________________________________" << endl;
	cout << "What would you like to do?" << endl;
	cout << "1 - Add and check-in new client" << endl;
	cout << "2 - Check-in old client" << endl;
	cout << "3 - Check-out client" << endl;
	cout << "4 - See checked-in clients" << endl;
	cout << "5 - See client records" << endl;
	cout << "6 - Search client by name" << endl;
	cout << "7 - Import clients/Reservations [NOT IMPLEMENTED]" << endl;
	cout << "0 - Back" << endl << endl;
	cout << "Option: ";
	cin >> menuOption;

	return menuOption;
}

void addNewClient(Hotel *h) {
	string name;
	int day, month, year;
	Date *birthday = new Date;

	clearBuffer();
	cout << "Name: ";
	getline(cin, name);
	cout << "Enter date(day month year): ";
	cin >> day >> month >> year;

	try {
		*birthday = Date(day, month, year);
	}
	catch (InvalidDate & date) {
		cout << "ERROR: Date " << date.getDay() << "/" << date.getMonth() << "/" << date.getYear() << " is invalid!" << endl;
		return;
	}

	Client *c = new Client(name, *birthday);
	h->checkInClient(c);
	h->addClientRecord(c);
	cout << "Client " << c->getName() << " added successfully!" << endl;
}

void checkInOldClient(Hotel *h) {
	int id;

	clearBuffer();
	cout << "ID: ";
	cin >> id;

	Client c = Client();
	c.setId(id);

	try {
		Client* client = h->getClientRecord(&c);
		h->checkInClient(client);
		cout << "Client " << client->getName() << " checked-in!" << endl;
	}
	catch (NonExistingClient & nonClient) {
		cout << "ERROR: Client " << nonClient.getId() << " does not exist!!!" << endl;
	}
}

void checkoutClient(Hotel *h) {
	string name;

	clearBuffer();
	cout << "Name: ";
	getline(cin, name);

	try {
		int ClientIndex = h->sequencialSearchClients(name);
		cout << "Client found!" << endl;
		vector<Reservation*> clientsReservations = h->getClientsCheckedIn()[ClientIndex]->getReservations();

		cout << name << "'s reservations checked out successfully!" << endl;
		h->checkoutClient(name);
		cout << "Client " << name << " checked out successfully!" << endl;
	}
	catch (NonExistingClient & nonClient) {
		cout << "ERROR: Client " << nonClient.getName() << " does not exist!!!" << endl;
	}
}

void searchClient(Hotel *h) {
	string name;

	clearBuffer();
	cout << "Name: ";
	getline(cin, name);

	try {
		Client* client = h->getClientRecord(name);
		h->checkInClient(client);
		cout << "Client " << client->getInfo() << endl;
	}
	catch (NonExistingClient & nonClient) {
		cout << "ERROR: Client " << nonClient.getName() << " does not exist!!!" << endl;
	}
}

void importClient(Hotel *h) {
	string filename;

	clearBuffer();
	cout << "File name: ";
	cin >> filename;
	h->importClientsandReservations(filename);
}



/********** Room Information **********/

void roomsMenu(Hotel *h) {
	int menuOption;

	do {
		menuOption = showRoomsOptions(h);
		switch (menuOption) {
		case 0: // Go back
			break;
		case 1:
			addRoom(h);
			break;
		case 2:
			removeRoom(h);
			break;
		case 3:
			cout << h->getRoomsInfo() << endl;
			break;
		case 4:
			h->allocateEmployees();
			break;
		case 5:
			searchRoom(h);
			break;
		case 6:
			importRoom(h);
			break;
		default:
			cout << "ERROR: Not a valid Operation! Please try again..." << endl;
		}
	} while (menuOption != 0);
}

int showRoomsOptions(Hotel *h) {
	int menuOption;

	cout << endl << endl << endl;
	cout << "_____________________________________" << endl;
	cout << "------------- ROOM MENU -------------" << endl;
	cout << "No. of Rooms: " << h->getRooms().size() << endl;
	cout << "No. of Meeting Rooms: " << h->getMeetingRooms() << endl;
	cout << "No. of bedrooms: " << h->getBedrooms() << endl;
	cout << "_____________________________________" << endl;
	cout << " ---- What would you like to do? ---- " << endl;
	cout << "1 - Add Room" << endl;
	cout << "2 - Remove Room" << endl;
	cout << "3 - See Rooms" << endl;
	cout << "4 - Distribute supervisors"<< endl;
	cout << "5 - Search Room by number" << endl;
	cout << "6 - Import Rooms [NOT IMPLEMENTED YET]" << endl;
	cout << "0 - Back" << endl << endl;
	cout << "Option: ";
	cin >> menuOption;

	return menuOption;
}

void addRoom(Hotel *h) {
	char type;

	do {
		clearBuffer();
		cout << "Meeting Room or Bedroom (m/b): ";
		cin >> type;
		if (type != 'm' && type != 'b')
			cout << "Invalid room type, please try again..." << endl;
	} while (type != 'm' && type != 'b');

	if (type == 'm') {
		addMeetingRoom(h);
	}
	else if (type == 'b') {
		addBedroom(h);
	}
}

void addMeetingRoom(Hotel *h) {
	int num, capacity;
	char tmp;
	bool audio = false, video = false;

	clearBuffer();
	cout << "Number: ";
	cin >> num;

	do {
		clearBuffer();
		cout << "Capacity (10/25/50): ";
		cin >> capacity;

		if (capacity != 10 && capacity != 25 && capacity != 50)
			cout << "Invalid Capacity, please enter another capacity..." << endl;

	} while (capacity != 10 && capacity != 25 && capacity != 50);

	clearBuffer();
	cout << "Video (y/n): ";
	cin >> tmp;

	if (tmp == 'y') video = true;

	clearBuffer();
	cout << "Audio (y/n): ";
	cin >> tmp;

	if (tmp == 'y') audio = true;

	MeetingRoom *m = new MeetingRoom(num, capacity, video, audio);

	try {
		h->addRoom(m);
	}
	catch (NonExistingRoom & invalidRoom) {
		cout << "ERROR: Room " << invalidRoom.getNumber() << " already exists!" << endl;
	}
}

void addBedroom(Hotel *h) {
	int num, capacity;
	string location;

	clearBuffer();
	cout << "Number: ";
	cin >> num;

	do {
		clearBuffer();
		cout << "Capacity (1/2): ";
		cin >> capacity;

		if (capacity != 1 || capacity != 2)
			cout << "Invalid Capacity, please enter another capacity..." << endl;

	} while (capacity != 1 || capacity != 2);

	do {
		clearBuffer();
		cout << "Location (Front/Back): ";
		cin >> location;

		if (location != "Front" || location != "Back")
			cout << "Invalid location, make sure first letter is in caps..." << endl;

	} while (location != "Front" || location != "Back");

	Bedroom *b = new Bedroom(num, capacity, location);

	try {
		h->addRoom(b);
	}
	catch (NonExistingRoom & invalidRoom) {
		cout << "ERROR: Room " << invalidRoom.getNumber() << " already exists!" << endl;
	}
}

void removeRoom(Hotel *h) {
	int num;

	clearBuffer();
	cout << "Room number: ";
	cin >> num;

	try {
		h->removeRoom(num);
		cout << "Room " << num << " removed successfully!" << endl;
	}
	catch (NonExistingRoom & nonRoom) {
		cout << "ERROR: Room " << nonRoom.getNumber() << " does not exist!!!" << endl;
	}
}

void searchRoom(Hotel *h) {
	int num;

	clearBuffer();
	cout << "Room number: ";
	cin >> num;

	try {
		int i = h->sequencialSearchRooms(num);
		cout << "Room found!" << endl;
		cout << h->getRooms()[i]->getInfo() << endl;
	}
	catch (NonExistingRoom & nonRoom) {
		cout << "ERROR: Room " << nonRoom.getNumber() << " does not exist!!!" << endl;
	}
}

void importRoom(Hotel *h) {
	string filename;

	clearBuffer();
	cout << "File name: ";
	cin >> filename;
	h->importClientsandReservations(filename);
}



/********** Reservation Information **********/

void reservationMenu(Hotel *h) {
	int menuOption;

	do {
		menuOption = showReservationOptions(h);
		switch (menuOption) {
		case 0:
			break;
		case 1:
			addReservation(h);
			break;
		case 2:
			removeReservation(h);
			break;
		case 3:
			h->showReservations();
			break;
		default:
			cout << "ERROR: Not a valid Operation! Please try again..." << endl;
		}
	} while (menuOption != 0);
}

int showReservationOptions(Hotel *h) {
	int menuOption;

	cout << endl << endl << endl;
	cout << "_____________________________________" << endl;
	cout << "--------- RESERVATION MENU ----------" << endl;
	cout << "No. of Reservations: " << h->getReservations().size()  << endl;
	cout << "_____________________________________" << endl;
	cout << " ---- What would you like to do? ---- " << endl;
	cout << "1 - Add Reservation" << endl;
	cout << "2 - Remove Reservation" << endl;
	cout << "3 - See Reservations" << endl;
	cout << "0 - Back" << endl << endl;
	cout << "Option: ";
	cin >> menuOption;

	return menuOption;
}

void addReservation(Hotel *h) {
	int day, month, year, roomNumber, roomIndex, duration, clientIndex;
	Room* roomPointer;
	Date* date = new Date();
	string name;

	// reading the client
	clearBuffer();
	cout << "Client name: ";
	getline(cin, name);

	try {
		clientIndex = h->sequencialSearchClients(name);
		cout << "Client found!" << endl;
		cout << h->getClientsCheckedIn()[clientIndex]->getInfo() << endl;
	}
	catch (NonExistingClient & nonClient) {
		cout << "ERROR: Client " << nonClient.getName() << " does not exist!!!" << endl;
		return;
	}

	// creating the reservation
	cout << "Enter date(day month year): ";
	cin >> day >> month >> year;

	try {
		*date = Date(day, month, year);
	}
	catch (InvalidDate & date) {
		cout << "ERROR: Date " << date.getDay() << "/" << date.getMonth() << "/" << date.getYear() << " is invalid!" << endl;
		return;
	}



	clearBuffer();
	cout << "Room number: ";
	cin >> roomNumber;

	try {
		roomIndex = h->sequencialSearchRooms(roomNumber);
		roomPointer = h->getRooms()[roomIndex];
		cout << roomPointer->getInfo() << endl;
	}
	catch (NonExistingRoom & nonRoom) {
		cout << "ERROR: Room " << nonRoom.getNumber() << " does not exist!!!" << endl;
		return;
	}

	clearBuffer();
	cout << "Duration: ";
	cin >> duration;
	Reservation *r = new Reservation(*date, roomPointer, duration);

	try {
		h->addReservation(*r);
		Client *c = h->getClientsCheckedIn()[clientIndex];
		c->addReservation(r);
		cout << "Reservation added successfully!" << endl;
	}
	catch (NonExistingReservation & nonReservation) {
		cout << "ERROR: Reservation already exists or is incompatible with others!!!" << endl;
	}
}

void removeReservation(Hotel *h) {
	int day, month, year, roomNumber, roomIndex;
	Room* roomPointer;
	Date* date = new Date();
	string name;

	// getting the date
	cout << "Enter date(day month year): ";
	cin >> day >> month >> year;

	try {
		*date = Date(day, month, year);
	}
	catch (InvalidDate & date) {
		cout << "ERROR: Date " << date.getDay() << "/" << date.getMonth() << "/" << date.getYear() << " is invalid!" << endl;
		return;
	}

	//getting the room
	clearBuffer();
	cout << "Room number: ";
	cin >> roomNumber;

	try {
		roomIndex = h->sequencialSearchRooms(roomNumber);
		roomPointer = h->getRooms()[roomIndex];
		cout << roomPointer->getInfo() << endl;
	}
	catch (NonExistingRoom & nonRoom) {
		cout << "ERROR: Room " << nonRoom.getNumber() << " does not exist!!!" << endl;
		return;
	}

	try {
		h->removeReservation(*date, roomPointer);
		cout << "Reservation removed successfully!" << endl;
		vector<Client*> tempClients = h->getClientsCheckedIn();

		for (size_t i = 0; i < tempClients.size(); i++) {
			try {
				tempClients[i]->removeReservation(*date, roomPointer);
				cout << tempClients[i]->getName() << "'s reservation removed successfully!" << endl;
			}
			catch (NonExistingReservation & nonReservation) {}
		}
	}
	catch (NonExistingReservation & nonReservation) {
		cout << "ERROR: Reservation does not exist!!!" << endl;
	}
}



/********** Employee Information **********/

void employeesMenu(Hotel *h) {
	int menuOption;

	do {
		menuOption = showEmployeeOptions(h);
		switch (menuOption) {
		case 0:
			break;
		case 1:
			addEmployee(h);
			break;
		case 2:
			removeEmployee(h);
			break;
		case 3:
			h->showEmployees();
			break;
		case 4:
			searchEmployee(h);
			break;
		case 5:
			importEmployee(h);
			break;
		default:
			cout << "ERROR: Not a valid Operation! Please try again..." << endl;
		}
	} while (menuOption != 0);
}

int showEmployeeOptions(Hotel *h) {
	int menuOption;

	cout << endl << endl << endl;
	cout << "_____________________________________" << endl;
	cout << "----------- EMPLOYEE MENU -----------" << endl;
	cout << "No. of Employees: " << h->getEmployees().size()  << endl;
	cout << "No. of Supervisors: " << h->getNoSupervisors() << endl;
	cout << "_____________________________________" << endl;
	cout << " ---- What would you like to do? ---- " << endl;
	cout << "1 - Add Employee" << endl;
	cout << "2 - Remove Employee" << endl;
	cout << "3 - See Employees" << endl;
	cout << "4 - Search Employee by ID" << endl;
	cout << "5 - Import Employees" << endl;
	cout << "0 - Back" << endl << endl;
	cout << "Option: ";
	cin >> menuOption;

	return menuOption;
}

void addEmployee(Hotel *h) {
	int id;
	string name;
	char supervisor;

	clearBuffer();
	cout << "ID: ";
	cin >> id;
	clearBuffer();
	cout << "Name: ";
	getline(cin, name);
	clearBuffer();
	cout << "Supervisor (y/n): ";
	cin >> supervisor;

	if (supervisor == 'y') {
		Employee *e = new Employee(name, true);

		try {
			h->addEmployee(*e);
		}
		catch (NonExistingEmployee & invalidEmployee) {
			cout << "ERROR: Employee " << invalidEmployee.getId() << " already exists!" << endl;
		}
	}
	else {
		Employee *e = new Employee(name, false);

		try {
			h->addEmployee(*e);
		}
		catch (NonExistingEmployee & invalidEmployee) {
			cout << "ERROR: Employee " << invalidEmployee.getId() << " already exists!" << endl;
		}
	}
}

void removeEmployee (Hotel *h) {
	int id;

	clearBuffer();
	cout << "ID: ";
	cin >> id;

	try {
		h->removeEmployee(id);
		cout << "Employee " << id << " removed successfully!" << endl;
	}
	catch (NonExistingEmployee & nonEmployee) {
		cout << "ERROR: Employee " << nonEmployee.getId() << " does not exist!!!" << endl;
	}
}

void searchEmployee(Hotel *h) {
	int id;

	clearBuffer();
	cout << "ID: ";
	cin >> id;

	try {
		int i = h->sequencialSearchEmployees(id);
		cout << h->getEmployees().at(i).getInfo() << endl;
	}
	catch (NonExistingEmployee & nonEmployee) {
		cout << "ERROR: Employee " << nonEmployee.getId() << " does not exist!!!" << endl;
	}
}

void importEmployee(Hotel *h) {
	string filename;

	clearBuffer();
	cout << "File name: ";
	cin >> filename;
	h->importEmployees(filename);
}

void vansMenu(Hotel * h){
	int menuOption;

	do {
		menuOption = showVanOptions(h);
		switch (menuOption) {
		case 0:
			break;
		case 1:
			addGroup(h);
			break;
		case 2:
			removeVan(h);
			break;
		case 3:
			h->showVans();
			break;
		case 4:
			searchVan(h);
			break;
		default:
			clearBuffer();
			cout << "ERROR: Not a valid Operation! Please try again..." << endl;
		}
	} while (menuOption != 0);
}

int showVanOptions(Hotel * h){
	int menuOption;
	cout << endl << endl << endl;
	cout << "______________________________________" << endl;
	cout << "----------- EXCURSION MENU -----------" << endl;
	cout << "No. of Vans in use: " << h->getVans().size() << endl;
	cout << "______________________________________" << endl;
	cout << " - What would you like to do? - " << endl;
	cout << "1 - Add a Group" << endl;
	cout << "2 - Remove Van" << endl;
	cout << "3 - See Vans" << endl;
	cout << "4 - Search Van by ID" << endl;
	cout << "5 - Finish a excursion" << endl; //to do......................
	cout << "0 - Back" << endl << endl;
	cout << "Option: ";
	cin >> menuOption;

	return menuOption;
}

void addGroup(Hotel * h){
	int clientIndex, size;
	Client* clientPointer;
	string name;
	vector<Client*> group;

	// reading the clients
	do {
		clearBuffer();
		cout << "What's the size of the group? ";
		cin >> size;
		if (cin.fail()) {
			cout << "The size of the group is suposed to be a number!!" << endl;
		}
	} while (cin.fail()); 
	
	for (int i = 0; i < size; i++) {
		cout << "Client name: ";
		getline(cin, name);

		try {
			clientIndex = h->sequencialSearchClients(name);
			cout << "Client found!" << endl;
			cout << h->getClientsCheckedIn()[clientIndex]->getInfo2() << endl;
			clientPointer = h->getClientsCheckedIn()[clientIndex];
			group.push_back(clientPointer);
		}
		catch (NonExistingClient & nonClient) {
			cout << "ERROR: Client " << nonClient.getName() << " does not exist!!!" << endl;
			return;
		}
	}
	h->addGroup(group);
}

void removeVan(Hotel * h){
	int id;

	if (h->getVans().size() == 0)
		cout << "There are no vans available";
	else {
		clearBuffer();
		cout << "ID: ";
		cin >> id;

		try {
			h->removeVan(id);
			cout << "Van " << id << " removed successfully!" << endl;
		}
		catch (NonExistingVan & nonVan) {
			cout << "ERROR: Van " << nonVan.getId() << " does not exist!!!" << endl;
		}
	}

}

void searchVan(Hotel * h){
	int id, i = 0;
	priority_queue<Van> vans=h->getVans();
	vector<Van> vanVec;
	bool wh = true;

	if (h->getVans().size() == 0)
		cout << "There are no vans available";
	else {
		do {
			clearBuffer();
			cout << "ID: ";
			cin >> id;

			if (cin.fail()) {
				cout << "The ID of the van is suposed to be a number!!" << endl << endl << endl;
			}
		} while (cin.fail());
		
		try {
			do {
				vanVec.push_back(vans.top());
				vans.pop();

				if (id == vanVec[i].getId()) {
					cout << vanVec[i].getInfo() << endl;
					wh = false;
				}

				i++;
			} while (!vans.empty() && wh);
		}
		catch (NonExistingVan & nonVan) {
			cout << "ERROR: Van " << nonVan.getId() << " does not exist!!!" << endl;
		}
	}
}

void importVan(Hotel * h){
	string filename;

	clearBuffer();
	cout << "File name: ";
	cin >> filename;
	h->importVans(filename);
}


/********** Employee Information **********/

void eventMenu(Hotel *h) {
	int menuOption;

	do {
		menuOption = showEventOptions(h);
		switch (menuOption) {
		case 0:
			break;
		case 1:
			addEvent(h);
			break;
		case 2:
			cout << h->getEventsInfo();
			break;
		default:
			cout << "ERROR: Not a valid Operation! Please try again..." << endl;
		}
	} while (menuOption != 0);
}

int showEventOptions(Hotel *h) {
	int menuOption;

	cout << "_____________________________________" << endl;
	cout << "------------ EVENT MENU ------------" << endl;
	cout << "No. of upcoming events: " << h->getEvents().size() << endl;
	cout << "_____________________________________" << endl;
	cout << " ---- What would you like to do? ---- " << endl;
	cout << "1 - Add Event" << endl;
	cout << "2 - See Events" << endl;
	cout << "0 - Back" << endl << endl;
	cout << "Option: ";
	cin >> menuOption;

	return menuOption;
}

void addEvent(Hotel *h) {
	string name, location, description;
	int day, month, year;
	Date *date = new Date();

	clearBuffer();
	cout << "Name: ";
	getline(cin, name);
	cout << "Enter date(day month year): ";
	cin >> day >> month >> year;

	try {
		*date = Date(day, month, year);
	}
	catch (InvalidDate & date) {
		cout << "ERROR: Date " << date.getDay() << "/" << date.getMonth() << "/" << date.getYear() << " is invalid!" << endl;
		return;
	}

	clearBuffer();
	cout << "Location: ";
	getline(cin, location);
	cout << "Description: ";
	getline(cin, description);
	Event *e = new Event(name, *date, location, description);
	h->addEvent(*e);
	cout << "Event added successfully!" << endl;
}
