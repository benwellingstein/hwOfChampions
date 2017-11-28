//
//  library1.cpp
//  wet1
//
//  Created by Ben on 26/11/2017.
//  Copyright © 2017 Ben. All rights reserved.
//

#include <stdio.h>

#include "library1.h"
#include "Colosseum.hpp"

//TODO
//IF GIVEN DS IS NULL - perhaps error checking on this level?


void* Init() {
	Colosseum * DS = new Colosseum();
	return (void*)DS;
}

StatusType AddTrainer(void *DS, int trainerID) {
	return ((Colosseum*)DS)-> AddTrainer (trainerID);
}

StatusType BuyGladiator(void *DS, int gladiatorID, int trainerID, int level) {
	return ((Colosseum*)DS)-> BuyGladiator(gladiatorID, trainerID, level);
}

StatusType FreeGladiator(void *DS, int gladiatorID) {
	return ((Colosseum*)DS)->FreeGladiator(gladiatorID);
}


StatusType LevelUp(void *DS, int gladiatorID, int levelIncrease) {
	return ((Colosseum*)DS)-> LevelUp(gladiatorID, levelIncrease);
}


StatusType UpgradeGladiator(void *DS, int gladiatorID, int upgradedID) {
	return ((Colosseum*)DS)-> UpgradeGladiator(gladiatorID, upgradedID);
}

StatusType GetTopGladiator(void *DS, int trainerID, int *gladiatorID) {
	return ((Colosseum*)DS)-> GetTopGladiator(trainerID, gladiatorID);
}


StatusType GetAllGladiatorsByLevel(void *DS, int trainerID, int **gladiators, int *numOfGladiator) {
	return ((Colosseum*)DS)->GetAllGladiatorsByLevel(trainerID, gladiators, numOfGladiator);
}


StatusType UpdateLevels(void *DS, int stimulantCode, int stimulantFactor) {
	return ((Colosseum*)DS)->UpdateLevels(stimulantCode, stimulantFactor);
}


//TODO - when to run destructor? Not automatic?
void Quit(void** DS) {

}


