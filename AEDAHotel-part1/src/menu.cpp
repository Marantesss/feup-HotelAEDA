#include "menu.h"

int menu() {
	int menuOption;

	do {
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
		cin >> menuOption;
		if (menuOption < 0 || menuOption > 5) {
			cout << "ERROR: Not a valid Operation! Please try again..." << endl;
		}
	} while (menuOption < 0 || menuOption > 5);

	return menuOption;
}

int hotelInformationMenu(Hotel *h) {
	int menuOption, floorOperation;
	string newAddress;

	do {
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
		cout << " 0 - Back" << endl;
		cout << "Option: ";
		cin >> menuOption;
		switch (menuOption) {
		case 0:
			break;
		case 1:
			cout << "Enter new address: ";
			cin.clear();
			cin.ignore(1000, '\n');
			getline(cin, newAddress);
			h->setAddress(newAddress);
			cout << "Address updated!" << endl << endl;
			break;
		case 2:
			h->addFloor();
			cout << "Floor added!" << endl;
			break;
		case 3:
			cout << "_____________________________________" << endl;
			cout << h->getRoomsInfo() << endl; // Prints all rooms
			cout << "WAre you sure you want to remove floor " << h->getFloors() << " ?" << endl;
			cout << "This action will remove all existing reservations and rooms in the floor." << endl;
			cout << "_____________________________________" << endl;
			cout << "Enter 1 to remove top floor or 0 to go back: ";
			cin >> floorOperation;
			if (floorOperation < 0 || floorOperation > h->getFloors()) {
				cout << "ERROR: Not a valid Floor/Operation! Please try again..." << endl;
			}
			else if (floorOperation > 0 || floorOperation <= h->getFloors()) {
				h->removeRoomsFromTopFloor();
				h->removeFloor();
				cout << "Top floor removed!" << endl;
			}
			break;
		}
		if (menuOption < 0 || menuOption > 3) {
			cout << "ERROR: Not a valid Operation! Please try again..." << endl;
		}
	} while (menuOption != 0);

	return menuOption;
}

int clientMenu(Hotel *h) {
	int menuOption;
	string name, filename;
	Client c = Client();
	do {
		cout << "_____________________________________" << endl;
		cout << " ----------- CLIENT MENU ----------- " << endl;
		cout << "Clients - " << h->getClients().size() << endl;
		cout << "\nWhat would you like to do?" << endl;
		cout << "Add Client - 1 " << endl;
		cout << "Remove Client - 2 " << endl;
		cout << "Search Client by name- 3 " << endl;
		cout << "Import Clients/Reservations - 4" << endl;
		cout << "Back - 0 " << endl;
		cout << "\nOption: ";
		cin >> menuOption;
		cout << endl;
		switch (menuOption) {
		case 0:
			break;
		case 1:
			cout << "Name - ";
			cin >> name;
			c.setName(name);
			h->addClient(c);
			break;
		case 2:
			cout << "Name - ";
			cin >> name;
			
			if (h->getClients().empty()) {
				cout << "The hotel has no Clients yet" << endl;
				break;
			}
			else {
				int i = h->sequencialSearchClients(name);
				if (i == -1) {
					cout << "Error - Client with the name " << name << " not found!" << endl;
					break;
				}
				h->getClients().erase(h->getClients().begin() + i);
			}
			break;
		case 3:
			cout << "Name - ";
			cin >> name;

			if (h->getClients().empty()) {
				cout << "The hotel has no Clients yet" << endl;
				break;
			}
			else {
				int i = h->sequencialSearchClients(name);
				if (i == -1) {
					cout << "Error - Client with the name " << name << " not found!" << endl;
					break;
				}
				h->getClients().at(i).getInfo();
			}
			break;
		case 4:
			cout << "File name - ";
			cin >> filename;
			h->importClientsandReservations(filename);
			break;
		case 5:

			break;
		default:
			break;
		}
	} while (menuOption != 0);

	return menuOption;
}

int roomsMenu(Hotel *h) {
	int menuOption, num, capacity,i;
	string location, filename;
	char type, tmp;
	bool audio, video;
	Bedroom b = Bedroom();
	MeetingRoom m = MeetingRoom();

	do {
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
		cout << "0 - Back" << endl;
		cout << "\nOption: ";
		cin >> menuOption;
		cout << endl;
		switch (menuOption) {
		case 0:
			break;
		case 1:
			cout << "Number - ";
			cin >> num;

			cout << "Meeting Room or Bedroom (m/b) - ";
			cin >> type;
			if (type == 'm') {
				m.setNumber(num);
				cout << "Capacity (10/25/50) - ";
				cin >> capacity;
				m.setCapacity(capacity);
				cout << "Audio (y/n) - ";
				cin >> tmp;
				if (tmp == 'y') audio = true; else audio = false;
				m.setAudio(audio);
				cout << "Video (y/n) - ";
				cin >> tmp;
				if (tmp == 'y') video = true; else video = false;
				m.setVideo(video);
				m.setDefaultPrice();
				h->addRoom(m);
			}
			else if (type == 'b') {
				b.setNumber(num);
				cout << "Capacity (1/2) - ";
				cin >> capacity;
				b.setCapacity(capacity);
				cout << "Location (front/back) - ";
				cin >> location;
				b.setLocation(location);
				b.setDefaultPrice();
				h->addRoom(b);
			}
			break;
		case 2:
			cout << "Room number - ";
			cin >> num;
			i = h->sequencialSearchRooms(num);
			if (i == -1) {
				cout << "Error - Room number " << num << " not found!" << endl;
				break;
			}
			h->removeRoom(i);
			break;
		case 3:
			h->showRooms();
			break;
		case 4:
			h->allocateEmployees();
			break;
		case 5:
			cout << "Room number - ";
			cin >> num;
			i = h->sequencialSearchRooms(num);
			if (i == -1) {
				cout << "Error - Room number " << num << " not found!" << endl;
				break;
			}
			cout << h->getRooms().at(i).getInfo() << endl;
			break;
		case 6:
			cout << "File name - ";
			cin >> filename;
			h->importClientsandReservations(filename);
			break;
		default:
			cout << "ERROR: Not a valid Operation! Please try again..." << endl;
		}
	} while (menuOption != 0);

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
		cout << "5 - Search Employee by name" << endl;
		cout << "6 - Import Employees" << endl;
		cout << "0 - Back" << endl;
		cout << "\nOption: ";
		cin >> menuOption;
		cout << endl;
		switch (menuOption) {
		case 0:
			break;
		case 1:
			cout << "ID - ";
			cin >> id;
			e.setId(id);
			cout << "Name - ";
			cin >> name;
			e.setName(name);
			cout << "Supervisor (y/n) - ";
			cin >> supervisor;
			if (supervisor == 'y') {
				e.setIsSupervisor(true);
			}
			else e.setIsSupervisor(false);
			h->addEmployee(e);
			break;
		case 2:
			cout << "ID - ";
			cin >> id;
			h->removeEmployee(id);
			break;
		case 3:
			h->showEmployees();
			break;
		case 4:
			cout << "ID - ";
			cin >> id;
			i = h->sequencialSearchEmployees(id);
			if (i == -1) {
				cout << "Error - Employee with the id " << id << " not found!" << endl;
			}
			else {
				cout << h->getEmployees().at(i).getInfo() << endl;
			}
			break;
		case 5:
			cout << "Name - ";
			cin >> name;
			i = h->sequencialSearchEmployees(id);
			if (i == -1) {
				cout << "Error - Employee with the name " << name << " not found!" << endl;
			}
			else {
				cout << h->getEmployees().at(i).getInfo() << endl;
			}
			break;
		case 6:
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
