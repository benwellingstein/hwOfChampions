
#include "PointingGladiator.hpp"


ostream& PointingGladiator::print(ostream& os) const {
	os  << id << " ";
	return os;
	
}
ostream& operator<<(ostream& os, const PointingGladiator& gladiator) {
	gladiator.print(os);
	return os;
}


//Sorts by id only
//			-------ID------
//			|			  |
//		lower 			higher
//
bool PointingGladiator::operator<(const PointingGladiator& other) const {
	return id < other.id;
}

bool PointingGladiator::operator==(const PointingGladiator& other) const {
	return (id == other.id);
}

bool PointingGladiator::operator!=(const PointingGladiator& other) const {
	return !(*this==other);
}

