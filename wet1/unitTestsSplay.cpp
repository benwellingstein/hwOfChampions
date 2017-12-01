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
	
	tree.insert(d);
	tree.insert(b);
	tree.insert(f);
	tree.insert(a);
	tree.insert(c);
	tree.insert(e);
	tree.insert(g);
	
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




void testSplayLeftRight() {
	SplayTree<int> tree;
	int* a = new int(1);
	int* b = new int(2);
	int* c = new int(3);
	int* d = new int(4);
	int* e = new int(5);
	int* f = new int(6);
	int* g = new int(7);
	tree.insert(f);
	tree.insert(b);
	tree.insert(g);
	tree.insert(a);
	tree.insert(d);
	tree.insert(c);
	tree.insert(e);
	
	std::stringstream out1;
	tree.print(out1);

	ASSERT_TRUE(out1.str() == "6 2 1 4 3 5 7 |1 2 3 4 5 6 7 |1 3 5 4 2 7 6 |");
	
	tree.splay(4);
	std::stringstream out2;
	
	tree.print(cout);
	cout << endl;

	tree.print(out2);
	ASSERT_TRUE(out2.str() == "4 2 1 3 6 5 7 |1 2 3 4 5 6 7 |1 3 2 5 7 6 4 |");
	
}

void testSplayRightLeft() {
	SplayTree<int> tree;
	int* a = new int(10);
	int* b = new int(5);
	int* c = new int(20);
	int* d = new int(15);
	int* e = new int(25);
	int* f = new int(12);
	int* g = new int(17);
	
	tree.insert(a);
	tree.insert(b);
	tree.insert(c);
	tree.insert(d);
	tree.insert(e);
	tree.insert(f);
	tree.insert(g);
	std::stringstream out1;
	tree.print(out1);
		ASSERT_TRUE(out1.str() == "10 5 20 15 12 17 25 |5 10 12 15 17 20 25 |5 12 17 15 25 20 10 |");
	
	tree.splay(15);
		std::stringstream out2;
		tree.print(out2);
		ASSERT_TRUE(out2.str() == "15 10 5 12 20 17 25 |5 10 12 15 17 20 25 |5 12 10 17 25 20 15 |");
}

void testSplayLeftLeft() {
	SplayTree<int> tree;
	int* a = new int(1);
	int* b = new int(2);
	int* c = new int(3);
	int* d = new int(4);
	int* e = new int(5);
	int* f = new int(6);
	int* g = new int(7);
	int* h = new int(8);
	int* i = new int(500);
	int* j = new int(1000);
	int* k = new int(9999);

	tree.insert(h);
	tree.insert(c);
	tree.insert(j);
	tree.insert(d);
	tree.insert(f);
	tree.insert(i);
	tree.insert(k);
	tree.insert(a);
	tree.insert(b);
	tree.insert(e);
	tree.insert(g);
	
	std::stringstream out1;
	//	tree.print(cout);
	//	ASSERT_TRUE(out1.str() == "4 2 1 3 6 5 7 |1 2 3 4 5 6 7 |1 3 2 5 7 6 4 |");
	
	tree.splay(3);
	//	std::stringstream out2;
	//	tree.print(cout);
	//	ASSERT_TRUE(out2.str() == "6 4 2 1 3 5 7 |1 2 3 4 5 6 7 |1 3 2 5 4 7 6 |");
}


void testSplayRightRight() {
	SplayTree<int> tree;
	int* a = new int(1);
	int* b = new int(2);
	int* c = new int(3);
	int* d = new int(4);
	int* e = new int(5);
	int* f = new int(6);
	int* g = new int(7);
	tree.insert(b);
	tree.insert(a);
	tree.insert(d);
	tree.insert(c);
	tree.insert(f);
	tree.insert(e);
	tree.insert(g);

	std::stringstream out1;
		tree.print(out1);
		ASSERT_TRUE(out1.str() == "2 1 4 3 6 5 7 |1 2 3 4 5 6 7 |1 3 5 7 6 4 2 |");
	
	tree.splay(6);
		std::stringstream out2;
		tree.print(out2);
		ASSERT_TRUE(out2.str() == "6 4 2 1 3 5 7 |1 2 3 4 5 6 7 |1 3 2 5 4 7 6 |");

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
	RUN_TEST(testSplayLeftRight);
	RUN_TEST(testSplayRightLeft);
//	RUN_TEST(testSplayLeftLeft);
	RUN_TEST(testSplayRightRight);




//    RUN_TEST(testBasicTreeInsert);
//    RUN_TEST(testFind);
//    //    RUN_TEST(testFindAdvanced);
//    RUN_TEST(testInsertAdvanced);
	return 0;
}

