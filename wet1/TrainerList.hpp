//
//  Linked List that holds trainer information
//

#ifndef TrainerList_hpp
#define TrainerList_hpp

#include <stdio.h>
#include "SplayTree.hpp"
#include "Gladiator.hpp"

struct Trainer {
	Trainer(int id): id(id), gladiators(), next(NULL) {}
	int id;
	SplayTree<Gladiator,UpdateFunction> gladiators;
	Trainer* next;
	
};

class TrainerList {
public:
	TrainerList();
	~TrainerList();
	void addTrainer(int trainerID);
	
	void addGladiator(int trainerID, int gladiatorID, int gladiatorLevel);
	void removeGladiator(int trainerID, int gladiatorID, int gladiatorLevel);
	//returns array of gladiators sorted by level
	
	bool exists(int trainerID);
	
	//returns pointer to trainer
	Trainer* findTrainer(int trainerID);
private:
	
	Trainer* head;
};






#endif /* TrainerList_hpp */
