#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Employee {
protected:
	int id;
	string name;
	bool isSupervisor;
public:
	Employee();
	Employee(int id, string name, bool supervisor);
	~Employee() {};
	int getId();
	string getName();
	bool getIsSupervisor() const;
	string getInfo() const;
	void setId(int id);
	void setName(string name);
	void setIsSupervisor(bool supervisor);
	//operators
	bool operator == (int id);
	bool operator == (string name);
	bool operator < (Employee & e);
};

class NonExistingEmployee {
	int id;
public:
	NonExistingEmployee(int id);
	int getId() const;
};

#endif /* EMPLOYEE_H_ */
