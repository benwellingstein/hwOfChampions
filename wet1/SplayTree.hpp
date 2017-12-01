//TODO
//insert
//remove
//find
//add double pointers


#ifndef SplayTree_hpp
#define SplayTree_hpp

#include <stdio.h>
#include <iostream>
#include <assert.h>

using std::cout;
using std::ostream;
using std::endl;

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
		//case 1
		if (*(head->data) == val) return;
		
		Node* father = head;
		Node* current = findNext(head, val);
		
		//case2
		if (*(current->data) == val)  {
			if (*(father->data) < val)  {
				ZigR(&head, father, current);
				return;
			} else {
				ZigL(&head, father, current);
				return;
			}
		}
		
		Node* grandFather  = head;
		Node** pGrandFather = NULL;
		
		do {
		if (pGrandFather == NULL) {
			pGrandFather = &head;
		} else {
			pGrandFather = findDirection(grandFather, father);
		}
			
		
		grandFather = father;
		father = current;
		current = findNext(father, val);
		}
		while ( *(current->data) != val);
			
			
	switch (findOrder(grandFather, father, current)) {
		case LL:
			ZigZigLL(pGrandFather, grandFather, father, current);
			break;
		case LR:
			ZigZagLR(pGrandFather, grandFather, father, current);
			break;
		case RL:
			ZigZagRL(pGrandFather, grandFather, father, current);
			break;
		case RR:
			ZigZigRR(pGrandFather, grandFather, father, current);
			break;
		}
		splay(val);
	
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	ostream& inOrder(ostream& os) const{
		inOrderRecPrint(head,os);
		os << "|";
		return os;
	}
	
	ostream& postOrder(ostream& os) const{
		postOrderRecPrint(head,os);
		os << "|";
		return os;
	}
	ostream& preOrder(ostream& os) const{
		preOrderRecPrint(head,os);
		os << "|";
		return os;
	}
	
	ostream& print(ostream& os) const {
		preOrder(os);
		inOrder(os);
		postOrder(os);
		return os;
	}
	
	

private:
	enum Order { LL, LR, RL, RR} ;
	
	struct Node {
		
		Node(T* data): data(data), lChild(NULL), rChild(NULL) {}
		
		ostream& print(ostream& os) const {
//			os << "---------" << std::endl;
//			os << "address: " << this << std::endl;
			os  << *data << " ";
//			os << "lchild: " << lChild << std::endl;
//			os << "lchild: " << rChild << std::endl;
			return os;
		}
		
		bool operator<(const Node& other) {
			return *data < *other.data;
		}
		
		bool operator==(const Node& other) {
			return *data == *other.data;
		}
		
		bool operator!=(const Node& other) {
			return !(this == other);
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
	
	
	
	
	
	ostream& inOrderRecPrint(Node* node, ostream& os) const {
		if (node) {
			inOrderRecPrint(node->lChild, os);
			node->print(os);
			inOrderRecPrint(node->rChild, os);
		}
		return os;
	}
	
	
	ostream& preOrderRecPrint(Node* node, ostream& os) const {
		if (node) {
			node->print(os);
			preOrderRecPrint(node->lChild, os);
			preOrderRecPrint(node->rChild, os);
		}
		return os;

	}
	
	ostream& postOrderRecPrint(Node* node, ostream& os) const {
		if (node) {
			postOrderRecPrint(node->lChild, os);
			postOrderRecPrint(node->rChild, os);
			node->print(os);
		}
		return os;

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
	
	static void ZigR(Node** grandFather, Node* father, Node* child ) {
		*grandFather = child;
		father->rChild = child->lChild;
		child->lChild = father;
	}
	
	static void  ZigZagLR(Node** greatGrandFather, Node* grandFather,
						  Node* father, Node* child) {
		*greatGrandFather = child;
		father->rChild = child->lChild;
		grandFather->lChild = child->rChild;
		child->lChild = father;
		child->rChild = grandFather;
	}

	static void  ZigZagRL(Node** greatGrandFather, Node* grandFather,
						  Node* father, Node* child) {
		*greatGrandFather = child;
		father->lChild = child->rChild;
		grandFather->rChild = child->lChild;
		child->rChild = father;
		child->lChild = grandFather;
	}

	static void  ZigZigRR(Node** greatGrandFather, Node* grandFather,
						  Node* father, Node* child) {
		*greatGrandFather = child;
		grandFather->rChild = father->lChild;
		father->rChild = child->lChild;
		child->lChild = father;
		father->lChild = grandFather;
	}
	
	static void  ZigZigLL(Node** greatGrandFather, Node* grandFather,
						  Node* father, Node* child) {
		*greatGrandFather = child;
		grandFather->lChild = father->rChild;
		father->lChild = child->rChild;
		child->rChild = father;
		father->rChild = grandFather;
	}

	
	static Order findOrder(Node* grandFather, Node* father, Node* current) {
		if (*(grandFather->data) < *(father->data) ) {
			if (*(current->data) < *(father->data) ) {
				return RL;
			} else {
				return RR;
			}
		} else {
			if (*(current->data) < *(father->data)) {
				return LL;
			}else {
				return LR;
			}
		}

	}
	
	Node** findDirection(Node* grandFather, Node* father){
		if (*(grandFather->data) < *(father->data)) {
			return &(grandFather->rChild);
		} else {
			return &(grandFather->lChild);
		}
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







