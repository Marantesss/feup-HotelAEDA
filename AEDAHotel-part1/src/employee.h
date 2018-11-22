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
	Employee(int id, string name, bool supervisor);
	Employee();
	~Employee() {};
	void setName(string name);
	void setId(int id);
	void setIsSupervisor(bool supervisor);
	string getName();
	int getId();
	bool getIsSupervisor() const;
	string getInfo() const;
	//operators
	bool operator == (int id);
	bool operator == (string name);
	bool operator < (Employee & e);
};

class NonExistingEmployee {
	int id;	/**< int number. The NonExistingRoom's number. */
public:
	/**
	* A constructor.
	* The constructor creates a NonExistingRoom object with the supplied number.
	* @param An int, the number of the NonExistingRoom.
	*/
	NonExistingEmployee(int id);

	/**
	* A const member function with no arguments to get the object's number.
	* @return An int, the number that originated the creation of this object.
	*/
	int getId() const;
};

#endif /* EMPLOYEE_H_ */
