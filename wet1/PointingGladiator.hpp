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





struct PointingGladiator {
public:
	PointingGladiator(int id, int level, Trainer* owner) : id(id), level(level), owner(owner) {}
	bool operator<(const PointingGladiator& other) const;
	bool operator==(const PointingGladiator& other) const;
	bool operator!=(const PointingGladiator& other) const;
	ostream& print(ostream& os) const;
	int id;
	int level;
	Trainer* owner;
};

#include <stdio.h>


class UpdateFunctionPointing {
public:
	UpdateFunctionPointing(int code, int factor): code(code), factor(factor) {}
	bool operator()(PointingGladiator& glad) {
		if (glad.id % code != 0) return false;
		glad.level *= factor;
		return true;
	}
private:
	int code;
	int factor;
};




#endif /* PointingGladiator_hpp */

