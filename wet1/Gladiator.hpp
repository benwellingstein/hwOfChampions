//
//This is the gladiator that will be kept in order in a tree by
// Level and then by ID
//

#ifndef Gladiator_hpp
#define Gladiator_hpp

#include <stdio.h>
#include <iostream>
using std::ostream;

struct Gladiator {
public:
	Gladiator() {}
	Gladiator(int id, int level) : id(id), level(level) {}
	Gladiator(const Gladiator& other);
	Gladiator& operator=(const Gladiator& other);
	bool operator<(const Gladiator& other) const;
	bool operator==(const Gladiator& other) const;
	bool operator!=(const Gladiator& other) const;
	ostream& print(ostream& os) const;
	int id;
	int level;
};

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


#endif /* Gladiator_hpp */
