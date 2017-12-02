#include <assert.h>
#include <iostream>
#include "unitTests.h"

#include "BinaryTree.hpp"


void testBasicTreeinsertBT) {
	int* a = new int(1);
	int* b = new int(2);
	int* c = new int(3);

	BinaryTree<int> tree;
	tree.insert(b);
	tree.insert(a);
	tree.insert(c);
//	tree.inOrder()
}

void testFind() {
	BinaryTree<int> tree;
	int* a = new int(1);
	int* b = new int(2);
	int* c = new int(3);
	tree.insertBTb);
	tree.insertBTa);
	tree.insertBTc);

	ASSERT_TRUE(tree.find(3));
	ASSERT_TRUE(tree.find(1));
	ASSERT_FALSE(tree.find(31));
	
	
}

void testInsertAdvanced(){
	BinaryTree<int> tree;
	int* a = new int(1);
	ASSERT_TRUE(tree.insert(a));
	ASSERT_FALSE(tree.insert(a));
	//	tree.inOrder();

}
int main() {
	RUN_TEST(testBasicTreeInsert);
	RUN_TEST(testFind);
//	RUN_TEST(testFindAdvanced);
	RUN_TEST(testInsertAdvanced);
	
	return 0;
}



