#include "menu.h"

void clearBuffer() {
	cin.clear();
	cin.ignore(1000, '\n');
}



/********** Hotel Information **********/

int menu() {
	int menuOption;

	do {
		menuOption = showMenu();
		if (menuOption < 0 || menuOption > 5) {
			cout << "ERROR: Not a valid Operation! Please try again..." << endl;
		}
	} while (menuOption < 0 || menuOption > 5);

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
	cout << "| 0 - Exit                           |" << endl;
	cout << "|____________________________________|" << endl;
	cout << "Option: ";
	clearBuffer();
	cin >> menuOption;

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
	cout << "Address - " << h->getAddress() << endl;
	cout << "Total Rooms: " << h->getBedrooms() + h->getMeetingRooms() << endl;
	cout << "Bedrooms: " << h->getBedrooms() << ", ";
	cout << "Meeting Rooms: " << h->getMeetingRooms() << endl;
	cout << "Total Clients: " << h->getClients().size() << endl;
	cout << "Total Employees: " << h->getEmployees().size() << endl;
	cout << "_____________________________________" << endl;
	cout << " ---- What would you like to do? ---- " << endl;
	cout << " 1 - Change address" << endl;
	cout << " 2 - Add floor" << endl;
	cout << " 3 - Remove top floor" << endl;
	cout << " 0 - Back" << endl << endl;
	cout << "Option: ";
	clearBuffer();
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
			addClient(h);
			break;
		case 2:
			removeClient(h);
			break;
		case 3:
			h->showClients();
			break;
		case 4:
			searchClient(h);
			break;
		case 5:
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
	cout << "Clients - " << h->getClients().size() << endl;
	cout << "_____________________________________" << endl;
	cout << "What would you like to do?" << endl;
	cout << "1 - Add Client" << endl;
	cout << "2 - Remove Client" << endl;
	cout << "3 - See Clients" << endl;
	cout << "4 - Search Client by name" << endl;
	cout << "5 - Import Clients/Reservations" << endl;
	cout << "0 - Back" << endl << endl;
	cout << "Option: ";
	clearBuffer();
	cin >> menuOption;

	return menuOption;
}

void addClient(Hotel *h) {
	string name;

	clearBuffer();
	cout << "Name: ";
	getline(cin, name);
	Client c(name);
	h->addClient(c);
}

void removeClient(Hotel *h) {
	string name;

	clearBuffer();
	cout << "Name: ";
	getline(cin, name);
	try {
		h->removeClient(name);
		cout << "Client " << name << " removed successfully!" << endl;
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
		int i = h->sequencialSearchClients(name);
		cout << "Client found!" << endl;
		cout << h->getClients()[i].getInfo() << endl;
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
			h->showRooms();
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

	cout << "_____________________________________" << endl;
	cout << "------------- ROOM MENU -------------" << endl;
	cout << "No. of Rooms: " << h->getRooms().size() << endl;
	cout << "No. of Meeting Rooms: " << h->getMeetingRooms() << endl;
	cout << "No. of bedrooms: " << h->getBedrooms() << endl;
	cout << "_____________________________________" << endl;
	cout << " ---- What would you like to do? ---- " << endl;
	cout << "1 - Add Room" << endl;
	cout << "2 - Remove Room" << endl;
	cout << "3 - See Rooms [NOT IMPLEMENTED YET]" << endl;
	cout << "4 - Distribute supervisors"<< endl;
	cout << "5 - Search Room by number" << endl;
	cout << "6 - Import Rooms [NOT IMPLEMENTED YET]" << endl;
	cout << "0 - Back" << endl << endl;
	cout << "Option: ";
	clearBuffer();
	cin >> menuOption;

	return menuOption;
}

void addRoom(Hotel *h) {
	char type;

	do {
		cout << "Meeting Room or Bedroom (m/b): ";
		clearBuffer();
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
	MeetingRoom m(num, capacity, video, audio);
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
			cout << "Invalid location, make sure first letter is caps..." << endl;
	} while (location != "Front" || location != "Back");
	Bedroom b(num, capacity, location);
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
		cout << h->getRooms()[i].getInfo() << endl;
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
	clearBuffer();
	cin >> menuOption;
	cout << endl;

	return menuOption;
}

void addReservation(Hotel *h) {
	int day, month, year, roomNumber, roomIndex, duration, clientIndex;
	Room* roomPointer;
	Date date;
	string name;

	// reading the client
	clearBuffer();
	cout << "Client name: ";
	getline(cin, name);
	try {
		clientIndex = h->sequencialSearchClients(name);
		cout << "Client found!" << endl;
		cout << h->getClients()[clientIndex].getInfo() << endl;
	}
	catch (NonExistingClient & nonClient) {
		cout << "ERROR: Client " << nonClient.getName() << " does not exist!!!" << endl;
		return;
	}

	// creating the reservation
	clearBuffer();
	cout << "Enter date(day month year): ";
	cin >> day >> month >> year;
	try {
		date = Date(day, month, year);
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
		roomPointer = &(h->getRooms()[roomIndex]);
	}
	catch (NonExistingRoom & nonRoom) {
		cout << "ERROR: Room " << nonRoom.getNumber() << " does not exist!!!" << endl;
		return;
	}
	clearBuffer();
	cout << "Duration: ";
	cin >> duration;
	Reservation r(date, roomPointer, duration);
	try {
		h->addReservation(r);
	}
	catch (NonExistingReservation & nonReservation) {
		cout << "ERROR: Reservation already exists or is incompatible with others!!!" << endl;
	}

	// adding reservation to clients record
	h->getClients()[clientIndex].addReservation(&r);
}

void removeReservation(Hotel *h) {
	// TODO
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
	cout << "0 - Back" << endl;
	cout << "\nOption: ";
	clearBuffer();
	cin >> menuOption;
	cout << endl;

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
		Employee e(id, name, true);
		try {
			h->addEmployee(e);
		}
		catch (NonExistingEmployee & invalidEmployee) {
			cout << "ERROR: Employee " << invalidEmployee.getId() << " already exists!" << endl;
		}
	}
	else {
		Employee e(id, name, false);
		try {
			h->addEmployee(e);
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
	cout << "File name - ";
	cin >> filename;
	h->importEmployees(filename);
}
