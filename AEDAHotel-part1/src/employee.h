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
	virtual string getInfo() const;
	//operators
	bool operator == (int id);
	bool operator == (string name);
	bool operator < (Employee & e);
};

#endif /* EMPLOYEE_H_ */
