/*
//TODO
 * fix code if memory allocation does not work.
 * make splay tree look like code
 * Dry finish up
*/

#include "Colosseum.hpp"
#include "Gladiator.hpp"
using std::bad_alloc;


StatusType Colosseum::AddTrainer(int trainerID) {
	if (trainerID <= 0) return INVALID_INPUT;
	if (trainers.exists(trainerID)) return FAILURE;
	try {
		trainers.addTrainer(trainerID);
	}
	catch (const bad_alloc& e) {
		return ALLOCATION_ERROR;
	};
	return SUCCESS;
}

StatusType Colosseum::BuyGladiator(int gladiatorID, int trainerID, int level) {
	if ((gladiatorID<=0) || (trainerID <=0) || (level<=0)) return INVALID_INPUT;
	PointingGladiator dummy(gladiatorID,level,NULL);
	if ( gladiatorIdTree.exist(dummy) || (!trainers.exists(trainerID)) )
		return FAILURE;
	try {
		Trainer* trainerP = trainers.findTrainer(trainerID);
		PointingGladiator* gladForIdTree = new PointingGladiator(gladiatorID,
															  level, trainerP);
		Gladiator* gladForLevelTree = new Gladiator(gladiatorID, level);
		trainers.addGladiator(trainerID, gladiatorID, level);
		gladiatorIdTree.insert(gladForIdTree);
		gladiatorLevelTree.insert(gladForLevelTree);
	}
	catch (const bad_alloc& e) {
		return ALLOCATION_ERROR;
	}
	return SUCCESS;
}

StatusType Colosseum::FreeGladiator(int gladiatorID) {
	if (gladiatorID <= 0) return INVALID_INPUT;
	PointingGladiator dummy(gladiatorID, 100, NULL);
	if (!gladiatorIdTree.exist(dummy)) return FAILURE;
	PointingGladiator* gladiatorToFree = gladiatorIdTree.find(dummy);
	Trainer* trainer = gladiatorToFree->owner;
	Gladiator dummy2(gladiatorID, gladiatorToFree->level);
	trainer->gladiators.remove(dummy2);
	gladiatorIdTree.remove(dummy);
	gladiatorLevelTree.remove(dummy2);
	return SUCCESS;
}

StatusType Colosseum::LevelUp(int gladiatorID, int levelIncrease){
	if (gladiatorID<=0 || levelIncrease <= 0 ) return INVALID_INPUT;
	PointingGladiator dummy(gladiatorID, 100, NULL);
	if (!gladiatorIdTree.exist(dummy)) return FAILURE;
	try {
		PointingGladiator* gladiatorToFree = gladiatorIdTree.find(dummy);
		int newGladiatorLevel = levelIncrease + gladiatorToFree->level;
		Trainer* pTrainer = gladiatorToFree->owner;
		FreeGladiator(gladiatorID);
		Gladiator* gladiatorToAddToTrainer = new Gladiator(gladiatorID,
												 newGladiatorLevel);
		Gladiator* gladiatorToAddToLevelTree = new Gladiator(gladiatorID, newGladiatorLevel);
		PointingGladiator* gladiatorToAddToIDTree = new PointingGladiator(gladiatorID, newGladiatorLevel, pTrainer);
		pTrainer->gladiators.insert(gladiatorToAddToTrainer);
		gladiatorIdTree.insert(gladiatorToAddToIDTree);
		gladiatorLevelTree.insert(gladiatorToAddToLevelTree);
	}
	catch (const bad_alloc& e) {
		return ALLOCATION_ERROR;
	}
	return SUCCESS;
}

StatusType Colosseum::UpgradeGladiator(int gladiatorID, int upgradedID){
	if (gladiatorID <= 0 || upgradedID <= 0) return INVALID_INPUT;
	if (!gladiatorIdTree.find(PointingGladiator(gladiatorID,100,NULL)) ||
		gladiatorIdTree.find(PointingGladiator(upgradedID, 100, NULL)) ||
		gladiatorID==upgradedID) return FAILURE;
	
	PointingGladiator* oldGladiator=  gladiatorIdTree.find(PointingGladiator
											(gladiatorID,100,NULL));
	Trainer* trainer = oldGladiator->owner;
	int gladiatorLevel = oldGladiator->level;
	
	gladiatorIdTree.remove(PointingGladiator(gladiatorID,100,NULL));
	gladiatorLevelTree.remove(Gladiator(gladiatorID,gladiatorLevel));
	trainer->gladiators.remove(Gladiator(gladiatorID,gladiatorLevel));

	try {
	Gladiator* gladiatorToAddToTrainer = new Gladiator(upgradedID,
													   gladiatorLevel);
	Gladiator* gladiatorToAddToLevelTree = new Gladiator(upgradedID,
														 gladiatorLevel);
	
	PointingGladiator* gladiatorToAddToIDTree = new PointingGladiator
										(upgradedID, gladiatorLevel, trainer);
	
		trainer->gladiators.insert(gladiatorToAddToTrainer);
		gladiatorIdTree.insert(gladiatorToAddToIDTree);
		gladiatorLevelTree.insert(gladiatorToAddToLevelTree);
	}
	catch (const bad_alloc& e) {
		return ALLOCATION_ERROR;
	}
	return SUCCESS;
}

StatusType Colosseum::GetTopGladiator(int trainerID, int *gladiatorID){
	if (!gladiatorID || trainerID == 0) return INVALID_INPUT;
	if (trainerID > 0 && !trainers.exists(trainerID)) return FAILURE;
	
	if (trainerID > 0) {
		Trainer* trainer = trainers.findTrainer(trainerID);
		if (trainer->gladiators.getTop() == NULL) {
			*gladiatorID = -1;
		} else {
			*gladiatorID = trainer->gladiators.getTop()->id;
		}
		return SUCCESS;
	}
	if (gladiatorLevelTree.getTop() == NULL ) {
		*gladiatorID = -1;
	} else {
		*gladiatorID = gladiatorLevelTree.getTop()->id;
	}
	return SUCCESS;
}

StatusType Colosseum::GetAllGladiatorsByLevel(int trainerID, int** gladiators,
								   int *numOfGladiator){
	if (trainerID==0 || !gladiators || !numOfGladiator ) return INVALID_INPUT;
	if (trainerID>0 && !trainers.exists(trainerID)) return FAILURE;
	
	int arrSize = getNumberOfGladiators(trainerID);
	Gladiator** gladiatorList;
	try {
		gladiatorList = (Gladiator**) new Gladiator[arrSize];
	}
	catch (const bad_alloc& e) {
		return ALLOCATION_ERROR;
	}
	
	exportByTrainerId(trainerID, gladiatorList);
	
	*gladiators = (int*)malloc(sizeof(int)*arrSize);
	if (!gladiators) return ALLOCATION_ERROR;
	for (int i = 0; i < arrSize; ++i) {
		(*gladiators)[arrSize-i-1] = gladiatorList[i]->id;
	}
	*numOfGladiator = arrSize;
	delete [] gladiatorList;
	return SUCCESS;
}


StatusType Colosseum::UpdateLevels(int stimulantCode, int stimulantFactor) {
	if (stimulantCode < 1 || stimulantFactor < 1) return INVALID_INPUT;
	
	UpdateFunction func = UpdateFunction(stimulantCode,stimulantFactor);
	try {
		gladiatorLevelTree.update(func);
		Trainer* trainer = trainers.findTrainer(-1);
		trainer = trainer->next;
		while (trainer) {
			trainer->gladiators.update(func);
			trainer = trainer->next;
		}
		UpdateFunctionPointing funcPointing = UpdateFunctionPointing(stimulantCode,stimulantFactor);
		gladiatorIdTree.update(funcPointing);
	}
	catch (const bad_alloc& e) {
		return ALLOCATION_ERROR;
	}
	return SUCCESS;
}

int Colosseum::getNumberOfGladiators(int trainerID) {
    if(trainerID == 0) return -1;
    if(trainerID < 0) return gladiatorLevelTree.size();
    Trainer* trainer = trainers.findTrainer(trainerID);
    return trainer->gladiators.size();
}

void Colosseum::exportByTrainerId(int trainerID, Gladiator** gladiatorList) {
	if (trainerID < 0 ) {
		gladiatorLevelTree.exportArr(gladiatorList);
	} else {
		Trainer* trainer = trainers.findTrainer(trainerID);
		trainer->gladiators.exportArr(gladiatorList);
	}
}
