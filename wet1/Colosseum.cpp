//
//  Colosseum.cpp
//  wet1
//
//  Created by Ben on 26/11/2017.
//  Copyright © 2017 Ben. All rights reserved.
//

//TODO fix code if memory allocation does not work.

#include "Colosseum.hpp"
#include "Gladiator.hpp"
using std::bad_alloc;














/* Description:   Adds a new trainer.
 * Input:         trainerID - The ID of the trainer to add.
 * Output:        None.
 * Return Values: ALLOCATION_ERROR - In case of an allocation error.
 *                INVALID_INPUT - if trainerID <= 0.
 *                FAILURE - If trainerID is already in the Colosseum.
 *                SUCCESS - Otherwise.
 */
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


/* Description:   Adds a new gladiator to the system.
 * Input:		  gladiatorID - ID of the gladiator to add.
 *                trainerID - The ID of the gladiator's trainer
 *                level - The gladiator's level
 * Output:        None.
 * Return Values: ALLOCATION_ERROR - In case of an allocation error.
 *                INVALID_INPUT - if gladiatorID <=0, or if trainerID <=0,
 *				  or if level <= 0
 *                FAILURE - If gladiatorID is already in the Colosseum,
 *				  or trainerID isn't in the Colosseum.
 *                SUCCESS - Otherwise.
 */
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



/* Description:   Removes an existing gladiator.
 * Input:		  gladiatorID - The ID of the gladiator to remove.
 * Output:        None.
 * Return Values: ALLOCATION_ERROR - In case of an allocation error.
 *                INVALID_INPUT - If gladiatorID <= 0.
 *                FAILURE - If gladiatorID isn't in the Colosseum.
 *                SUCCESS - Otherwise.
 */

StatusType Colosseum::FreeGladiator(int gladiatorID) {
	if (gladiatorID <= 0) return INVALID_INPUT;
	PointingGladiator dummy(gladiatorID, 100, NULL);
	if (!gladiatorIdTree.exist(dummy)) return FAILURE;
	PointingGladiator* gladiatorToFree = gladiatorIdTree.find(dummy);
	Gladiator dummy2(gladiatorID, gladiatorToFree->level);
	gladiatorIdTree.remove(dummy);
	gladiatorLevelTree.remove(dummy2);
	trainers.removeGladiator(gladiatorToFree->owner->id, gladiatorID,
							 gladiatorToFree->level);
	return SUCCESS;
}


/* Description:   Increases the level of a gladiator.
 * Input:         gladiatorID - The ID of the gladiator.
 *		          levelIncrease - The increase in level.
 * Output:        None.
 * Return Values: ALLOCATION_ERROR - In case of an allocation error.
 *                INVALID_INPUT - If gladiatorID<=0, or if levelIncrease<=0
 *                FAILURE - If gladiatorID isn't in the Colosseum.
 *                SUCCESS - Otherwise.
 */
StatusType Colosseum::LevelUp(int gladiatorID, int levelIncrease){
	if (gladiatorID<=0 || levelIncrease <= 0 ) return INVALID_INPUT;
	PointingGladiator dummy(gladiatorID, 100, NULL);
	if (!gladiatorIdTree.exist(dummy)) return FAILURE;
	try {
		PointingGladiator* gladiatorToFree = gladiatorIdTree.find(dummy);
		int newGladiatorLevel = levelIncrease + gladiatorToFree->level;
		Trainer* pTrainer = gladiatorToFree->owner;
		
		FreeGladiator(gladiatorID);

		//todo make names nicer
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


/* Description:   Upgrades a gladiator, updating his ID, while maintaining
 *				  his level.
 * Input:         gladiatorID - The original ID of the gladiator.
 *                upgradedID - The new ID of the gladiator.
 * Output:        None.
 * Return Values: ALLOCATION_ERROR - In case of an allocation error.
 *                INVALID_INPUT -If gladiatorID<=0, or if upgradedID<=0.
 *                FAILURE - If gladiatorID isn't in the Colosseum, or
 *				  upgradedID is in the Colosseum.
 *                SUCCESS - Otherwise.
 */
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

/* Description:   Returns the gladiator with the highest level from trainerID
 * 			If trainerID < 0, returns the top gladiator in the entire DS.
 * Input:         DS - A pointer to the data structure.
 *                trainerID - The trainer that we'd like to get the data for.
 * Output:        gladiatorID - A pointer to a variable that should be updated
 *					to the ID of the top gladiator.
 * Return Values: ALLOCATION_ERROR - In case of an allocation error.
 *                INVALID_INPUT - If DS==NULL, or if gladiatorID == NULL, or
 *					if trainerID == 0.
 *                SUCCESS - Otherwise.
 */
StatusType Colosseum::GetTopGladiator(int trainerID, int *gladiatorID){
	if (!gladiatorID || trainerID == 0) return INVALID_INPUT;
	if (trainerID > 0 && !trainers.exists(trainerID)) return FAILURE;
	
	if (trainerID > 0) {
		Trainer* trainer = trainers.findTrainer(trainerID);
		*gladiatorID = trainer->gladiators.getTop()->id;
		return SUCCESS;
	}
	
	*gladiatorID = gladiatorLevelTree.getTop()->id;
	return SUCCESS;
}

//todo try catch
StatusType Colosseum::GetAllGladiatorsByLevel(int trainerID, int **gladiators,
								   int *numOfGladiator){
	if (trainerID==0 || !gladiators || !numOfGladiator ) return INVALID_INPUT;
	if (trainerID>0 && !trainers.exists(trainerID)) return FAILURE;
	int arrSize;
	Gladiator** gladiatorList;
	if (trainerID < 0) {
	
	
		*numOfGladiator = gladiatorLevelTree.size();

		arrSize = *numOfGladiator;

		gladiatorList = (Gladiator**)malloc(sizeof(Gladiator*)*arrSize);
		if (!gladiatorList) return ALLOCATION_ERROR;
		gladiatorLevelTree.exportArr(gladiatorList);

	} else {
		Trainer* trainer = trainers.findTrainer(trainerID);
		*numOfGladiator = trainer->gladiators.size();
		arrSize = *numOfGladiator;
		gladiatorList = (Gladiator**)malloc(sizeof(Gladiator*)*arrSize);
		if (!gladiatorList) return ALLOCATION_ERROR;
		trainer->gladiators.exportArr(gladiatorList);
	}

	for (int i = 0; i < arrSize; ++i) {
		gladiators[i] = &gladiatorList[i]->id;
	}
	
	return SUCCESS;
}

int Colosseum::getNumberOfGladiators(int trainerID) {
    if(trainerID == 0) return -1;
    if(trainerID < 0) return gladiatorLevelTree.size();
    Trainer* trainer = trainers.findTrainer(trainerID);
    return trainer->gladiators.size();
}



//
//template <class T>
//class Stimulant {
//public:
//	Stimulant(int stimulantCode , int stimulantFactor) : stimulantCode(stimulantCode),
//	stimulantFactor(stimulantFactor) {}
//	
//	bool operator(const T& val) {
//		if ( val % stimulantCode == 0) {
//			
//		}
//	}
//private:
//	int stimulantCode;
//	int stimulantFactor;
//};




/* Description:   Updates the level of the gladiators where
 *				  gladiatorID % stimulantCode == 0.
 * 			      For each matching gladiator, multiplies its level
 *				  by stimulantFactor.
 * Input:         stimulantCode - The basis that the stimulant works on
 *          	  stimulantFactor - The multiply factor of the level
 * Output:        None.
 * Return Values: ALLOCATION_ERROR - In case of an allocation error.
 *                INVALID_INPUT - If stimulantCode < 1 or
 *				  if stimulantFactor <1
 *                SUCCESS - Otherwise.
 */
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
		//TODO update tree problem

	}
	catch (const bad_alloc& e) {
		return ALLOCATION_ERROR;
	}
	return SUCCESS;
}





