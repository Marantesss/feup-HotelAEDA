#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

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
	virtual string getInfo() const; 
};

class Supervisor: public Employee {
public:
	Supervisor(int id, string name);
	virtual string getInfo() const;
};

#endif /* HOTEL_H_ */
