#ifndef EVENT_H_
#define EVENT_H_

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "date.h"

/**
 * @defgroup event event
 * @{
 *
 *  Class necessary to handle events
 */

/**
 *  @brief A class used to represent an event
 *  Each event object has a name, a date, a location and a description.
 */
class Event {
	/**
	 * @brief name The event's name
	 */
	string name;

	/**
	 * @brief date The event's date
	 */
	Date date;

	/**
	 * @brief location The event's location
	 */
	string location;

	/**
	 * @brief description The event's description
	 */
	string description;
public:
	/**
	 * @brief Default constructor.
	 */
	Event();

	/**
	 * @brief Constructor.
	 *
	 * The constructor creates an Employee object with the data passed as argument.
	 *
	 * @param name The new event's name
	 *
	 * @param date The new events's date.
	 *
	 * @param location The new event's location.
	 *
	 * @param description The new event's description.
	 */
	Event(string name, Date date, string location, string description);

	/**
	 * @brief Default destructor.
	 */
	~Event(){}

	/**
	 * @brief Member function to get the event's date.
	 *
	 * @return The event's date.
	 */
	Date getDate() const;

	/**
	 * @brief Member function to get the event's name.
	 *
	 * @return The event's name.
	 */
	string getName() const;

	/**
	 * @brief Member function to get the event's location.
	 *
	 * @return The event's location.
	 */
	string getLocation() const;

	/**
	 * @brief Member function to get the event's description.
	 *
	 * @return The event's description.
	 */
	string getDescription() const;

	/**
	 * @brief Member function to show the event's information.
	 *
	 * @return The event's information.
	 */
	string getInfo() const;

	/**
	 * @brief Member function to check if an event's date is earlier than another's.
	 *
	 * @param ev The event that is being compared to
	 *
	 * @return True if the first event's date is sooner than the one's passed as an argument, false otherwise.
	 */
	bool operator < (Event ev) const;
};

/**@}*/

#endif /* EVENT_H_ */
