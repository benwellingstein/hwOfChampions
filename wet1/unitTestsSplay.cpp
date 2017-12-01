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

void testFindAdvanced() {
    SplayTree<int> tree;
    
    int* a = new int(35);
    int* b = new int(9);
    int* c = new int(2);
    int* d = new int(18);
    int* e = new int(44);
    int* f = new int(73);
    int* g = new int(69);
    int* h = new int(39);
    int* i = new int(43);
    int* j = new int(96);
    int* k = new int(99);
    int* l = new int(100);

    tree.insert(a);
    tree.insert(b);
    tree.insert(c);
    tree.insert(d);
    tree.insert(e);
    tree.insert(f);
    tree.insert(g);
    tree.insert(h);
    tree.insert(i);
    tree.insert(j);
    tree.insert(k);
    tree.insert(l);
    
    ASSERT_TRUE(tree.find(35));
    ASSERT_TRUE(tree.find(39));
    ASSERT_TRUE(tree.find(100));
    ASSERT_TRUE(tree.find(99));
    ASSERT_TRUE(tree.find(69));
    ASSERT_FALSE(tree.find(131));
    ASSERT_FALSE(tree.find(41));
    ASSERT_FALSE(tree.find(60));
    //    tree.inOrder();
}


int main() {
	RUN_TEST(testSplay);
    RUN_TEST(testBasicTreeInsert);
    RUN_TEST(testFind);
    RUN_TEST(testFindAdvanced);
    RUN_TEST(testInsertAdvanced);
	return 0;
}

