#include <assert.h>
#include <iostream>
#include "unitTests.h"

#include "SplayTree.hpp"
#include "Gladiator.hpp"

void testSplayLeft() {
	SplayTree<int,UpdateFunction> tree;
	int* a = new int(1);
	int* b = new int(2);
	int* c = new int(3);
	int* d = new int(4);
	int* e = new int(5);
	int* f = new int(6);
	int* g = new int(7);

    ASSERT_TRUE(tree.insertBT(d));
    ASSERT_TRUE(tree.insertBT(b));
    ASSERT_TRUE(tree.insertBT(f));
	ASSERT_TRUE(tree.insertBT(a));
	ASSERT_TRUE(tree.insertBT(c));
	ASSERT_TRUE(tree.insertBT(e));
	ASSERT_TRUE(tree.insertBT(g));

	
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
	SplayTree<int,UpdateFunction> tree;
	int* a = new int(1);
	int* b = new int(2);
	int* c = new int(3);
	int* d = new int(4);
	int* e = new int(5);
	int* f = new int(6);
	int* g = new int(7);
	
	tree.insertBT(d);
	tree.insertBT(b);
	tree.insertBT(f);
	tree.insertBT(a);
	tree.insertBT(c);
	tree.insertBT(e);
	tree.insertBT(g);
	
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
	SplayTree<int,UpdateFunction> tree;
	int* a = new int(1);
	int* b = new int(2);
	int* c = new int(3);
	int* d = new int(4);
	int* e = new int(5);
	int* f = new int(6);
	int* g = new int(7);
	tree.insertBT(f);
	tree.insertBT(b);
	tree.insertBT(g);
	tree.insertBT(a);
	tree.insertBT(d);
	tree.insertBT(c);
	tree.insertBT(e);
	
	std::stringstream out1;
	tree.print(out1);
	ASSERT_TRUE(out1.str() == "6 2 1 4 3 5 7 |1 2 3 4 5 6 7 |1 3 5 4 2 7 6 |");
	
	tree.splay(4);
	std::stringstream out2;
	
	tree.print(out2);
	ASSERT_TRUE(out2.str() == "4 2 1 3 6 5 7 |1 2 3 4 5 6 7 |1 3 2 5 7 6 4 |");
	
}

void testSplayRightLeft() {
	SplayTree<int,UpdateFunction> tree;
	int* a = new int(10);
	int* b = new int(5);
	int* c = new int(20);
	int* d = new int(15);
	int* e = new int(25);
	int* f = new int(12);
	int* g = new int(17);
	
	tree.insertBT(a);
	tree.insertBT(b);
	tree.insertBT(c);
	tree.insertBT(d);
	tree.insertBT(e);
	tree.insertBT(f);
	tree.insertBT(g);
	std::stringstream out1;
	tree.print(out1);
		ASSERT_TRUE(out1.str() == "10 5 20 15 12 17 25 |5 10 12 15 17 20 25 |5 12 17 15 25 20 10 |");
	
	tree.splay(15);
		std::stringstream out2;
		tree.print(out2);
		ASSERT_TRUE(out2.str() == "15 10 5 12 20 17 25 |5 10 12 15 17 20 25 |5 12 10 17 25 20 15 |");
}

void testAdvancedSplayLeftLeft() {
	SplayTree<int,UpdateFunction> tree;
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

	tree.insertBT(h);
	tree.insertBT(f);
	tree.insertBT(j);
	tree.insertBT(d);
	tree.insertBT(g);
	tree.insertBT(i);
	tree.insertBT(k);
	tree.insertBT(b);
	tree.insertBT(e);
	tree.insertBT(a);
	tree.insertBT(c);
	
	std::stringstream out1;
		tree.print(out1);
		ASSERT_TRUE(out1.str() == "8 6 4 2 1 3 5 7 1000 500 9999 |1 2 3 4 5 6 7 8 500 1000 9999 |1 3 2 5 4 7 6 500 9999 1000 8 |");
	
	tree.splay(2);
	std::stringstream out2;
	tree.print(out2);

	ASSERT_TRUE(out2.str() == "2 1 8 4 3 6 5 7 1000 500 9999 |1 2 3 4 5 6 7 8 500 1000 9999 |1 3 5 7 6 4 500 9999 1000 8 2 |");
}

void testSplayRightRight() {
	SplayTree<int,UpdateFunction> tree;
    int* a = new int(1);
    int* b = new int(2);
    int* c = new int(3);
    int* d = new int(4);
    int* e = new int(5);
    int* f = new int(6);
    int* g = new int(7);
    tree.insertBT(b);
    tree.insertBT(a);
    tree.insertBT(d);
    tree.insertBT(c);
    tree.insertBT(f);
    tree.insertBT(e);
    tree.insertBT(g);
    
    std::stringstream out1;
    tree.print(out1);
    ASSERT_TRUE(out1.str() == "2 1 4 3 6 5 7 |1 2 3 4 5 6 7 |1 3 5 7 6 4 2 |");
    
    tree.splay(6);
    std::stringstream out2;
    tree.print(out2);
    ASSERT_TRUE(out2.str() == "6 4 2 1 3 5 7 |1 2 3 4 5 6 7 |1 3 2 5 4 7 6 |");
    
}



void testAdvancedSplay1() {
	SplayTree<int,UpdateFunction> tree;
    int* a = new int(20);
    int* b1 = new int(10);
    int* b2 = new int(30);
    int* c1 = new int(5);
    int* c2 = new int(15);
    int* c3 = new int(25);
    int* c4 = new int(35);
    int* d1 = new int(2);
    int* d2 = new int(7);
    int* d3 = new int(12);
    int* d4 = new int(17);
    int* d5 = new int(22);
    int* d6 = new int(27);
    int* d7 = new int(32);
    int* d8 = new int(37);
    int* e01 = new int(1);
    int* e02 = new int(3);
    int* e03 = new int(6);
    int* e04 = new int(8);
    int* e05 = new int(11);
    int* e06 = new int(13);
    int* e07 = new int(16);
    int* e08 = new int(18);
    int* e09 = new int(21);
    int* e10 = new int(23);
    int* e11 = new int(26);
    int* e12 = new int(28);
    int* e13 = new int(31);
    int* e14 = new int(33);
    int* e15 = new int(36);
    int* e16 = new int(38);

    
    tree.insertBT(a);
    tree.insertBT(b1);
    tree.insertBT(b2);
    tree.insertBT(c1);
    tree.insertBT(c2);
    tree.insertBT(c3);
    tree.insertBT(c4);
    tree.insertBT(d1);
    tree.insertBT(d2);
    tree.insertBT(d3);
    tree.insertBT(d4);
    tree.insertBT(d5);
    tree.insertBT(d6);
    tree.insertBT(d7);
    tree.insertBT(d8);
    tree.insertBT(e01);
    tree.insertBT(e02);
    tree.insertBT(e03);
    tree.insertBT(e04);
    tree.insertBT(e05);
    tree.insertBT(e06);
    tree.insertBT(e07);
    tree.insertBT(e08);
    tree.insertBT(e09);
    tree.insertBT(e10);
    tree.insertBT(e11);
    tree.insertBT(e12);
    tree.insertBT(e13);
    tree.insertBT(e14);
    tree.insertBT(e15);
    tree.insertBT(e16);

    std::stringstream out1;
    tree.print(out1);

    ASSERT_TRUE(out1.str() == "20 10 5 2 1 3 7 6 8 15 12 11 13 17 16 18 30 25 22 21 23 27 26 28 35 32 31 33 37 36 38 |1 2 3 5 6 7 8 10 11 12 13 15 16 17 18 20 21 22 23 25 26 27 28 30 31 32 33 35 36 37 38 |1 3 2 6 8 7 5 11 13 12 16 18 17 15 10 21 23 22 26 28 27 25 31 33 32 36 38 37 35 30 20 |");
    tree.splay(1);
    std::stringstream out2;
    tree.print(out2);
    ASSERT_TRUE(out2.str() == "1 10 2 5 3 7 6 8 20 15 12 11 13 17 16 18 30 25 22 21 23 27 26 28 35 32 31 33 37 36 38 |1 2 3 5 6 7 8 10 11 12 13 15 16 17 18 20 21 22 23 25 26 27 28 30 31 32 33 35 36 37 38 |3 6 8 7 5 2 11 13 12 16 18 17 15 21 23 22 26 28 27 25 31 33 32 36 38 37 35 30 20 10 1 |");
}

void testAdvancedSplay2() {
	SplayTree<int,UpdateFunction> tree;
    int* a = new int(20);
    int* b1 = new int(10);
    int* b2 = new int(30);
    int* c1 = new int(5);
    int* c2 = new int(15);
    int* c3 = new int(25);
    int* c4 = new int(35);
    int* d1 = new int(2);
    int* d2 = new int(7);
    int* d3 = new int(12);
    int* d4 = new int(17);
    int* d5 = new int(22);
    int* d6 = new int(27);
    int* d7 = new int(32);
    int* d8 = new int(37);
    int* e01 = new int(1);
    int* e02 = new int(3);
    int* e03 = new int(6);
    int* e04 = new int(8);
    int* e05 = new int(11);
    int* e06 = new int(13);
    int* e07 = new int(16);
    int* e08 = new int(18);
    int* e09 = new int(21);
    int* e10 = new int(23);
    int* e11 = new int(26);
    int* e12 = new int(28);
    int* e13 = new int(31);
    int* e14 = new int(33);
    int* e15 = new int(36);
    int* e16 = new int(38);
    
    
    tree.insertBT(a);
    tree.insertBT(b1);
    tree.insertBT(b2);
    tree.insertBT(c1);
    tree.insertBT(c2);
    tree.insertBT(c3);
    tree.insertBT(c4);
    tree.insertBT(d1);
    tree.insertBT(d2);
    tree.insertBT(d3);
    tree.insertBT(d4);
    tree.insertBT(d5);
    tree.insertBT(d6);
    tree.insertBT(d7);
    tree.insertBT(d8);
    tree.insertBT(e01);
    tree.insertBT(e02);
    tree.insertBT(e03);
    tree.insertBT(e04);
    tree.insertBT(e05);
    tree.insertBT(e06);
    tree.insertBT(e07);
    tree.insertBT(e08);
    tree.insertBT(e09);
    tree.insertBT(e10);
    tree.insertBT(e11);
    tree.insertBT(e12);
    tree.insertBT(e13);
    tree.insertBT(e14);
    tree.insertBT(e15);
    tree.insertBT(e16);
    
    std::stringstream out1;
    tree.print(out1);
    ASSERT_TRUE(out1.str() == "20 10 5 2 1 3 7 6 8 15 12 11 13 17 16 18 30 25 22 21 23 27 26 28 35 32 31 33 37 36 38 |1 2 3 5 6 7 8 10 11 12 13 15 16 17 18 20 21 22 23 25 26 27 28 30 31 32 33 35 36 37 38 |1 3 2 6 8 7 5 11 13 12 16 18 17 15 10 21 23 22 26 28 27 25 31 33 32 36 38 37 35 30 20 |");
    
    tree.splay(2);
    std::stringstream out2;
    tree.print(out2);

    ASSERT_TRUE(out2.str() == "2 1 20 5 3 10 7 6 8 15 12 11 13 17 16 18 30 25 22 21 23 27 26 28 35 32 31 33 37 36 38 |1 2 3 5 6 7 8 10 11 12 13 15 16 17 18 20 21 22 23 25 26 27 28 30 31 32 33 35 36 37 38 |1 3 6 8 7 11 13 12 16 18 17 15 10 5 21 23 22 26 28 27 25 31 33 32 36 38 37 35 30 20 2 |");
}

void testAdvancedSplay3() {
	SplayTree<int,UpdateFunction> tree;
    int* a = new int(20);
    int* b1 = new int(10);
    int* b2 = new int(30);
    int* c1 = new int(5);
    int* c2 = new int(15);
    int* c3 = new int(25);
    int* c4 = new int(35);
    int* d1 = new int(2);
    int* d2 = new int(7);
    int* d3 = new int(12);
    int* d4 = new int(17);
    int* d5 = new int(22);
    int* d6 = new int(27);
    int* d7 = new int(32);
    int* d8 = new int(37);
    int* e01 = new int(1);
    int* e02 = new int(3);
    int* e03 = new int(6);
    int* e04 = new int(8);
    int* e05 = new int(11);
    int* e06 = new int(13);
    int* e07 = new int(16);
    int* e08 = new int(18);
    int* e09 = new int(21);
    int* e10 = new int(23);
    int* e11 = new int(26);
    int* e12 = new int(28);
    int* e13 = new int(31);
    int* e14 = new int(33);
    int* e15 = new int(36);
    int* e16 = new int(38);
    
    
    tree.insertBT(a);
    tree.insertBT(b1);
    tree.insertBT(b2);
    tree.insertBT(c1);
    tree.insertBT(c2);
    tree.insertBT(c3);
    tree.insertBT(c4);
    tree.insertBT(d1);
    tree.insertBT(d2);
    tree.insertBT(d3);
    tree.insertBT(d4);
    tree.insertBT(d5);
    tree.insertBT(d6);
    tree.insertBT(d7);
    tree.insertBT(d8);
    tree.insertBT(e01);
    tree.insertBT(e02);
    tree.insertBT(e03);
    tree.insertBT(e04);
    tree.insertBT(e05);
    tree.insertBT(e06);
    tree.insertBT(e07);
    tree.insertBT(e08);
    tree.insertBT(e09);
    tree.insertBT(e10);
    tree.insertBT(e11);
    tree.insertBT(e12);
    tree.insertBT(e13);
    tree.insertBT(e14);
    tree.insertBT(e15);
    tree.insertBT(e16);
    
    std::stringstream out1;
    tree.print(out1);
    ASSERT_TRUE(out1.str() == "20 10 5 2 1 3 7 6 8 15 12 11 13 17 16 18 30 25 22 21 23 27 26 28 35 32 31 33 37 36 38 |1 2 3 5 6 7 8 10 11 12 13 15 16 17 18 20 21 22 23 25 26 27 28 30 31 32 33 35 36 37 38 |1 3 2 6 8 7 5 11 13 12 16 18 17 15 10 21 23 22 26 28 27 25 31 33 32 36 38 37 35 30 20 |");
    
    tree.splay(3);

    std::stringstream out2;
    tree.print(out2);
    ASSERT_TRUE(out2.str() == "3 2 1 10 5 7 6 8 20 15 12 11 13 17 16 18 30 25 22 21 23 27 26 28 35 32 31 33 37 36 38 |1 2 3 5 6 7 8 10 11 12 13 15 16 17 18 20 21 22 23 25 26 27 28 30 31 32 33 35 36 37 38 |1 2 6 8 7 5 11 13 12 16 18 17 15 21 23 22 26 28 27 25 31 33 32 36 38 37 35 30 20 10 3 |");
}

void testFindMax() {
	SplayTree<int,UpdateFunction> tree;
    int* a = new int(20);
    int* b1 = new int(10);
    int* b2 = new int(30);
    int* c1 = new int(5);
    int* c2 = new int(15);
    int* c3 = new int(25);
    int* c4 = new int(35);
    int* d1 = new int(2);
    int* d2 = new int(7);
    int* d3 = new int(12);
    int* d4 = new int(17);
    int* d5 = new int(22);
    int* d6 = new int(27);
    int* d7 = new int(32);
    int* d8 = new int(37);
    int* e01 = new int(1);
    int* e02 = new int(3);
    int* e03 = new int(6);
    int* e04 = new int(8);
    int* e05 = new int(11);
    int* e06 = new int(13);
    int* e07 = new int(16);
    int* e08 = new int(18);
    int* e09 = new int(21);
    int* e10 = new int(23);
    int* e11 = new int(26);
    int* e12 = new int(28);
    int* e13 = new int(31);
    int* e14 = new int(33);
    int* e15 = new int(36);
    int* e16 = new int(38);
    
    
    tree.insertBT(a);
    tree.insertBT(b1);
    tree.insertBT(b2);
    tree.insertBT(c1);
    tree.insertBT(c2);
    tree.insertBT(c3);
    tree.insertBT(c4);
    tree.insertBT(d1);
    tree.insertBT(d2);
    tree.insertBT(d3);
    tree.insertBT(d4);
    tree.insertBT(d5);
    tree.insertBT(d6);
    tree.insertBT(d7);
    tree.insertBT(d8);
    tree.insertBT(e01);
    tree.insertBT(e02);
    tree.insertBT(e03);
    tree.insertBT(e04);
    tree.insertBT(e05);
    tree.insertBT(e06);
    tree.insertBT(e07);
    tree.insertBT(e08);
    tree.insertBT(e09);
    tree.insertBT(e10);
    tree.insertBT(e11);
    tree.insertBT(e12);
    tree.insertBT(e13);
    tree.insertBT(e14);
    tree.insertBT(e15);
    tree.insertBT(e16);
    
    std::stringstream out1;
    tree.print(out1);
    ASSERT_TRUE(out1.str() == "20 10 5 2 1 3 7 6 8 15 12 11 13 17 16 18 30 25 22 21 23 27 26 28 35 32 31 33 37 36 38 |1 2 3 5 6 7 8 10 11 12 13 15 16 17 18 20 21 22 23 25 26 27 28 30 31 32 33 35 36 37 38 |1 3 2 6 8 7 5 11 13 12 16 18 17 15 10 21 23 22 26 28 27 25 31 33 32 36 38 37 35 30 20 |");
    
//    Node* returnNode = tree.findMax();
	
}

void testAdvancedSplay6() {
	SplayTree<int,UpdateFunction> tree;
    int* a = new int(20);
    int* b1 = new int(10);
    int* b2 = new int(30);
    int* c1 = new int(5);
    int* c2 = new int(15);
    int* c3 = new int(25);
    int* c4 = new int(35);
    int* d1 = new int(2);
    int* d2 = new int(7);
    int* d3 = new int(12);
    int* d4 = new int(17);
    int* d5 = new int(22);
    int* d6 = new int(27);
    int* d7 = new int(32);
    int* d8 = new int(37);
    int* e01 = new int(1);
    int* e02 = new int(3);
    int* e03 = new int(6);
    int* e04 = new int(8);
    int* e05 = new int(11);
    int* e06 = new int(13);
    int* e07 = new int(16);
    int* e08 = new int(18);
    int* e09 = new int(21);
    int* e10 = new int(23);
    int* e11 = new int(26);
    int* e12 = new int(28);
    int* e13 = new int(31);
    int* e14 = new int(33);
    int* e15 = new int(36);
    int* e16 = new int(38);
    
    
    tree.insertBT(a);
    tree.insertBT(b1);
    tree.insertBT(b2);
    tree.insertBT(c1);
    tree.insertBT(c2);
    tree.insertBT(c3);
    tree.insertBT(c4);
    tree.insertBT(d1);
    tree.insertBT(d2);
    tree.insertBT(d3);
    tree.insertBT(d4);
    tree.insertBT(d5);
    tree.insertBT(d6);
    tree.insertBT(d7);
    tree.insertBT(d8);
    tree.insertBT(e01);
    tree.insertBT(e02);
    tree.insertBT(e03);
    tree.insertBT(e04);
    tree.insertBT(e05);
    tree.insertBT(e06);
    tree.insertBT(e07);
    tree.insertBT(e08);
    tree.insertBT(e09);
    tree.insertBT(e10);
    tree.insertBT(e11);
    tree.insertBT(e12);
    tree.insertBT(e13);
    tree.insertBT(e14);
    tree.insertBT(e15);
    tree.insertBT(e16);
    
    std::stringstream out1;
    tree.print(out1);
    ASSERT_TRUE(out1.str() == "20 10 5 2 1 3 7 6 8 15 12 11 13 17 16 18 30 25 22 21 23 27 26 28 35 32 31 33 37 36 38 |1 2 3 5 6 7 8 10 11 12 13 15 16 17 18 20 21 22 23 25 26 27 28 30 31 32 33 35 36 37 38 |1 3 2 6 8 7 5 11 13 12 16 18 17 15 10 21 23 22 26 28 27 25 31 33 32 36 38 37 35 30 20 |");
    
    tree.splay(6);
    std::stringstream out2;
    tree.print(out2);

    ASSERT_TRUE(out2.str() == "6 5 2 1 3 10 7 8 20 15 12 11 13 17 16 18 30 25 22 21 23 27 26 28 35 32 31 33 37 36 38 |1 2 3 5 6 7 8 10 11 12 13 15 16 17 18 20 21 22 23 25 26 27 28 30 31 32 33 35 36 37 38 |1 3 2 5 8 7 11 13 12 16 18 17 15 21 23 22 26 28 27 25 31 33 32 36 38 37 35 30 20 10 6 |");
}

void testAdvancedSplay7() {
	SplayTree<int,UpdateFunction> tree;
    int* a = new int(20);
    int* b1 = new int(10);
    int* b2 = new int(30);
    int* c1 = new int(5);
    int* c2 = new int(15);
    int* c3 = new int(25);
    int* c4 = new int(35);
    int* d1 = new int(2);
    int* d2 = new int(7);
    int* d3 = new int(12);
    int* d4 = new int(17);
    int* d5 = new int(22);
    int* d6 = new int(27);
    int* d7 = new int(32);
    int* d8 = new int(37);
    int* e01 = new int(1);
    int* e02 = new int(3);
    int* e03 = new int(6);
    int* e04 = new int(8);
    int* e05 = new int(11);
    int* e06 = new int(13);
    int* e07 = new int(16);
    int* e08 = new int(18);
    int* e09 = new int(21);
    int* e10 = new int(23);
    int* e11 = new int(26);
    int* e12 = new int(28);
    int* e13 = new int(31);
    int* e14 = new int(33);
    int* e15 = new int(36);
    int* e16 = new int(38);
    
    
    tree.insertBT(a);
    tree.insertBT(b1);
    tree.insertBT(b2);
    tree.insertBT(c1);
    tree.insertBT(c2);
    tree.insertBT(c3);
    tree.insertBT(c4);
    tree.insertBT(d1);
    tree.insertBT(d2);
    tree.insertBT(d3);
    tree.insertBT(d4);
    tree.insertBT(d5);
    tree.insertBT(d6);
    tree.insertBT(d7);
    tree.insertBT(d8);
    tree.insertBT(e01);
    tree.insertBT(e02);
    tree.insertBT(e03);
    tree.insertBT(e04);
    tree.insertBT(e05);
    tree.insertBT(e06);
    tree.insertBT(e07);
    tree.insertBT(e08);
    tree.insertBT(e09);
    tree.insertBT(e10);
    tree.insertBT(e11);
    tree.insertBT(e12);
    tree.insertBT(e13);
    tree.insertBT(e14);
    tree.insertBT(e15);
    tree.insertBT(e16);
    
    std::stringstream out1;
    tree.print(out1);
    ASSERT_TRUE(out1.str() == "20 10 5 2 1 3 7 6 8 15 12 11 13 17 16 18 30 25 22 21 23 27 26 28 35 32 31 33 37 36 38 |1 2 3 5 6 7 8 10 11 12 13 15 16 17 18 20 21 22 23 25 26 27 28 30 31 32 33 35 36 37 38 |1 3 2 6 8 7 5 11 13 12 16 18 17 15 10 21 23 22 26 28 27 25 31 33 32 36 38 37 35 30 20 |");
    
    tree.splay(7);
    std::stringstream out2;
    tree.print(out2);

    ASSERT_TRUE(out2.str() == "7 5 2 1 3 6 20 10 8 15 12 11 13 17 16 18 30 25 22 21 23 27 26 28 35 32 31 33 37 36 38 |1 2 3 5 6 7 8 10 11 12 13 15 16 17 18 20 21 22 23 25 26 27 28 30 31 32 33 35 36 37 38 |1 3 2 6 5 8 11 13 12 16 18 17 15 10 21 23 22 26 28 27 25 31 33 32 36 38 37 35 30 20 7 |");
}

void testAdvancedSplay8() {
	SplayTree<int,UpdateFunction> tree;
    int* a = new int(20);
    int* b1 = new int(10);
    int* b2 = new int(30);
    int* c1 = new int(5);
    int* c2 = new int(15);
    int* c3 = new int(25);
    int* c4 = new int(35);
    int* d1 = new int(2);
    int* d2 = new int(7);
    int* d3 = new int(12);
    int* d4 = new int(17);
    int* d5 = new int(22);
    int* d6 = new int(27);
    int* d7 = new int(32);
    int* d8 = new int(37);
    int* e01 = new int(1);
    int* e02 = new int(3);
    int* e03 = new int(6);
    int* e04 = new int(8);
    int* e05 = new int(11);
    int* e06 = new int(13);
    int* e07 = new int(16);
    int* e08 = new int(18);
    int* e09 = new int(21);
    int* e10 = new int(23);
    int* e11 = new int(26);
    int* e12 = new int(28);
    int* e13 = new int(31);
    int* e14 = new int(33);
    int* e15 = new int(36);
    int* e16 = new int(38);
    
    
    tree.insertBT(a);
    tree.insertBT(b1);
    tree.insertBT(b2);
    tree.insertBT(c1);
    tree.insertBT(c2);
    tree.insertBT(c3);
    tree.insertBT(c4);
    tree.insertBT(d1);
    tree.insertBT(d2);
    tree.insertBT(d3);
    tree.insertBT(d4);
    tree.insertBT(d5);
    tree.insertBT(d6);
    tree.insertBT(d7);
    tree.insertBT(d8);
    tree.insertBT(e01);
    tree.insertBT(e02);
    tree.insertBT(e03);
    tree.insertBT(e04);
    tree.insertBT(e05);
    tree.insertBT(e06);
    tree.insertBT(e07);
    tree.insertBT(e08);
    tree.insertBT(e09);
    tree.insertBT(e10);
    tree.insertBT(e11);
    tree.insertBT(e12);
    tree.insertBT(e13);
    tree.insertBT(e14);
    tree.insertBT(e15);
    tree.insertBT(e16);
    
    std::stringstream out1;
    tree.print(out1);
    
    ASSERT_TRUE(out1.str() == "20 10 5 2 1 3 7 6 8 15 12 11 13 17 16 18 30 25 22 21 23 27 26 28 35 32 31 33 37 36 38 |1 2 3 5 6 7 8 10 11 12 13 15 16 17 18 20 21 22 23 25 26 27 28 30 31 32 33 35 36 37 38 |1 3 2 6 8 7 5 11 13 12 16 18 17 15 10 21 23 22 26 28 27 25 31 33 32 36 38 37 35 30 20 |");
    
    tree.splay(8);
    std::stringstream out2;
    tree.print(out2);
    ASSERT_TRUE(out2.str() == "8 7 5 2 1 3 6 10 20 15 12 11 13 17 16 18 30 25 22 21 23 27 26 28 35 32 31 33 37 36 38 |1 2 3 5 6 7 8 10 11 12 13 15 16 17 18 20 21 22 23 25 26 27 28 30 31 32 33 35 36 37 38 |1 3 2 6 5 7 11 13 12 16 18 17 15 21 23 22 26 28 27 25 31 33 32 36 38 37 35 30 20 10 8 |");
}


void testBasicTreeinsertBT() {
    int* a = new int(1);
    int* b = new int(2);
    int* c = new int(3);
    
	SplayTree<int,UpdateFunction> tree;
    tree.insertBT(b);
    tree.insertBT(a);
    tree.insertBT(c);
    //    tree.inOrder()
}

void testInsertBTAdvanced(){
	SplayTree<int,UpdateFunction> tree;
    int* a = new int(1);
    ASSERT_TRUE(tree.insertBT(a));
    ASSERT_FALSE(tree.insertBT(a));
    //    tree.inOrder();
    
}


void testFind1() {
	SplayTree<int,UpdateFunction> tree;
    int* a = new int(20);
    int* b1 = new int(10);
    int* b2 = new int(30);
    int* c1 = new int(5);
    int* c2 = new int(15);
    int* c3 = new int(25);
    int* c4 = new int(35);
    int* d1 = new int(2);
    int* d2 = new int(7);
    int* d3 = new int(12);
    int* d4 = new int(17);
    int* d5 = new int(22);
    int* d6 = new int(27);
    int* d7 = new int(32);
    int* d8 = new int(37);
    int* e01 = new int(1);
    int* e02 = new int(3);
    int* e03 = new int(6);
    int* e04 = new int(8);
    int* e05 = new int(11);
    int* e06 = new int(13);
    int* e07 = new int(16);
    int* e08 = new int(18);
    int* e09 = new int(21);
    int* e10 = new int(23);
    int* e11 = new int(26);
    int* e12 = new int(28);
    int* e13 = new int(31);
    int* e14 = new int(33);
    int* e15 = new int(36);
    int* e16 = new int(38);
    
    
    tree.insertBT(a);
    tree.insertBT(b1);
    tree.insertBT(b2);
    tree.insertBT(c1);
    tree.insertBT(c2);
    tree.insertBT(c3);
    tree.insertBT(c4);
    tree.insertBT(d1);
    tree.insertBT(d2);
    tree.insertBT(d3);
    tree.insertBT(d4);
    tree.insertBT(d5);
    tree.insertBT(d6);
    tree.insertBT(d7);
    tree.insertBT(d8);
    tree.insertBT(e01);
    tree.insertBT(e02);
    tree.insertBT(e03);
    tree.insertBT(e04);
    tree.insertBT(e05);
    tree.insertBT(e06);
    tree.insertBT(e07);
    tree.insertBT(e08);
    tree.insertBT(e09);
    tree.insertBT(e10);
    tree.insertBT(e11);
    tree.insertBT(e12);
    tree.insertBT(e13);
    tree.insertBT(e14);
    tree.insertBT(e15);
    tree.insertBT(e16);
    
    std::stringstream out1;
    tree.print(out1);
    
    ASSERT_TRUE(out1.str() == "20 10 5 2 1 3 7 6 8 15 12 11 13 17 16 18 30 25 22 21 23 27 26 28 35 32 31 33 37 36 38 |1 2 3 5 6 7 8 10 11 12 13 15 16 17 18 20 21 22 23 25 26 27 28 30 31 32 33 35 36 37 38 |1 3 2 6 8 7 5 11 13 12 16 18 17 15 10 21 23 22 26 28 27 25 31 33 32 36 38 37 35 30 20 |");
    tree.find(1);
    std::stringstream out2;
    tree.print(out2);
    ASSERT_TRUE(out2.str() == "1 10 2 5 3 7 6 8 20 15 12 11 13 17 16 18 30 25 22 21 23 27 26 28 35 32 31 33 37 36 38 |1 2 3 5 6 7 8 10 11 12 13 15 16 17 18 20 21 22 23 25 26 27 28 30 31 32 33 35 36 37 38 |3 6 8 7 5 2 11 13 12 16 18 17 15 21 23 22 26 28 27 25 31 33 32 36 38 37 35 30 20 10 1 |");
}

void testFind4() {
	SplayTree<int,UpdateFunction> tree;
    int* a = new int(20);
    int* b1 = new int(10);
    int* b2 = new int(30);
    int* c1 = new int(5);
    int* c2 = new int(15);
    int* c3 = new int(25);
    int* c4 = new int(35);
    int* d1 = new int(2);
    int* d2 = new int(7);
    int* d3 = new int(12);
    int* d4 = new int(17);
    int* d5 = new int(22);
    int* d6 = new int(27);
    int* d7 = new int(32);
    int* d8 = new int(37);
    int* e01 = new int(1);
    int* e02 = new int(3);
    int* e03 = new int(6);
    int* e04 = new int(8);
    int* e05 = new int(11);
    int* e06 = new int(13);
    int* e07 = new int(16);
    int* e08 = new int(18);
    int* e09 = new int(21);
    int* e10 = new int(23);
    int* e11 = new int(26);
    int* e12 = new int(28);
    int* e13 = new int(31);
    int* e14 = new int(33);
    int* e15 = new int(36);
    int* e16 = new int(38);
    
    
    tree.insertBT(a);
    tree.insertBT(b1);
    tree.insertBT(b2);
    tree.insertBT(c1);
    tree.insertBT(c2);
    tree.insertBT(c3);
    tree.insertBT(c4);
    tree.insertBT(d1);
    tree.insertBT(d2);
    tree.insertBT(d3);
    tree.insertBT(d4);
    tree.insertBT(d5);
    tree.insertBT(d6);
    tree.insertBT(d7);
    tree.insertBT(d8);
    tree.insertBT(e01);
    tree.insertBT(e02);
    tree.insertBT(e03);
    tree.insertBT(e04);
    tree.insertBT(e05);
    tree.insertBT(e06);
    tree.insertBT(e07);
    tree.insertBT(e08);
    tree.insertBT(e09);
    tree.insertBT(e10);
    tree.insertBT(e11);
    tree.insertBT(e12);
    tree.insertBT(e13);
    tree.insertBT(e14);
    tree.insertBT(e15);
    tree.insertBT(e16);
    
    std::stringstream out1;
    tree.print(out1);
    
    ASSERT_TRUE(out1.str() == "20 10 5 2 1 3 7 6 8 15 12 11 13 17 16 18 30 25 22 21 23 27 26 28 35 32 31 33 37 36 38 |1 2 3 5 6 7 8 10 11 12 13 15 16 17 18 20 21 22 23 25 26 27 28 30 31 32 33 35 36 37 38 |1 3 2 6 8 7 5 11 13 12 16 18 17 15 10 21 23 22 26 28 27 25 31 33 32 36 38 37 35 30 20 |");
    tree.find(4);
    std::stringstream out2;
    tree.print(out2);
    ASSERT_TRUE(out2.str() == "3 2 1 10 5 7 6 8 20 15 12 11 13 17 16 18 30 25 22 21 23 27 26 28 35 32 31 33 37 36 38 |1 2 3 5 6 7 8 10 11 12 13 15 16 17 18 20 21 22 23 25 26 27 28 30 31 32 33 35 36 37 38 |1 2 6 8 7 5 11 13 12 16 18 17 15 21 23 22 26 28 27 25 31 33 32 36 38 37 35 30 20 10 3 |");
}

void testInsert4() {
	SplayTree<int,UpdateFunction> tree;
    //int* a = new int(20);
    int* b1 = new int(10);
    //int* b2 = new int(30);
    int* c1 = new int(5);
    int* c2 = new int(15);
    //int* c3 = new int(25);
    //int* c4 = new int(35);
    int* d1 = new int(2);
    int* d2 = new int(7);
    int* d3 = new int(12);
    int* d4 = new int(17);
    //int* d5 = new int(22);
    //int* d6 = new int(27);
    //int* d7 = new int(32);
    //int* d8 = new int(37);
    int* e01 = new int(1);
    int* e02 = new int(3);
    int* e03 = new int(6);
    int* e04 = new int(8);
    int* e05 = new int(11);
    int* e06 = new int(13);
    int* e07 = new int(16);
    int* e08 = new int(18);
    //int* e09 = new int(21);
    //int* e10 = new int(23);
    //int* e11 = new int(26);
    //int* e12 = new int(28);
    //int* e13 = new int(31);
    //int* e14 = new int(33);
    //int* e15 = new int(36);
    //int* e16 = new int(38);
    
    
    //tree.insertBT(a);
    tree.insertBT(b1);
    //tree.insertBT(b2);
    tree.insertBT(c1);
    tree.insertBT(c2);
    //tree.insertBT(c3);
    //tree.insertBT(c4);
    tree.insertBT(d1);
    tree.insertBT(d2);
    tree.insertBT(d3);
    tree.insertBT(d4);
    //tree.insertBT(d5);
    //tree.insertBT(d6);
    //tree.insertBT(d7);
    //tree.insertBT(d8);
    tree.insertBT(e01);
    tree.insertBT(e02);
    tree.insertBT(e03);
    tree.insertBT(e04);
    tree.insertBT(e05);
    tree.insertBT(e06);
    tree.insertBT(e07);
    tree.insertBT(e08);
    //tree.insertBT(e09);
    //tree.insertBT(e10);
    //tree.insertBT(e11);
    //tree.insertBT(e12);
    //tree.insertBT(e13);
    //tree.insertBT(e14);
    //tree.insertBT(e15);
    //tree.insertBT(e16);
    
    std::stringstream out1;
    tree.print(out1);
    ASSERT_TRUE(out1.str() == "10 5 2 1 3 7 6 8 15 12 11 13 17 16 18 |1 2 3 5 6 7 8 10 11 12 13 15 16 17 18 |1 3 2 6 8 7 5 11 13 12 16 18 17 15 10 |");
    
    int* newValue = new int(4);
    
    tree.insert(newValue);
    
    //cout << endl;
    //tree.print(cout);
    //cout << endl;
    
    std::stringstream out2;
    tree.print(out2);
    ASSERT_TRUE(out2.str() == "4 3 2 1 10 5 7 6 8 15 12 11 13 17 16 18 |1 2 3 4 5 6 7 8 10 11 12 13 15 16 17 18 |1 2 3 6 8 7 5 11 13 12 16 18 17 15 10 4 |");
}


void testFindAdvanced() {
	SplayTree<int,UpdateFunction> tree;

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

    tree.insertBT(a);
    tree.insertBT(b);
    tree.insertBT(c);
    tree.insertBT(d);
    tree.insertBT(e);
    tree.insertBT(f);
    tree.insertBT(g);
    tree.insertBT(h);
    tree.insertBT(i);
    tree.insertBT(j);
    tree.insertBT(k);
    tree.insertBT(l);
    
    ASSERT_TRUE(tree.exist(35));
    ASSERT_TRUE(tree.exist(39));
    ASSERT_TRUE(tree.exist(100));
    ASSERT_TRUE(tree.exist(99));
    ASSERT_TRUE(tree.exist(69));
    ASSERT_FALSE(tree.exist(131));
    ASSERT_FALSE(tree.exist(41));
    ASSERT_FALSE(tree.exist(60));
    //    tree.inOrder();
}


void testShoeLace(){
	SplayTree<int,UpdateFunction> tree;
	int* _1 = new int(1);
	int* _2 = new int(2);
	int* _3 = new int(3);
	int* _4 = new int(4);
	int* _5 = new int(5);
	int* _6 = new int(6);
	int* _7 = new int(7);
	int* _8 = new int(8);
	int* _9 = new int(9);
	int* _10 = new int(10);
	int* _11 = new int(11);
	int* _12 = new int(12);
	int* _13 = new int(13);
	int* _14 = new int(14);
	int* _15 = new int(15);

	tree.insertBT(_1);
	tree.insertBT(_2);
	tree.insertBT(_3);
	tree.insertBT(_4);
	tree.insertBT(_5);
	tree.insertBT(_6);
	tree.insertBT(_7);
	tree.insertBT(_8);
	tree.insertBT(_9);
	tree.insertBT(_10);
	tree.insertBT(_11);
	tree.insertBT(_12);
	tree.insertBT(_13);
	tree.insertBT(_14);
	tree.insertBT(_15);

	tree.splay(15);
	std::stringstream out1;
	tree.print(out1);
	ASSERT_TRUE(out1.str() == "15 2 1 4 3 6 5 8 7 10 9 12 11 14 13 |1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 |1 3 5 7 9 11 13 14 12 10 8 6 4 2 15 |");

//	expected
//			15
//	  	  /
//		2
//	   / \
//	  1   4
//		 / \
//		3   6
//		   / \
//		  5   8
//			 / \
//			7   10
//			   / \
//			  9  12
//				 / \
//				11 14
//				   /
//				  13
}


void testRemove() {
	SplayTree<int,UpdateFunction> tree;
	//int* a = new int(20);
	int* b1 = new int(10);
	//int* b2 = new int(30);
	int* c1 = new int(5);
	int* c2 = new int(15);
	//int* c3 = new int(25);
	//int* c4 = new int(35);
	int* d1 = new int(2);
	int* d2 = new int(7);
	int* d3 = new int(12);
	int* d4 = new int(17);
	//int* d5 = new int(22);
	//int* d6 = new int(27);
	//int* d7 = new int(32);
	//int* d8 = new int(37);
	int* e01 = new int(1);
	int* e02 = new int(3);
	int* e03 = new int(6);
	int* e04 = new int(8);
	int* e05 = new int(11);
	int* e06 = new int(13);
	int* e07 = new int(16);
	int* e08 = new int(18);
	//int* e09 = new int(21);
	//int* e10 = new int(23);
	//int* e11 = new int(26);
	//int* e12 = new int(28);
	//int* e13 = new int(31);
	//int* e14 = new int(33);
	//int* e15 = new int(36);
	//int* e16 = new int(38);
	
	
	//tree.insertBT(a);
	tree.insertBT(b1);
	//tree.insertBT(b2);
	tree.insertBT(c1);
	tree.insertBT(c2);
	//tree.insertBT(c3);
	//tree.insertBT(c4);
	tree.insertBT(d1);
	tree.insertBT(d2);
	tree.insertBT(d3);
	tree.insertBT(d4);
	//tree.insertBT(d5);
	//tree.insertBT(d6);
	//tree.insertBT(d7);
	//tree.insertBT(d8);
	tree.insertBT(e01);
	tree.insertBT(e02);
	tree.insertBT(e03);
	tree.insertBT(e04);
	tree.insertBT(e05);
	tree.insertBT(e06);
	tree.insertBT(e07);
	tree.insertBT(e08);
	//tree.insertBT(e09);
	//tree.insertBT(e10);
	//tree.insertBT(e11);
	//tree.insertBT(e12);
	//tree.insertBT(e13);
	//tree.insertBT(e14);
	//tree.insertBT(e15);
	//tree.insertBT(e16);
	tree.remove(11);
	
	
	std::stringstream out1;
	tree.print(out1);
	ASSERT_TRUE(out1.str() == "10 5 2 1 3 7 6 8 12 15 13 17 16 18 |1 2 3 5 6 7 8 10 12 13 15 16 17 18 |1 3 2 6 8 7 5 13 16 18 17 15 12 10 |");
	
	tree.remove(10);
	tree.remove(5);
	tree.remove(1);
	tree.remove(3);
	tree.remove(16);
	tree.remove(12);
	tree.remove(18);
	tree.remove(2);
	tree.remove(8);
	tree.remove(13);
	tree.remove(15);
	tree.remove(17);
	tree.remove(6);
	tree.remove(7);
	std::stringstream out2;
	tree.print(out2);
	ASSERT_TRUE(out2.str() == "|||");
	
}


void testTop() {
	SplayTree<int,UpdateFunction> tree;
	int* c1 = new int(5);
	int* d1 = new int(2);
	int* e01 = new int(1);
	int* e02 = new int(3);
	int* e03 = new int(6);
	int* e04 = new int(8);
	int* e05 = new int(11);
	int* e06 = new int(13);
	int* e07 = new int(16);

	
	ASSERT_TRUE(tree.getTop() == NULL);
	tree.insert(c1);
	ASSERT_TRUE(*tree.getTop() == 5);
	tree.remove(5);
	ASSERT_TRUE(tree.getTop() == NULL);
	tree.insert(e01);
	ASSERT_TRUE(*tree.getTop() == 1);

	tree.insert(e02);
	ASSERT_TRUE(*tree.getTop() == 3);

	tree.insert(e03);
	ASSERT_TRUE(*tree.getTop() == 6);

	tree.insert(e04);
	ASSERT_TRUE(*tree.getTop() == 8);

	tree.insert(e05);
	ASSERT_TRUE(*tree.getTop() == 11);
	tree.remove(11);
	ASSERT_TRUE(*tree.getTop() == 8);
	tree.remove(6);
	ASSERT_TRUE(*tree.getTop() == 8);
	tree.remove(8);
	ASSERT_TRUE(*tree.getTop() == 3);

	tree.insert(e06);
	ASSERT_TRUE(*tree.getTop() == 13);

	tree.insert(e07);
	ASSERT_TRUE(*tree.getTop() == 16);

	tree.insert(d1);
	ASSERT_TRUE(*tree.getTop() == 16);

	
}

void testInsertLowest() {
	SplayTree<int,UpdateFunction> tree;

	int* a = new int(1);
	int* b = new int(2);
	int* c = new int(3);
	int* d = new int(4);
	
	tree.insertBT(b);
	tree.insertBT(c);
	tree.insertBT(d);

	tree.insert(a);
	
	std::stringstream out1;
	tree.print(out1);
	ASSERT_TRUE(out1.str() == "1 2 3 4 |1 2 3 4 |4 3 2 1 |");
	
	
}

void testLeftInsert() {
	SplayTree<int,UpdateFunction> tree;

	int* one = new int(1);
	int* two = new int(2);
	int* three = new int(3);
	int* four = new int(4);
	int* five = new int(5);
	int* six = new int(6);
	
	tree.insertBT(two);
	tree.insertBT(one);
	tree.insertBT(five);
	tree.insertBT(four);
	tree.insertBT(six);

	tree.insert(three);

	std::stringstream out1;
	tree.print(out1);
	ASSERT_TRUE(out1.str() == "3 2 1 4 5 6 |1 2 3 4 5 6 |1 2 6 5 4 3 |");

}


int splayTests() {
	cout << "-------SPLAY TESTS-----------" << endl;
	RUN_TEST(testSplayLeft);
	RUN_TEST(testSplayRight);
	RUN_TEST(testSplayLeftRight);
	RUN_TEST(testSplayRightLeft);
	RUN_TEST(testAdvancedSplayLeftLeft);
	RUN_TEST(testSplayRightRight);
    RUN_TEST(testAdvancedSplay1);
    RUN_TEST(testAdvancedSplay2);
    RUN_TEST(testAdvancedSplay3);
    RUN_TEST(testAdvancedSplay6);
    RUN_TEST(testAdvancedSplay7);
    RUN_TEST(testAdvancedSplay8);
    RUN_TEST(testBasicTreeinsertBT);
    RUN_TEST(testFind1);
    RUN_TEST(testFind4);
    RUN_TEST(testInsert4); 
    RUN_TEST(testFindAdvanced);
    RUN_TEST(testInsertBTAdvanced);
	RUN_TEST(testShoeLace);
	RUN_TEST(testRemove);
	RUN_TEST(testTop);
	RUN_TEST(testInsertLowest);
	RUN_TEST(testLeftInsert);
	return 0;
}

