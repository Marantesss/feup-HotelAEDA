#include "menu.h"

int menu() {
	int menuOption;

	do {
		cout << "What would you like to do?" << endl;
		cout << "Hotel Information - 1" << endl;
		cout << "Clients - 2" << endl;
		cout << "Reservations - 3" << endl;
		cout << "Rooms - 4" << endl;
		cout << "Employees - 5" << endl;
		cout << "Exit - 0" << endl;
		cout << "\nOption: ";
		cin >> menuOption;
		cout << endl;
		if (menuOption < 0 || menuOption > 5) {
			cout << "ERROR: Not a valid Operation! Please try again..." << endl;
		}
	} while (menuOption < 0 || menuOption > 5);

	return menuOption;
}

int hotelInformationMenu(Hotel *h) {
	int menuOption;

	do {
		cout << "------ HOTEL INFORMATION ------" << endl;
		cout << "Hotel AEDA - " << h->getAddress() << endl;
		cout << "Total Rooms: " << h->getBedrooms() + h->getMeetingRooms() << ", ";
		cout << "Bedrooms: " << h->getBedrooms() << ", ";
		cout << "Meeting Rooms: " << h->getMeetingRooms() << endl;
		cout << "Clients: " << h->getClients().size() << endl;
		cout << "Employees: " << h->getEmployees().size() << endl << endl;

		cout << "What would you like to do?" << endl;
		cout << "Change Information - 1 " << endl;
		cout << "Back - 0 " << endl;
		cout << "\nOption: ";
		cin >> menuOption;
		cout << endl;
		switch (menuOption) {
		case 0:
			break;
		case 1:
			hotelChangeInformationMenu(h);
			break;
		}
		if (menuOption < 0 || menuOption > 1) {
			cout << "ERROR: Not a valid Operation! Please try again..." << endl;
		}
	} while (menuOption != 0);

	return menuOption;
}

int hotelChangeInformationMenu(Hotel *h) {
	int menuOption, floorOperation;
	string newAddress;

	do {
		cout << "------ CHANGE HOTEL INFORMATION ------" << endl;
		cout << "Change Address - 1" << endl;
		cout << "Add Floor - 2" << endl;
		cout << "Remove Floor - 3" << endl;
		cout << "Back - 0 " << endl;
		cout << "\nOption: ";
		cin >> menuOption;
		cout << endl;
		switch (menuOption) {
		case 1:
			cout << "Enter new address: ";
			cin >> newAddress;
			h->setAddress(newAddress);
			cout << "Address updated!" << endl << endl;
			break;
		case 2:
			h->addFloor();
			cout << "Floor added!" << endl;
			break;
		case 3:
			cout << "Which floor do you want to remove?" << endl;
			cout << h->getRoomsInfo(); // Prints all rooms
			cout << "This action will remove all existing reservations and rooms in the floor." << endl;
			cout << "\nEnter floor number (or 0 to go back): ";
			cin >> floorOperation;
			cout << endl;
			if (floorOperation < 0 || floorOperation > h->getFloors()) {
				cout << "ERROR: Not a valid Floor/Operation! Please try again..." << endl;
			}
			else if (floorOperation > 0 || floorOperation <= h->getFloors()) {
				h->removeRoomsFromFloor(menuOption);
				h->removeFloor();
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
		cout << "------ CLIENT MENU ------" << endl;
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
