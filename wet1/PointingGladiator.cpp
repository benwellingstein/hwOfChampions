//
//  PointingGladiator.cpp
//  wet1
//
//  Created by Ben on 03/12/2017.
//  Copyright © 2017 Ben. All rights reserved.
//

#include "PointingGladiator.hpp"


ostream& PointingGladiator::print(ostream& os) const {
	os  << id << " ";
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

