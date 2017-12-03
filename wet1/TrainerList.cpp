
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
	return (findTrainer(trainerID));
}

Trainer* TrainerList::findTrainer(int trainerID){
	Trainer* current = head;
	while (current) {
		if (current->id == trainerID) return current;
		current = current->next;
	}
	return NULL;
}





void TrainerList::addGladiator(int trainerID, int gladiatorID, int gladiatorLevel) {
	Trainer* trainer = findTrainer(trainerID);
	Gladiator* newGladiator = new Gladiator(gladiatorID,gladiatorLevel);
	trainer->gladiators.insert(newGladiator);
}
//void TrainerList::removeGladiator(int trainerID, int gladiatorID, int gladiatorLevel);
////returns ID of top gladiator of trainer
//int TrainerList::getTopGladiator(int trainerID) const;
////returns array of gladiators sorted by level
//int** TrainerList::getAllGlaidatorByLevel(int trainerID, int* numOfGladiators);

