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
	string name;
	Client c = Client();
	do {
		cout << "_____________________________________" << endl;
		cout << " ----------- CLIENT MENU ----------- " << endl;
		cout << "Clients - " << h->getClients().size() << endl;
		cout << "\nWhat would you like to do?" << endl;
		cout << "Add Client - 1 " << endl;
		cout << "Remove Client - 2 " << endl;
		cout << "Search Client - 3 " << endl;
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
			/*cout << "Name - ";
			cin >> name;
			
			if (h->getClients().empty()) {
				cout << "The hotel has no Clients yet" << endl;
				break;
			}
			else {
				int i;
				if (i = sequencialSearch(h->getClients(), name) == -1) {
					cout << "Error - Client with the name " << name << " not found!" << endl;
					break;
				}
				h->getClients().erase(h->getClients().begin() + i);
			}*/
			break;
		case 3:

			break;
		}
		if (menuOption < 0 || menuOption > 1) {
			cout << "ERROR: Not a valid Operation! Please try again..." << endl;
		}
	} while (menuOption != 0);

	return menuOption;
}

int employeesMenu(Hotel *h) {
	int menuOption, id, i;
	string name, SclientOpt;
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
			if (i = sequencialSearch(h->getEmployees(), id) == -1) {
				cout << "Error - Employee with the id " << id << " not found!" << endl;
			}
			else {
				cout << h->getEmployees().at(i).getInfo() << endl;
			}
			break;
		case 5:
			cout << "Name - ";
			cin >> name;
			int i;
			if (i = sequencialSearch(h->getEmployees(), name) == -1) {
				cout << "Error - Employee with the name " << name << " not found!" << endl;
			}
			else {
				cout << h->getEmployees().at(i).getInfo() << endl;
			}
			break;
		default:
			cout << "ERROR: Not a valid Operation! Please try again..." << endl;
		}
	} while (menuOption != 0);

	return menuOption;
}
