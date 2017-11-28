//
//  SplayTree.hpp
//  wet1
//
//  Created by Ben on 28/11/2017.
//  Copyright © 2017 Ben. All rights reserved.
//

#ifndef SplayTree_hpp
#define SplayTree_hpp

#include <stdio.h>

//struct splay
//{
//	int key;
//	splay* lchild;
//	splay* rchild;
//};
//
//class SplayTree {
//public:
//	SplayTree() {}
//
//	// RR(Y rotates to the right)
//	splay* RR_Rotate(splay* k2);
//
//	// LL(Y rotates to the left)
//	splay* LL_Rotate(splay* k2);
//
//	// An implementation of top-down splay tree
//	splay* Splay(int key, splay* root);
//
//
//	splay* newNode(int key);
//
//	splay* insert(int key, splay* root);
//
//	splay* remove(int key, splay* root);
//
//	splay* find(int key, splay* root);
//
//	void inOrder(splay* root);
//};













template <class T>
class SplayTree {
	
public:
	
//	find
//  find max
//  find min
//
//	insert
//	split
//	delete
//	join

private:
	
	class node {
	public:
		node(const T& data): data(data) {};
	private:
		T 	data;
		node* lchild;
		node* rchild;
	};
	
	node* head;
	
	
};



#endif /* SplayTree_hpp */
