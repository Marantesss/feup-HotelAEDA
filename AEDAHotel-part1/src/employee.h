#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Employee { // @suppress("Class has a virtual method and non-virtual destructor")
protected:
	int id;
	string name;
public:
	Employee(int id, string name);
	void setName(string name);
	void setId(int id);
	string getName();
	int getId();
	virtual string getInfo() const = 0;
};

class Supervisor: public Employee { // @suppress("Class has a virtual method and non-virtual destructor")
public:
	Supervisor(int id, string name);
	string getInfo() const;
};

#endif /* EMPLOYEE_H_ */
