#include <assert.h>
#include <iostream>
#include "unitTests.h"

#include "SplayTree.hpp"


void testSplayLeft() {
	SplayTree<int> tree;
	int* a = new int(1);
	int* b = new int(2);
	int* c = new int(3);
	int* d = new int(4);
	int* e = new int(5);
	int* f = new int(6);
	int* g = new int(7);

	ASSERT_TRUE(tree.insert(d));
	ASSERT_TRUE(tree.insert(b));
	ASSERT_TRUE(tree.insert(f));
	ASSERT_TRUE(tree.insert(a));
	ASSERT_TRUE(tree.insert(c));
	ASSERT_TRUE(tree.insert(e));
	ASSERT_TRUE(tree.insert(g));

	
//	expected
//			2
//		1		4
//			3		6
//				5		7
	
	
	
	std::stringstream out1;
	tree.print(out1);
	ASSERT_TRUE(out1.str() == "4 2 1 3 6 5 7 |1 2 3 4 5 6 7 |1 3 2 5 7 6 4 |");

	tree.splay(2);
	std::stringstream out2;
	tree.print(out2);
	ASSERT_TRUE(out2.str() == "2 1 4 3 6 5 7 |1 2 3 4 5 6 7 |1 3 5 7 6 4 2 |");

	
}


void testSplayRight() {
	SplayTree<int> tree;
	int* a = new int(1);
	int* b = new int(2);
	int* c = new int(3);
	int* d = new int(4);
	int* e = new int(5);
	int* f = new int(6);
	int* g = new int(7);
	
	ASSERT_TRUE(tree.insert(d));
	ASSERT_TRUE(tree.insert(b));
	ASSERT_TRUE(tree.insert(f));
	ASSERT_TRUE(tree.insert(a));
	ASSERT_TRUE(tree.insert(c));
	ASSERT_TRUE(tree.insert(e));
	ASSERT_TRUE(tree.insert(g));
	
	std::stringstream out1;
	tree.print(out1);
	ASSERT_TRUE(out1.str() == "4 2 1 3 6 5 7 |1 2 3 4 5 6 7 |1 3 2 5 7 6 4 |");
	
	tree.splay(6);
	
	std::stringstream out2;
	tree.print(out2);
	ASSERT_TRUE(out2.str() == "6 4 2 1 3 5 7 |1 2 3 4 5 6 7 |1 3 2 5 4 7 6 |");
	
//	expected
//			6
//		4		7
//	2		5
//1		3
	
}


void testBasicTreeInsert() {
    int* a = new int(1);
    int* b = new int(2);
    int* c = new int(3);
    
    SplayTree<int> tree;
    tree.insert(b);
    tree.insert(a);
    tree.insert(c);
    //    tree.inOrder()
}

void testFind() {
    SplayTree<int> tree;
    int* a = new int(1);
    int* b = new int(2);
    int* c = new int(3);
    tree.insert(b);
    tree.insert(a);
    tree.insert(c);
    
    ASSERT_TRUE(tree.find(3));
    ASSERT_TRUE(tree.find(1));
    ASSERT_FALSE(tree.find(31));
    
    
}

void testInsertAdvanced(){
    SplayTree<int> tree;
    int* a = new int(1);
    ASSERT_TRUE(tree.insert(a));
    ASSERT_FALSE(tree.insert(a));
    //    tree.inOrder();
    
}


int main() {
	RUN_TEST(testSplayLeft);
	RUN_TEST(testSplayRight);

//    RUN_TEST(testBasicTreeInsert);
//    RUN_TEST(testFind);
//    //    RUN_TEST(testFindAdvanced);
//    RUN_TEST(testInsertAdvanced);
	return 0;
}

