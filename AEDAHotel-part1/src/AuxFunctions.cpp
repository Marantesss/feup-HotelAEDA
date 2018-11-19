#include "AuxFunctions.h"

template <class T>
void insertionSort(vector<T> &v) {
	for (size_t i = 1; i < v.size(); i++)
	{
		T tmp = v[i];
		size_t j;
		for (j = i; j > 0 && tmp < v[j - 1]; j--) {
			v[j] = v[j - 1];
		}
		v[j] = tmp;
	}
}

template <class T, class A>
int sequencialSearch(vector<T> vec, A x) {
	for (unsigned int i = 0; i < vec.size(); i++)
		if (v[i] == x)
			return i;
	return -1;
}

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
		cout << "Option: ";
		cin >> menuOption;
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
		cout << "Option: ";
		cin >> menuOption;
		if (menuOption < 0 || menuOption > 1) {
			cout << "ERROR: Not a valid Operation! Please try again..." << endl;
		}
	} while (menuOption < 0 || menuOption > 1);

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
		cout << "Option: ";
		cin >> menuOption;
		switch (menuOption) {
		case 1:
			cout << "Enter new address: ";
			cin >> newAddress;
			// h->setAddress(newAddress);
			cout << "Address updated!" << endl;
			break;
		case 2:
			// h->addFloor();
			cout << "Floor added!" << endl;
			break;
		case 3:
			cout << "Which floor do you want to remove?" << endl;
			cout << h->getRoomsInfo(); // Prints all rooms
			cout << "This action will remove all existing reservations and rooms in the floor." << endl;
			cout << "Enter floor number (or 0 to go back): ";
			cin >> floorOperation;
			if (floorOperation < 0 || floorOperation > h->getFloors()) {
				cout << "ERROR: Not a valid Floor/Operation! Please try again..." << endl;
			}
			else if (floorOperation > 0 || floorOperation <= h->getFloors()) {
				h->removeRoomsFromFloor(menuOption);
				h->removeFloor();
			}
			break;
		}
		if (menuOption < 0 || menuOption > h->getFloors()) {
			cout << "ERROR: Not a valid Operation! Please try again..." << endl;
		}
	} while (menuOption != 0);

	return menuOption;
}
