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


int main() {
	RUN_TEST(testSplay);
	return 0;
}

