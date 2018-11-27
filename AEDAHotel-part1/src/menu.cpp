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

int showHotelInformationMenu(Hotel *h) {
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
			searchClient(h);
			break;
		case 4:
			importClient(h);
			break;
		default:
			cout << "ERROR: Not a valid Operation! Please try again..." << endl;
		}
	} while (menuOption != 0);
}

int showClientMenu(Hotel *h) {
	int menuOption;

	cout << "_____________________________________" << endl;
	cout << " ----------- CLIENT MENU ----------- " << endl;
	cout << "Clients - " << h->getClients().size() << endl;
	cout << "_____________________________________" << endl;
	cout << "What would you like to do?" << endl;
	cout << "Add Client - 1 " << endl;
	cout << "Remove Client - 2 " << endl;
	cout << "Search Client by name - 3 " << endl;
	cout << "Import Clients/Reservations - 4" << endl;
	cout << "Back - 0 " << endl << endl;
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
		cout << h->clients[i].getInfo() << endl;
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

int roomsMenu(Hotel *h) {
	int menuOption, num, capacity,i;
	string location, filename;
	char type = 'm', tmp;
	bool audio, video;
	Bedroom b = Bedroom();
	MeetingRoom m = MeetingRoom();

	do {
		menuOption = showRoomsOptions(h);
		switch (menuOption) {
		case 0: // Go back
			break;
		case 1:	// Add Room
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Number - ";
			cin >> num;
			cin.clear();
			cin.ignore(1000, '\n');
			do {
				if (type != 'm' || type != 'b')
					cout << "Invalid room type, please try again..." << endl;
				cout << "Meeting Room or Bedroom (m/b) - ";
				cin.clear();
				cin.ignore(1000, '\n');
				cin >> type;
			} while (type != 'm' || type != 'b');
			if (type == 'm') {
				m.setNumber(num);
				do {
					if (capacity != 10 || capacity != 25 || capacity != 50)
						cout << "Invalid Capacity, please enter another capacity..." << endl;
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "Capacity (10/25/50) - ";
					cin >> capacity;
				} while (capacity != 10 || capacity != 25 || capacity != 50);
				m.setCapacity(capacity);
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Audio (y/n) - ";
				cin >> tmp;
				if (tmp == 'y') audio = true; else audio = false;
				m.setAudio(audio);
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Video (y/n) - ";
				cin >> tmp;
				if (tmp == 'y') video = true; else video = false;
				m.setVideo(video);
				m.setDefaultPrice();
				h->addRoom(m);
			}
			else if (type == 'b') {
				b.setNumber(num);
				do {
					if (capacity != 1 || capacity != 2)
						cout << "Invalid Capacity, please enter another capacity..." << endl;
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "Capacity (1/2) - ";
					cin >> capacity;
				} while (capacity != 1 || capacity != 2);
				b.setCapacity(capacity);
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Location (front/back) - ";
				cin >> location;
				b.setLocation(location);
				b.setDefaultPrice();
				h->addRoom(b);
			}
			break;
		case 2:	// Remove Room
			cout << "Room number: ";
			cin >> num;
			try {
				h->removeRoom(num);
				cout << "Room " << num << " removed succesfuly" << endl;
			}
			catch (NonExistingRoom & nonRoom) {
				cout << "ERROR: Room " << nonRoom.getNumber() << " does not exist!!!" << endl;
			}
			break;
		case 3: // Show Rooms
			h->showRooms();
			break;
		case 4: // Allocate Employees
			h->allocateEmployees();
			break;
		case 5: // Search Room
			cout << "Room number: ";
			cin >> num;
			i = h->sequencialSearchRooms(num);
			if (i == -1) {
				cout << "ERROR: Room " << num << " not found!" << endl;
				break;
			}
			cout << h->getRooms().at(i).getInfo() << endl;
			break;
		case 6:	// Import Rooms
			cout << "File name: ";
			cin >> filename;
			h->importClientsandReservations(filename);
			break;
		default:
			cout << "ERROR: Not a valid Operation! Please try again..." << endl;
		}
	} while (menuOption != 0);

	return menuOption;
}

int showRoomsMenu(Hotel *h) {
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

//Done
int employeesMenu(Hotel *h) {
	int menuOption, id, i;
	string name, SclientOpt, filename;
	Employee e = Employee();
	char supervisor;

	do {
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
		cin >> menuOption;
		cout << endl;
		switch (menuOption) {
		case 0:
			break;
		case 1:
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "ID - ";
			cin >> id;
			e.setId(id);
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Name - ";
			cin >> name;
			e.setName(name);
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Supervisor (y/n) - ";
			cin >> supervisor;
			if (supervisor == 'y') {
				e.setIsSupervisor(true);
			}
			else e.setIsSupervisor(false);
			h->addEmployee(e);
			break;
		case 2:
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "ID - ";
			cin >> id;
			try {
				h->removeEmployee(id);
			}
			catch (NonExistingEmployee & nonEmployee) {
				cout << "ERROR: Employee " << nonEmployee.getId() << " does not exist!!!" << endl;
			}
			break;
		case 3:
			h->showEmployees();
			break;
		case 4:
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "ID - ";
			cin >> id;
			i = h->sequencialSearchEmployees(id);
			if (i == -1) {
				cout << "ERROR: Employee " << id << " does not exist!!!" << endl;
			}
			else {
				cout << h->getEmployees().at(i).getInfo() << endl;
			}
			break;
		case 5:
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "File name - ";
			cin >> filename;
			h->importEmployees(filename);
			break;
		default:
			cout << "ERROR: Not a valid Operation! Please try again..." << endl;
		}
	} while (menuOption != 0);

	return menuOption;
}
