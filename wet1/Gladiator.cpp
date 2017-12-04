#include "Gladiator.hpp"

ostream& Gladiator::print(ostream& os) const {
	os  << id << " ";
	return os;
	
}

ostream& operator<<(ostream& os, const Gladiator& gladiator) {
	gladiator.print(os);
	return os;
}

//Sorts by level and then by id
//			------Level----
//			|		|	  |
//		lower 		|	higher
//					|
//                Equal
//					|
//			-------ID------
//			|			  |
//		higher 			lower
//
bool Gladiator::operator<(const Gladiator& other) const {
	if (level < other.level) return true;
	if (other.level < level ) return false;
	if (id < other.id) return false;
	return true;
}

bool Gladiator::operator==(const Gladiator& other) const {
	return (id == other.id);
}

bool Gladiator::operator!=(const Gladiator& other) const {
	return !(*this==other);
}


Gladiator& Gladiator::operator=(const Gladiator& other){
	if (*this == other) return *this;
	Gladiator* newGladiator = new Gladiator();
	newGladiator->id = other.id;
	newGladiator->level = other.level;
	return *newGladiator;
}


Gladiator::Gladiator(const Gladiator& other) : id(other.id), level(other.level) {}




