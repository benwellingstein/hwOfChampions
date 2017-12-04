//
//  updateFunction.hpp
//  wet1
//
//  Created by Ben on 04/12/2017.
//  Copyright © 2017 Ben. All rights reserved.
//

#ifndef updateFunction_hpp
#define updateFunction_hpp

#include <stdio.h>
#include "Gladiator.hpp"

class UpdateFunction {
public:
	UpdateFunction(int code, int factor ) : code(code), factor(factor) {}
	bool operator()(Gladiator& gladiator) {
		if (gladiator.id % code != 0) return false;
		gladiator.level *= factor;
		return true;
	}
private:
	int code;
	int factor;
};


#endif /* updateFunction_hpp */
