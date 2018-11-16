#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <iostream>
#include <string>
#include <vector>
#include "room.h"

using namespace std;

class Employee {
	int id;
	string name;
public:
	Employee(int id, string name);
	void setName(string name);
	void setId(int id);
	string getName();
	int getId();
};

class Supervisor:public Employee {
	vector<Room> appointedRooms;
public:
	Supervisor(int id, string name);
	void addARoom(Room *r);
	vector<Room> getARooms();
};

#endif /* HOTEL_H_ */
