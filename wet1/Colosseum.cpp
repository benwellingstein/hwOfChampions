//
//  Colosseum.cpp
//  wet1
//
//  Created by Ben on 26/11/2017.
//  Copyright © 2017 Ben. All rights reserved.
//

#include "Colosseum.hpp"


StatusType Colosseum::AddTrainer(int trainerID) {
	if (trainerID <= 0)  return FAILURE;
	return SUCCESS;
}


StatusType Colosseum::BuyGladiator(int gladiatorID, int trainerID, int level) {
	return SUCCESS;
}

StatusType Colosseum::FreeGladiator(int gladiatorID) {
	return SUCCESS;
}

StatusType Colosseum::LevelUp(int gladiatorID, int levelIncrease){
	return SUCCESS;
}


StatusType Colosseum::UpgradeGladiator(int gladiatorID, int upgradedID){
	return SUCCESS;
}


StatusType Colosseum::GetTopGladiator(int trainerID, int *gladiatorID){
	return SUCCESS;
}


StatusType Colosseum::GetAllGladiatorsByLevel(int trainerID, int **gladiators,
								   int *numOfGladiator){
	return SUCCESS;
}



StatusType Colosseum::UpdateLevels(int stimulantCode, int stimulantFactor){
	return SUCCESS;
}
