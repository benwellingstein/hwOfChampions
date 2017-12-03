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
	SplayTree<Gladiator> gladiators;
	Trainer* next;
	
};

class TrainerList {
public:
	TrainerList();
	~TrainerList();
	void addTrainer(int trainerID);
	
	void addGladiator(int trainerID, int gladiatorID, int gladiatorLevel);
	void removeGladiator(int trainerID, int gladiatorID, int gladiatorLevel);//TODO
	//returns ID of top gladiator of trainer
	int getTopGladiator(int trainerID) const;//TODO
	//returns array of gladiators sorted by level
	int** getAllGlaidatorByLevel(int trainerID, int* numOfGladiators);//TODO
	
	bool exists(int trainerID);
	
	//returns pointer to trainer
	Trainer* findTrainer(int trainerID);
private:
	
	Trainer* head;
};






#endif /* TrainerList_hpp */
