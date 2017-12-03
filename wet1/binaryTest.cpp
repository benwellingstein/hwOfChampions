#include <assert.h>
#include <iostream>
#include "unitTests.h"

#include "BinaryTree.hpp"


void testBasicTreeinsertBT) {
	BinaryTree<int> tree;
	tree.insert(2);
	tree.insert(1);
	tree.insert(3);
//	tree.inOrder();
}

void testFind() {
	BinaryTree<int> tree;
	tree.insert(2);
	tree.insert(1);
	tree.insert(3);
	ASSERT_TRUE(tree.find(3));
	ASSERT_TRUE(tree.find(1));
	ASSERT_FALSE(tree.find(31));
}

void testFindAdvanced() {
	BinaryTree<int> tree;

	tree.insert(35);
	tree.insert(9);
	tree.insert(2);
	tree.insert(18);
	tree.insert(44);
	tree.insert(73);
	tree.insert(69);
	tree.insert(39);
	tree.insert(43);
	tree.insert(96);
	tree.insert(99);
	tree.insert(100);
	
	ASSERT_TRUE(tree.find(35));
	ASSERT_TRUE(tree.find(39));
	ASSERT_TRUE(tree.find(100));
	ASSERT_TRUE(tree.find(99));
	ASSERT_TRUE(tree.find(69));
	ASSERT_FALSE(tree.find(131));
	ASSERT_FALSE(tree.find(41));
	ASSERT_FALSE(tree.find(60));
//	tree.inOrder();
}

void testInsertAdvanced(){
	BinaryTree<int> tree;
	ASSERT_TRUE(tree.insertBT2));
	ASSERT_FALSE(tree.insertBT2));
	//	tree.inOrder();

}
int main() {
//	std::cout << "HI" ;
	RUN_TEST(testBasicTreeInsert);
	RUN_TEST(testFind);
	RUN_TEST(testFindAdvanced);
	RUN_TEST(testInsertAdvanced);

	return 0;
}


