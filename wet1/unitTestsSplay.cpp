#include <assert.h>
#include <iostream>
#include "unitTests.h"

#include "SplayTree.hpp"


void testSplay() {
	SplayTree<int> tree;
	int* a = new int(1);
	int* b = new int(2);
	int* c = new int(3);
	int* d = new int(4);
	int* e = new int(5);
	int* f = new int(6);
	ASSERT_TRUE(tree.insert(a));
	ASSERT_TRUE(tree.insert(b));
	ASSERT_TRUE(tree.insert(c));
	ASSERT_TRUE(tree.insert(d));
	ASSERT_TRUE(tree.insert(e));
	ASSERT_TRUE(tree.insert(f));
	tree.splay(6);
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
	RUN_TEST(testSplay);
    RUN_TEST(testBasicTreeInsert);
    RUN_TEST(testFind);
    //    RUN_TEST(testFindAdvanced);
    RUN_TEST(testInsertAdvanced);
	return 0;
}

