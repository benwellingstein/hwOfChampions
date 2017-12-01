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
#include <iostream>
#include <assert.h>

using std::cout;
using std::ostream;


template <class T>
class SplayTree {
public:
	SplayTree(): head(NULL) {}
	
	~SplayTree() {
		inOrderRecDestroy(head);
	}
	
	
	
	bool find(const T& val) const {
		if (!head) {
			return false;
		} else {
			Node* currNode = head;
			while (1) {
				if ( (*(*currNode).data) == val ) return true;
				if ( val< (*(*currNode).data)) {
					if ( (*currNode).lChild) {
						currNode = currNode->lChild;
					} else {
						return false;
					}
				} else {
					if ((*currNode).rChild) {
						currNode = currNode->rChild;
					} else {
						return false;
					}
				}
			}
		}
	}
	
	bool insert(T* val) {
		if (find(*val)) return false;
		Node* newNode = new Node(val);
		if (!head) {
			head=newNode;
			return true;
		} else {
			Node* currNode = head;
			while (1) {
				if (*val < (*(*currNode).data)) {
					if ((*currNode).lChild) {
						currNode = currNode->lChild;
					} else {
						(currNode->lChild = newNode);
						return true;
					}
				} else {
					if ((*currNode).rChild ) {
						currNode = currNode->rChild;
					} else {
						(currNode->rChild = newNode);
						return true;
					}
				}
			}
		}
		assert(false);
		return false;
	}
	
	void splay(const T& val) {
		if (!find(val)) return;
		if (*(head->data) == val) return;
		Node* father = head;
		Node* current = findNext(head, val);
		if (*(current->data) == val) {
			ZigL(&head, father, current);
		}
		}
	
	
	
	void inOrder(){
		inOrderRecPrint(head);
	}
	
	
	
	
private:

	
	struct Node {
		
		Node(T* data): data(data), lChild(NULL), rChild(NULL) {}
		
		ostream& print(ostream& os) const {
			os << "---------" << std::endl;
			os << "address: " << this << std::endl;
			os << "data: " << *data << std::endl;
			os << "lchild: " << lChild << std::endl;
			os << "lchild: " << rChild << std::endl;
			return os;
		}
		
		bool operator<(const Node& other) {
			return *data < *other.data;
		}
		
		bool operator==(const Node& other) {
			return *data == *other.data;
		}
		
		T* data;
		Node* lChild;
		Node* rChild;
	};




	void inOrderRecDestroy(Node* node) const {
		if (node) {
			inOrderRecDestroy(node->lChild);
			inOrderRecDestroy(node->rChild);
			delete node->data;
			delete node;
		}
	}
	
	void inOrderRecPrint(Node* node) const {
		if (node) {
			inOrderRecPrint(node->lChild);
			node->print(cout);
			inOrderRecPrint(node->rChild);
		}
	}

	Node* findNext( Node* checkAgainst, const T& val) {
		if (*(checkAgainst->data)< val)  	return checkAgainst->rChild;
		if (val < *(checkAgainst->data)) 	return checkAgainst->lChild;
		if (val == *(checkAgainst->data)) 	return checkAgainst;
		assert(false);
		return NULL;
	}
	
	static void ZigL(Node** grandFather, Node* father, Node* child) {
		*grandFather = child;
		father->lChild = child->rChild;
		child->rChild = father;
	}
	
	
	Node* head;
	
	
	
};

























//#include <stdio.h>
//#include "BinaryTree.hpp"
//
//
//
//template <class T>
//class SplayTree : public BinaryTree<T> {
//
//public:
//
//	}
////	find
////  find max
////  find min
////
////	insert
////	split
////	delete
////	join
//
//private:
//
//
//
//
//};
//
//
//
//
//







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

















#endif /* SplayTree_hpp */







