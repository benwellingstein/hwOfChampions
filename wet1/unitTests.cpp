#include <assert.h>
#include <iostream>
#include "unitTests.h"
#include "unitTestsSplay.cpp"
#include "Colosseum.hpp"
#include "Gladiator.hpp"
#include "TrainerList.hpp"
#include "PointingGladiator.hpp"

void testGladiatorSorting() {
	Gladiator a(5,100);
	Gladiator b(3, 50);
	Gladiator c(2, 150);
	Gladiator d(3, 150);
	Gladiator e(1, 150);
	Gladiator cCopy(2, 150);
	ASSERT_TRUE(b<a);
	ASSERT_TRUE(b<c);
	ASSERT_TRUE(d<c);
	ASSERT_TRUE(d<e);
	ASSERT_TRUE(cCopy==c);
	ASSERT_TRUE(a!=e);
}

void testPointingGladiatorSorting() {
	PointingGladiator a(1, 100, NULL);
	PointingGladiator b(2, 399, NULL);
	PointingGladiator bCopy(2, 399, NULL);

	ASSERT_TRUE(a<b);
	ASSERT_TRUE(b==bCopy);
	ASSERT_FALSE(a==b);
	ASSERT_TRUE(a!=b);

}

void testTrainersCreation() {
	TrainerList trainers;
	trainers.addTrainer(1);
	trainers.addTrainer(2);
	trainers.addTrainer(3);
	ASSERT_TRUE(trainers.exists(1));
	ASSERT_TRUE(trainers.exists(2));
	ASSERT_TRUE(trainers.exists(3));
	ASSERT_FALSE(trainers.exists(4));


}

//void testGladiatorPrint() {
//	SplayTree<Gladiator> gladTree;
//	Gladiator* glad2Insert = new Gladiator(1,100);
//	gladTree.insert(glad2Insert);
//
//	gladTree.print(cout);
//}




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
	//TODO - automate test
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
	ASSERT_EQUALS(col.UpgradeGladiator(321, 321), FAILURE);

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
void testsGetAllGladiatorsByLevel() {
	Colosseum col;
	col.AddTrainer(1);
	col.AddTrainer(2);
	col.AddTrainer(3);
	col.AddTrainer(4);

	col.BuyGladiator(1337, 1, 1);
	col.BuyGladiator(1338, 2, 3);
	col.BuyGladiator(1339, 2, 2);
	col.BuyGladiator(1340, 2, 1);
	col.BuyGladiator(1341, 2, 999);
	col.BuyGladiator(1342, 2, 998);
	col.BuyGladiator(665, 3, 99999);
	col.BuyGladiator(1343, 4, 13);
	col.BuyGladiator(8888, 4, 1300);
	col.BuyGladiator(1000, 4, 1300);
	col.BuyGladiator(1345, 4, 1300);
	col.BuyGladiator(2, 4, 80000);
	
	
	int num = -3;
	int* size = &num;
	
	int bla = -1337;
	int* blap = &bla;
	int** arr = &(blap);
//    int numberOfGladiators = col.getNumberOfGladiators(-4);
	int** nullArr = NULL;
	
	
    //TODO check if not NULL
//	int** arr = (int**)malloc(sizeof(int*)*numberOfGladiators);

	ASSERT_EQUALS(col.GetAllGladiatorsByLevel(0, arr, size), INVALID_INPUT);
	ASSERT_EQUALS(col.GetAllGladiatorsByLevel(1, nullArr, size), INVALID_INPUT);
	ASSERT_EQUALS(col.GetAllGladiatorsByLevel(1, arr, NULL), INVALID_INPUT);

	
	ASSERT_EQUALS(col.GetAllGladiatorsByLevel(10, arr, size), FAILURE);

	ASSERT_EQUALS(col.GetAllGladiatorsByLevel(-4, arr, size), SUCCESS);

	
	
	ASSERT_EQUALS(*size,12);
    //cout << *arr[0] << endl;
    //cout << *arr[5] << endl;
	ASSERT_EQUALS(*arr[0], 1340);
	ASSERT_EQUALS((*arr)[1], 1337);
    ASSERT_EQUALS((*arr)[2], 1339);
    ASSERT_EQUALS((*arr)[3], 1338);
    ASSERT_EQUALS((*arr)[4], 1343);
    ASSERT_EQUALS((*arr)[5], 1342);
    ASSERT_EQUALS((*arr)[6], 1341);
    ASSERT_EQUALS((*arr)[7], 8888);
    ASSERT_EQUALS((*arr)[8], 1345);
    ASSERT_EQUALS((*arr)[9], 1000);
    ASSERT_EQUALS((*arr)[10], 2);
    ASSERT_EQUALS((*arr)[11], 665);
	
	col.FreeGladiator(2);
	col.FreeGladiator(1345);
	
	
	Colosseum col2;
	col2.AddTrainer(1);
	col2.AddTrainer(2);
	col2.AddTrainer(3);
	col2.AddTrainer(4);
	col2.BuyGladiator(1337, 1, 1);
	col2.BuyGladiator(1338, 2, 3);
	col2.BuyGladiator(1339, 2, 2);
	col2.BuyGladiator(1340, 2, 1);
	col2.BuyGladiator(1341, 2, 999);
	col2.BuyGladiator(1342, 2, 998);
	col2.BuyGladiator(665, 3, 99999);

	int bla2 = -1337;
	int* blap2 = &bla2;
	int** arr2 = &(blap2);
	int num2 = -3;
	int* size2 = &num2;
	ASSERT_EQUALS(col.GetAllGladiatorsByLevel(2, arr2, size2), SUCCESS);

	ASSERT_EQUALS(*size2,5);

	ASSERT_EQUALS((*arr2)[0], 1340);
	ASSERT_EQUALS((*arr2)[1], 1339);
	ASSERT_EQUALS((*arr2)[2], 1338);
	ASSERT_EQUALS((*arr2)[3], 1342);
	ASSERT_EQUALS((*arr2)[4], 1341);

	free(*arr);
	free(*arr2);
	
	
	//TODO check if not NULL
	
	
	
	
	
/*
	int num2 = -3;
	num2--;
	int* size2 = &num;
	int** arr2 = &size;
	ASSERT_EQUALS(col.GetAllGladiatorsByLevel(-2, arr2, size2), SUCCESS);
	ASSERT_EQUALS(*size,12);
	ASSERT_EQUALS(*(*arr+0), 655);

	
	int num3 = -3;
	num3--;
	int* size3 = &num;
	int** arr3 = &size;
	*/
	
	//ASSERT_EQUALS(col.GetAllGladiatorsByLevel(4, arr3, size3), SUCCESS);
	//ASSERT_EQUALS(*size2,3);



	//TODO check for trainedID>0

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
	Colosseum col;
	col.AddTrainer(1);
	col.BuyGladiator(1337, 1, 1);
	col.AddTrainer(2);
	col.BuyGladiator(1338, 2, 3);
	col.BuyGladiator(1339, 2, 2);
	col.BuyGladiator(1340, 2, 1);
	col.BuyGladiator(1341, 2, 999);
	col.BuyGladiator(1342, 2, 998);
	col.AddTrainer(3);
	col.BuyGladiator(665, 3, 99999);
	col.AddTrainer(4);
	col.BuyGladiator(1343, 4, 13);
	col.BuyGladiator(1344, 4, 130);
	col.BuyGladiator(1345, 4, 1300);
	col.BuyGladiator(1346, 4, 80000);

	int returnValue ;
	ASSERT_TRUE(col.GetTopGladiator(-2,&returnValue)==SUCCESS);
	ASSERT_TRUE(returnValue == 665);
	ASSERT_TRUE(col.GetTopGladiator(1,&returnValue)==SUCCESS);
	ASSERT_TRUE(returnValue == 1337);
	ASSERT_TRUE(col.GetTopGladiator(2,&returnValue)==SUCCESS);
	ASSERT_TRUE(returnValue == 1341);
	ASSERT_TRUE(col.GetTopGladiator(3,&returnValue)==SUCCESS);
	ASSERT_TRUE(returnValue == 665);
	ASSERT_TRUE(col.GetTopGladiator(4,&returnValue)==SUCCESS);
	ASSERT_TRUE(returnValue == 1346);

	ASSERT_TRUE(col.UpdateLevels(0, 3) == INVALID_INPUT);
	ASSERT_TRUE(col.UpdateLevels(-10, 3) == INVALID_INPUT);

	ASSERT_TRUE(col.UpdateLevels(1, 0) == INVALID_INPUT);
	ASSERT_TRUE(col.UpdateLevels(1, -13) == INVALID_INPUT);

	ASSERT_TRUE(col.UpdateLevels(2, 3) == SUCCESS);
	
	ASSERT_TRUE(col.GetTopGladiator(-2,&returnValue)==SUCCESS);
	ASSERT_TRUE(returnValue == 1346);
	ASSERT_TRUE(col.GetTopGladiator(1,&returnValue)==SUCCESS);
	ASSERT_TRUE(returnValue == 1337);
	ASSERT_TRUE(col.GetTopGladiator(2,&returnValue)==SUCCESS);
	ASSERT_TRUE(returnValue == 1342);
	ASSERT_TRUE(col.GetTopGladiator(3,&returnValue)==SUCCESS);
	ASSERT_TRUE(returnValue == 665);
	ASSERT_TRUE(col.GetTopGladiator(4,&returnValue)==SUCCESS);
	ASSERT_TRUE(returnValue == 1346);
	
}


int main() {
	cout << "-------COLOSSEUM TESTS-----------" << endl;

	RUN_TEST(testGladiatorSorting);
	RUN_TEST(testPointingGladiatorSorting);
	RUN_TEST(testTrainersCreation);
    RUN_TEST(testAddTrainer);
	RUN_TEST(testAddGladiator);
	RUN_TEST(testFreeGladiator);
	RUN_TEST(testLevelUp);
	RUN_TEST(testUpgradeGladiator);
	RUN_TEST(testGetTopGladiator);
	RUN_TEST(testsGetAllGladiatorsByLevel);
	RUN_TEST(testUpdateLevels);
	splayTests();

	
	return 0;
}
