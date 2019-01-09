#ifndef VAN_H_
#define VAN_H_

#include <queue>
#include "client.h"

using namespace std;

/**
 * @defgroup van van
 * @{
 *
 *  Class necessary to handle excursions 
 */

/**
 *  @brief A class used to represent a van.
 *
 *  Each van object has an id, a van capacity, vacancies and an onBoard vector.
 *
 *  @see Client Class
 */
class Van {
	/**
	 * @brief id The van's id.
	 */
	int id;

	/**
	 * @brief capacity The van's capacity.
	 */
	int capacity;

	/**
	 * @brief vacancies The van's vacancies.
	 */
	int vacancies;

	/**
	 * @brief onBoard The hotel's clients on board of the van.
	 */
	vector <Client*> onBoard;

	/**
	 * @brief nextId The next van's id.
	 */
	static int nextId;

public:
	/**
	 * @brief Default constructor.
	 */
	Van();

	/**
	 * @brief Default destructor.
	 */
	~Van();
	
	/**
	 * @brief Member function to set the van's new id.
	 *
	 * @param The van's new id.
	 */
	void setId(int id);

	/**
	 * @brief Const member function to get the van's id.
	 *
	 * @return The van's id.
	 */
	int getId() const;

	/**
	 * @brief Const member function to get the van's capacity.
	 *
	 * @return The van's capacity.
	 */
	int getCapacity() const;

	/**
	 * @brief Const member function to get the van's vacancies.
	 *
	 * @return The van's vacancies.
	 */
	int getVacancies() const;

	/**
	 * @brief Const member function to get the van's information.
	 *
 	 * The return string will contain the van's id and vacancies
	 * followed by newline and a list containing all the clients on board.
	 *
	 * @return The van's id, vacancies and clients on board.
	 */
	string getInfo() const;

	/**
	 * @brief Member function to add a new group of clients.
	 *
	 * All the clients are pointers to the clients vector
	 * in the hotel class
	 *
	 * @param group A vector of pointers to the hotel's clients.
	 */
	void addGroup(vector<Client*>& group);

	/**
	 * @brief Overload of Operator < for class Van.
	 *
	 * @param v1 The other van to be compared to.
	 *
	 * @return true, if the first van's has a lower number of vacancies
	 * 	      false, if otherwise
	 */
	bool operator < (const Van& v1) const;

	/**
	 * @brief Overload of Operator == for class Van.
	 *
	 * @param id The other van's id to be compared to.
	 *
	 * @return true, if the Vans id is the same as the parameter
	 * 		  false, if otherwise
	 */
	bool operator == (int id);

};

class NonExistingVan {
	/**
	 * int id The NonExistingVan's id.
	 */
	int id;

public:
	/**
	 * @brief Constructor.
	 *
	 * The constructor creates a NonExistingVan object with the supplied id.
	 *
	 * @param id The id of the NonExistingVan.
	 */
	NonExistingVan(int id);

	/**
	 * @brief Const member function to get the object's id.
	 *
	 * @return The id that originated the creation of this object.
	 */
	int getId() const;
};

/**@}*/

#endif /* VAN_H_ */