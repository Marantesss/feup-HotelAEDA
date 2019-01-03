#include "van.h"

/***************/
/** Van Class **/
/***************/

int Van::nextId = 1;

Van::Van() {
	this->id = this->nextId;
	this->capacity = 6;
	this->vacancies = 6;
	nextId++;
}

void Van::setId(int id){
	this->id = id;
}

int Van::getId() const{
	return id;
}

int Van::getCapacity() const {
	return capacity;
}

int Van::getVacancies() const {
	return vacancies;
}

void Van::addGroup(vector<Client*> & group) {
	vacancies = vacancies - group.size();
	for (unsigned i = 0; i < group.size(); i++) {
		onBoard.push_back(group[i]);
	}
}

bool Van::operator<(const Van & v1) const {
	if (this->vacancies < v1.vacancies)
		return false;
	return true;
}

bool Van::operator==(int id){
	if (this->id == id)
		return true;
	return false;
}

string Van::getInfo() const {
	stringstream ss;
	ss << "Van ID: " << id << endl;
	ss << "Vacancies: " << vacancies << endl;

	if (!this->onBoard.empty()) {
		ss << "Clients on board:" << endl;
		for (size_t i = 0; i < onBoard.size(); i++) {
			ss << i + 1 << ": " << onBoard[i]->getInfo2() << endl;
		}
	}
	else {
		ss << "(This van has no clients on board)" << endl;
	}

	return ss.str();
}

/******************************/
/** NonExistingVan exception **/
/******************************/

NonExistingVan::NonExistingVan(int id) : id(id) {}

int NonExistingVan::getId() const {
	return this->id;
}