#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// Employee Class
/**
 *  An abstract class used to represent an employee.
 *
 *  Each employee object has an id, a name and the possibility to be a supervisor.
 */
class Employee {

protected:
	/**
	 * int id The employee's id
	 */
	int id;

	/**
	 * string name The employee's name
	 */
	string name;

	/**
	 * bool isSupervisor The employee's possibility to be a supervisor
	 */
	bool isSupervisor;

	/**
	 * static int nextId The next employee's id.
	 */
	static int nextId;

public:
	/**
	 * @brief Default constructor.
	 */
	Employee();

	/**
	 * @brief Constructor.
	 *
	 * The constructor creates an Employee object with the data passed as argument.
	 *
	 * @param name The Employee's name.
	 *
	 * @param supervisor The Employee's possibility to be a supervisor.
	 */
	Employee(string name, bool supervisor);

	/**
	 * @brief Default destructor.
	 */
	~Employee() {};

	/**
	 * @brief Member function to get the employee's id.
	 *
	 * @return The employee's id.
	 */
	int getId();

	/**
	 * @brief Member function to get the employee's name.
	 *
	 * @return The employee's name.
	 */
	string getName();

	/**
	 * @brief Const member function to get the employee's possibility to be a supervisor.
	 *
	 * @return The employee's isSupervisor.
	 */
	bool getIsSupervisor() const;

	/**
	 * @brief Const member function to get the employee's information.
	 *
	 * @return The employee's information.
	 */
	string getInfo() const;

	/**
	 * @brief Member function to change the employee's id.
	 *
 	 * @param id The employee's new id.
	 */
	void setId(int id);

	/**
	 * @brief Member function to change the employee's name.
	 *
	 * @param name The employee's new name.
	 */
	void setName(string name);

	/**
	 * @brief Member function to change the employee's isSupervisor.
	 *
	 * @param supervisor The employee's new isSupervisor.
	 */
	void setIsSupervisor(bool supervisor);

	//operators
	/**
	 * @brief Overload of Operator == for class Employee.
	 *
	 * @param id The other employee's id to be compared to.
	 *
	 * @return true, if the Employee id is the same as the parameter
	 * 		  false, if otherwise
	 */
	bool operator == (int id);

	/**
	 * @brief Overload of Operator == for class Employee.
	 *
	 * @param name The other employee's name to be compared to.
	 *
	 * @return true, if the Employee name is the same as the parameter
	 * 		  false, if otherwise
	 */
	bool operator == (string name);

	/**
	 * @brief Overload of Operator < for class Employee.
	 *
	 * @param e The other employee to be compared to.
	 *
	 * @return true, if the first employee's id comes first
	 * 	      false, if otherwise
	 */
	bool operator < (Employee & e);
};

/**
 *  A class used to represent an exception.
 *
 *  The exception object contains the invalid Employee.
 */
class NonExistingEmployee {
	/**
	 * int id The NonExistingEmployee's id.
	 */
	int id;

public:
	/**
	 * @brief Constructor.
	 *
	 * The constructor creates a NonExistingEmployee object with the supplied id.
	 *
	 * @param id The id of the NonExistingEmployee.
	 */
	NonExistingEmployee(int id);

	/**
	 * @brief Const member function to get the object's id.
	 *
	 * @return The id that originated the creation of this object.
	 */
	int getId() const;
};

#endif /* EMPLOYEE_H_ */
