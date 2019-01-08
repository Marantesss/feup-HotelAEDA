#include <iostream>
#include <string>
#include <sstream>
#include "hotel.h"
#include "client.h"
#include "reservation.h"
#include "room.h"
#include "date.h"
#include "van.h"
#include "AuxFunctions.h"
#include "menu.h"

using namespace std;

Hotel* buildDemoHotel() {
	Hotel *h = new Hotel(4, "Porto, Rua da Alegria 20");

	//... creating employees
	Employee *e1 = new Employee("Diogo Torres", false);
	h->addEmployee(*e1);

	Employee *e2 = new Employee("Gustavo Rodrigues", true);
	h->addEmployee(*e2);

	Employee *e3 = new Employee("Tiago Ferreira", false);
	h->addEmployee(*e3);

	Employee *e4 = new Employee("Armanda Correia", true);
	h->addEmployee(*e4);

	Employee *e5 = new Employee("Roberto Dias", false);
	h->addEmployee(*e5);

	Employee *e6 = new Employee("Joana Pereira", false);
	h->addEmployee(*e6);

	//... Building Rooms
	Bedroom *b101 = new Bedroom(101, 1, "Back");
	h->addRoom(b101);
	Bedroom *b102 = new Bedroom(102, 1, "Back");
	h->addRoom(b102);
	Bedroom *b103 = new Bedroom(103, 1, "Front");
	h->addRoom(b103);
	Bedroom *b104 = new Bedroom(104, 2, "Back");
	h->addRoom(b104);
	Bedroom *b105 = new Bedroom(105, 2, "Front");
	h->addRoom(b105);
	Bedroom *b201 = new Bedroom(201, 1, "Back");
	h->addRoom(b201);
	Bedroom *b202 = new Bedroom(202, 1, "Back");
	h->addRoom(b202);
	Bedroom *b203 = new Bedroom(203, 1, "Front");
	h->addRoom(b203);
	Bedroom *b204 = new Bedroom(204, 2, "Back");
	h->addRoom(b204);
	Bedroom *b205 = new Bedroom(205, 2, "Front");
	h->addRoom(b205);
	Bedroom *b301 = new Bedroom(301, 1, "Back");
	h->addRoom(b301);
	Bedroom *b302 = new Bedroom(302, 1, "Back");
	h->addRoom(b302);
	Bedroom *b303 = new Bedroom(303, 1, "Front");
	h->addRoom(b303);
	Bedroom *b304 = new Bedroom(304, 2, "Back");
	h->addRoom(b304);
	Bedroom *b305 = new Bedroom(305, 2, "Front");
	h->addRoom(b305);
	MeetingRoom *mr401 = new MeetingRoom(401, 25, true, true);
	h->addRoom(mr401);
	MeetingRoom *mr402 = new MeetingRoom(402, 10, false, false);
	h->addRoom(mr402);

	//... Creating Reservations
	// winter
	Date *winter1 = new Date(12, 12, 2019);
	Reservation *r1 = new Reservation(*winter1, b305, 2);
	h->addReservation(*r1);
	Date *winter2 = new Date(12, 2, 2019);
	Reservation *r2 = new Reservation(*winter2, b205, 1);
	h->addReservation(*r2);
	Date *winter3 = new Date(20, 2, 2018);
	Reservation *r3 = new Reservation(*winter3, b205, 4);
	h->addReservation(*r3);
	// Spring
	Date *spring1 = new Date(21, 4, 2019);
	Reservation *r4 = new Reservation(*spring1, b102, 1);
	h->addReservation(*r4);
	Date *spring2 = new Date(3, 5, 2019);
	Reservation *r5 = new Reservation(*spring2, b203, 3);
	h->addReservation(*r5);
	Date *spring3 = new Date(19, 5, 2018);
	Reservation *r6 = new Reservation(*spring3, b303, 3);
	h->addReservation(*r6);
	// Summer
	Date *summer1 = new Date(20, 6, 2019);
	Reservation *r7 = new Reservation(*summer1, b105, 4);
	h->addReservation(*r7);
	Date *summer2 = new Date(14, 7, 2019);
	Reservation *r8 = new Reservation(*summer2, b202, 5);
	h->addReservation(*r8);
	Date *summer3 = new Date(4, 7, 2018);
	Reservation *r9 = new Reservation(*summer3, b101, 2);
	h->addReservation(*r9);
	// Autumn
	Date *autumn1 = new Date(11, 9, 2019);
	Reservation *r10 = new Reservation(*autumn1, b301, 10);
	h->addReservation(*r10);
	Date *autumn2 = new Date(17, 10, 2019);
	Reservation *r11 = new Reservation(*autumn2, b203, 2);
	h->addReservation(*r11);
	Date *autumn3 = new Date(20, 9, 2018);
	Reservation *r12 = new Reservation(*autumn3, b205, 2);
	h->addReservation(*r12);

	//... creating old clients
	Date *bd1 = new Date(22, 3, 1977);
	Client *c1 = new Client("Sofia Pimenta", *bd1);
	c1->addReservation(r3);
	h->addClientRecord(c1);

	Date *bd2 = new Date(2, 2, 1999);
	Client *c2 = new Client("Miguel Sim�es", *bd2);
	c2->addReservation(r6);
	h->addClientRecord(c2);

	Date *bd3 = new Date(14, 8, 1995);
	Client *c3 = new Client("Diogo Mota", *bd3);
	c3->addReservation(r9);
	h->addClientRecord(c3);

	Date *bd4 = new Date(13, 1, 1997);
	Client *c4 = new Client("Goncalo Ribeiro", *bd4);
	c4->addReservation(r12);
	h->addClientRecord(c4);

	//... creating new clients
	Date *bd5 = new Date(11, 9, 1990);
	Client *c5 = new Client("Luis Goncalves", *bd5);
	c5->addReservation(r1);
	c5->addReservation(r5);
	h->checkInClient(c5);
	h->addClientRecord(c5);

	Date *bd6 = new Date(21, 4, 1996);
	Client *c6 = new Client("Joao Francisco", *bd6);
	c6->addReservation(r3);
	c6->addReservation(r2);
	h->checkInClient(c6);
	h->addClientRecord(c6);

	Date *bd7 = new Date(7, 12, 1978);
	Client *c7 = new Client("Maria Almeida", *bd7);
	c7->addReservation(r8);
	c7->addReservation(r4);
	h->checkInClient(c7);
	h->addClientRecord(c7);

	Date *bd8 = new Date(2, 9, 1986);
	Client *c8 = new Client("Carlos Marques", *bd8);
	c8->addReservation(r7);
	c8->addReservation(r6);
	h->checkInClient(c8);
	h->addClientRecord(c8);

	Date *bd9 = new Date(13, 1, 1987);
	Client *c9 = new Client("Jos� Pedro Castro", *bd9);
	c9->addReservation(r9);
	h->checkInClient(c9);
	h->addClientRecord(c9);

	//... creating vans
	vector<Client*> cli;
	cli.push_back(c1);
	cli.push_back(c2);
	Van *v1 = new Van();
	v1->addGroup(cli);
	h->addVan(*v1);

	Van *v2 = new Van();
	cli.push_back(c3);
	cli.push_back(c4);
	v2->addGroup(cli);
	h->addVan(*v2);
	cli.clear();

	Van *v3 = new Van();
	cli.push_back(c1);
	cli.push_back(c2);
	cli.push_back(c3);
	v3->addGroup(cli);
	h->addVan(*v3);

	// Creating Events
	Date *ev1d = new Date (19, 1, 2019);
	Event *ev1 = new Event("Hotel's Birthday Party", *ev1d, "Hotel AEDA", "Join us and come have fun with your family and friends with the opening of the Hotels new bar and dining room");
	h->addEvent(*ev1);

	Date *ev2d = new Date (14, 2, 2019);
	Event *ev2 = new Event("Valentine's day", *ev2d, "Rua do Rei, 23", "Come have fun with you significant other with a special Valentine's day dinner and romantic movie!");
	h->addEvent(*ev2);

	Date *ev3d = new Date (21, 4, 2019);
	Event *ev3 = new Event("Easter Egg Hunt", *ev3d, "Avenida da Liberdade, 45", "Easter is here, so bring the little ones in our annual easter egg hunt!");
	h->addEvent(*ev3);

	return h;

}

int main() {
	int menuOption;

	Hotel *h = buildDemoHotel();
	Date *currentDate = new Date();
	currentDate->getCurrentDate();

	cout << "=======================================" << endl;
	cout << "======== Welcome to Hotel AEDA ========" << endl;
	cout << "=======================================" << endl;
	sendHappyBirthayEmail(*currentDate, h);
	do {
		menuOption = menu(currentDate);
		switch(menuOption) {
		case 1: // Hotel Information
			hotelInformationMenu(h);
			break;
		case 2: // Clients
			clientMenu(h);
			break;
		case 3: // Reservations
			reservationMenu(h);
			break;
		case 4: // Rooms
			roomsMenu(h);
			break;
		case 5: // Employees
			employeesMenu(h);
			break;
		case 6: // Vans
			vansMenu(h);
			break;
		case 7: //Events
			eventMenu(h);
			break;
		case 8: //Next Day
			(*currentDate)++;
			sendHappyBirthayEmail(*currentDate, h);
			h->updateEvents(*currentDate);
			break;
		}
		if (menuOption < 0 || menuOption > 8) {
			cout << "ERROR: Not a valid Operation! Please try again..." << endl;
		}
	} while (menuOption != 0);

	return 0;
}
