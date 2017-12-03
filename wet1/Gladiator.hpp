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
	Gladiator(int id, int level) : id(id), level(level) {}
	bool operator<(const Gladiator& other) const;
	bool operator==(const Gladiator& other) const;
	bool operator!=(const Gladiator& other) const;
	ostream& print(ostream& os) const;
	int id;
	int level;
};


#endif /* Gladiator_hpp */
