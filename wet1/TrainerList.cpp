
#include "TrainerList.hpp"


TrainerList::TrainerList() {
	head = new Trainer(-1);
}


//trainer that is being added must not already exist
void TrainerList::addTrainer(int trainerID) {
	Trainer* newTrainer = new Trainer(trainerID);
	newTrainer->next = head->next;
	head->next =newTrainer;
}

TrainerList::~TrainerList() {
	Trainer* currentTrainer = head;
	Trainer* nextTrainer = head;
	while (currentTrainer) {
		nextTrainer = currentTrainer->next;
		delete currentTrainer;
		currentTrainer = nextTrainer;
	}
}



bool TrainerList::exists(int trainerID) {
	Trainer* current = head;
	while (current) {
		if (current->id == trainerID) return true;
		current = current->next;
	}
	return false;
}

//void TrainerList::addGladiator(int trainerID, int gladiatorID, int gladiatorLevel);
//void TrainerList::removeGladiator(int trainerID, int gladiatorID, int gladiatorLevel);
////returns ID of top gladiator of trainer
//int TrainerList::getTopGladiator(int trainerID) const;
////returns array of gladiators sorted by level
//int** TrainerList::getAllGlaidatorByLevel(int trainerID, int* numOfGladiators);

