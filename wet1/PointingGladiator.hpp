//
//  PointingGladiator.hpp
//  wet1
//
//  Created by Ben on 03/12/2017.
//  Copyright © 2017 Ben. All rights reserved.
//
#include "TrainerList.hpp"
#ifndef PointingGladiator_hpp
#define PointingGladiator_hpp

class PointingGladiator {
public:
	PointingGladiator(int id, int level, Trainer* owner) : id(id), level(level), owner(owner) {}
	bool operator<(const PointingGladiator& other) const;
	bool operator==(const PointingGladiator& other) const;
	bool operator!=(const PointingGladiator& other) const;
	ostream& print(ostream& os) const;
private:
	int id;
	int level;
	Trainer* owner;
};


ostream& operator<<(ostream& os, const PointingGladiator& gladiator) {
	gladiator.print(os);
	return os;
}

#include <stdio.h>

#endif /* PointingGladiator_hpp */
