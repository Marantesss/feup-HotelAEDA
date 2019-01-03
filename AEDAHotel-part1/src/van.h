#ifndef VAN_H_
#define VAN_H_

#include <queue>
#include "client.h"

class Van {
	int id;
	int capacity;
	int vacancies;
	vector <Client*> onBoard;
	static int nextId;
public:
	Van();
	void setId(int id);
	int getId() const;
	int getCapacity() const;
	int getVacancies() const;
	void addGroup(vector<Client*>& group);
	bool operator < (const Van& v1) const;
	bool operator == (int id);
	string getInfo() const;
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
#endif