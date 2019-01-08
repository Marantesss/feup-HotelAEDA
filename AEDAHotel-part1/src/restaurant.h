#ifndef RESTAURANT_H_
#define RESTAURANT_H_

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/** @defgroup restaurant restaurant
 * @{
 *
 * Classes to represent a restaurant
 */

/**
 *  A class used to represent a restaurant.
 *
 *  Each restaurant has a name, a type and it's distance to the hotel.
 */
class Restaurant {
	/**
	 * @brief name The restaurant's name.
	 */
	string name;

	/**
	 * @brief type The restaurant's type.
	 */
	string type;

	/**
	 * @brief distance The distance between the hotel and the restaurant.
	 */
	int distance;
public:
	/**
	 * @brief Default constructor.
	 */
	Restaurant();

	/**
	 * @brief Constructor.
	 *
	 * The constructor creates a Restaurant object with the data passed as argument.
	 *
	 * @param name The restaurant's name.
	 *
	 * @param type The restaurant's type.
	 *
	 * @param distance The distance between the hotel and the restaurant. 
	 *
	 */
	Restaurant(string name, string type, int distance);

	/**
	 * @brief Default destructor.
	 */
	~Restaurant();

	/**
	 * @brief Member function to get the restaurant's name.
	 *
	 * @return The restaurant's name.
	 */
	string getName() const;

	/**
	 * @brief Member function to get the restaurant's type.
	 *
	 * @return The restaurant's type.
	 */
	string getType() const;

	/**
	 * @brief Member function to get the distance between the hotel and the restaurant.
	 *
	 * @return The distance between the hotel and the restaurant.
	 */
	int getDistance() const;

	/**
	 * @brief Member function to change the restaurant's name.
	 *
	 * @param name The restaurant's name.
	 */
	void setName(string name);

	/**
	 * @brief Member function to change the restaurant's type.
	 *
	 * @param type The restaurant's type.
	 */
	void setType(string type);

	/**
	 * @brief Member function to change the distance between the hotel and the restaurant.
	 *
	 * @param distance The distance between the hotel and the restaurant
	 */
	void setDistance(int distance);

	/**
	 * @brief Member function to get the hotel information.
	 *
	 * @return String containing the hotel information.
	 */
	string getInfo() const;

	/**
	* @brief Overload of Operator < for class Restaurant.
	*
	* @param r The other restaurant to be compared to.
	*
	* @return true, if the if the first restaurant's type comes first in alphabetical order and in case they are the same it compares the distance between the hotel and the restaurants.
	*        false, if otherwise.
	*/
	bool operator < (const Restaurant &r) const;

	/**
	 * @brief Overload of Operator == for class Restaurant.
	 *
	 * @param r The other restaurant to be compared to.
	 *
	 * @return true, if the Restaurant's name is the same as the other restaurant.
	 * 		  false, if otherwise.
	 */
	bool operator == (const Restaurant &r) const;
};

/**
 *  A class used to represent an exception.
 *
 *  The exception object contains the non existing restaurant.
 */
class NonExistingRestaurant {
	/**
	 * @brief name The NonExistingRestaurant's name.
	 */
	string name;
public:
	/**
	 * @brief Constructor.
	 *
	 * The constructor creates a NonExistingRestaurant object with the supplied name.
	 *
	 * @param The name of the NonExistingRestaurant.
	 */
	NonExistingRestaurant(string name);

	/**
	 * @brief Const member function to get the object's name.
	 *
	 * @return The name that originated the creation of this object.
	 */
	string getName() const;
};

/**
 *  A class used to represent an exception.
 *
 *  The exception object contains the already existant restaurant.
 */
class ExistingRestaurant {
	/**
	 * @brief name The ExistingRestaurant's name.
	 */
	string name;
public:
	/**
	* @brief Constructor.
	*
	* The constructor creates an ExistingRestaurant object with the supplied name.
	*
	* @param The name of the ExistingRestaurant.
	*/
	ExistingRestaurant(string name);

	/**
	 * @brief Const member function to get the object's name.
	 *
	 * @return The name that originated the creation of this object.
	 */
	string getName() const;
};

/**@}*/

#endif /* CLIENT_H_ */