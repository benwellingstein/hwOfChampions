#include <assert.h>
#include <iostream>
#include "unitTests.h"

#include "Colosseum.hpp"


void testAddTrainer() {
	Colosseum col;
	ASSERT_EQUALS(col.AddTrainer(0), INVALID_INPUT);
	ASSERT_EQUALS(col.AddTrainer(-2), INVALID_INPUT);
	ASSERT_EQUALS(col.AddTrainer(1), SUCCESS);
	ASSERT_EQUALS(col.AddTrainer(1), FAILURE);
}


void testAddGladiator() {
	Colosseum col;
	ASSERT_EQUALS(col.BuyGladiator(0, 1, 1) , INVALID_INPUT);
	ASSERT_EQUALS(col.BuyGladiator(-10, 1, 1) , INVALID_INPUT);
	ASSERT_EQUALS(col.BuyGladiator(1, 0, 1) , INVALID_INPUT);
	ASSERT_EQUALS(col.BuyGladiator(1, -10, 1) , INVALID_INPUT);
	ASSERT_EQUALS(col.BuyGladiator(1, 1, 0) , INVALID_INPUT);
	ASSERT_EQUALS(col.BuyGladiator(1, 1, -10) , INVALID_INPUT);

	col.AddTrainer(1);
	ASSERT_EQUALS(col.BuyGladiator(1337, 1, 10) , SUCCESS);
	ASSERT_EQUALS(col.BuyGladiator(1337, 1, 10) , FAILURE);
	ASSERT_EQUALS(col.BuyGladiator(1, 666, 10) , FAILURE);
}


void testFreeGladiator() {
	Colosseum col;
	ASSERT_EQUALS(col.FreeGladiator(0), INVALID_INPUT);
	ASSERT_EQUALS(col.FreeGladiator(-20), INVALID_INPUT);

	col.AddTrainer(1);
	col.BuyGladiator(1337, 1, 7);
	
	ASSERT_EQUALS(col.FreeGladiator(666), FAILURE);
	ASSERT_EQUALS(col.FreeGladiator(1337), SUCCESS);
	ASSERT_EQUALS(col.FreeGladiator(1337), FAILURE);
}


void testLevelUp() {
	Colosseum col;
	ASSERT_EQUALS(col.LevelUp(0, 3), INVALID_INPUT);
	ASSERT_EQUALS(col.LevelUp(-20, 3), INVALID_INPUT);
	ASSERT_EQUALS(col.LevelUp(1, 0), INVALID_INPUT);
	ASSERT_EQUALS(col.LevelUp(2, -2), INVALID_INPUT);
	
	col.AddTrainer(1);
	col.BuyGladiator(1337, 1, 7);
	ASSERT_EQUALS(col.LevelUp(321, 3), FAILURE);
	ASSERT_EQUALS(col.LevelUp(1337, 3), SUCCESS);
}


void testUpgradeGladiator() {
	Colosseum col;
	ASSERT_EQUALS(col.UpgradeGladiator(0, 2), INVALID_INPUT);
	ASSERT_EQUALS(col.UpgradeGladiator(-20, 2), INVALID_INPUT);
	ASSERT_EQUALS(col.UpgradeGladiator(1, 0), INVALID_INPUT);
	ASSERT_EQUALS(col.UpgradeGladiator(1, -2), INVALID_INPUT);
	
	col.AddTrainer(1);
	col.BuyGladiator(1337, 1, 7);

	col.AddTrainer(2);
	col.BuyGladiator(1338, 2, 7);

	ASSERT_EQUALS(col.UpgradeGladiator(1, 1338), FAILURE);
	ASSERT_EQUALS(col.UpgradeGladiator(666, 999), FAILURE);
	ASSERT_EQUALS(col.UpgradeGladiator(1337, 321), SUCCESS);
	ASSERT_EQUALS(col.UpgradeGladiator(1338, 321), FAILURE);
}


void testGetTopGladiator() {
	Colosseum col;
	int returnVal = 0;
	ASSERT_EQUALS(col.GetTopGladiator(3, NULL), INVALID_INPUT);
	ASSERT_EQUALS(col.GetTopGladiator(0, &returnVal), INVALID_INPUT);

	col.AddTrainer(1);
	col.BuyGladiator(1337, 1, 1);
	col.AddTrainer(2);
	col.BuyGladiator(1338, 2, 3);
	col.BuyGladiator(1339, 2, 2);
	col.BuyGladiator(1340, 2, 1);
	col.BuyGladiator(1341, 2, 999);
	col.BuyGladiator(1342, 2, 4);
	col.AddTrainer(3);
	col.BuyGladiator(666, 3, 99999);

	ASSERT_EQUALS(col.GetTopGladiator(2, &returnVal), SUCCESS);
	ASSERT_EQUALS(returnVal, 1341);
	ASSERT_EQUALS(col.GetTopGladiator(1, &returnVal), SUCCESS);
	ASSERT_EQUALS(returnVal, 1337);
	ASSERT_EQUALS(col.GetTopGladiator(-1, &returnVal), SUCCESS);
	ASSERT_EQUALS(returnVal, 666);
}
/* Description:   Returns all the gladiators from trainerID sorted by their
 *				  level.
 *           	  If trainerID < 0, returns all the gladiators in the
 *				  entire Colosseum sorted by their level.
 * Input:		  trainerID - The trainer that we'd like to get the data
 *				  for.
 * Output:        gladiators - A pointer to a to an array that you should
 *			      update with the gladiators' IDs sorted by their level,
 *			      in case two gladiators have same level they should be
 *				  sorted by their ID.
 *                numOfGladiator - A pointer to a variable that should be
 *				  updated to the number of gladiators.
 * Return Values: ALLOCATION_ERROR - In case of an allocation error.
 *                INVALID_INPUT - If any of the arguments is NULL or if
 *				  trainerID == 0.
 *                SUCCESS - Otherwise.
 */
void tetsGetAllGladiatorsByLevel() {
	ASSERT_EQUALS(1, 1);
}


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
void testUpdateLevels() {
	ASSERT_EQUALS(1, 0);
}


int main() {
    RUN_TEST(testAddTrainer);
	RUN_TEST(testAddGladiator);
	RUN_TEST(testFreeGladiator);
	RUN_TEST(testLevelUp);
	RUN_TEST(testUpgradeGladiator);
	RUN_TEST(testGetTopGladiator);
	RUN_TEST(tetsGetAllGladiatorsByLevel);
	RUN_TEST(testUpdateLevels);
	return 0;
}
