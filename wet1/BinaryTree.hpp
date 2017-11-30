//
//  BinaryTree.hpp
//  
//
//  Created by Ben on 30/11/2017.
//

#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include <stdio.h>
using std::cout;
using std::ostream;

class Node {
public:
	Node(const int& num): num(num), lChild(NULL), rChild(NULL) {}
	ostream& print(ostream& os) const {
		os << "---------" << std::endl;
		os << "address: " << this << std::endl;
		os << "data: " << num << std::endl;
		os << "lchild: " << lChild << std::endl;
		os << "lchild: " << rChild << std::endl;
		return os;
	}
	
	bool operator<(const Node& other) {
		return num< other.num;
	}
	
	bool operator==(const Node& other) {
		return num == other.num;
	}
	
	bool hasLeft() {
		return lChild!=NULL;
	}
	
	bool hasRight() {
		return rChild!=NULL;
	}
	
	Node* getL() const {
		return lChild;
	}
	
	Node* getR() const {
		return rChild;
	}
	
	void setL(Node* l) {
		lChild = l;
	}
	
	void setR(Node* r) {
		rChild = r;
	}
	
private:
	int num;
	Node* lChild;
	Node* rChild;
};


ostream& operator<<(ostream& os, const Node& node) {
	node.print(os);
	return os;
}





class BinaryTree {
public:
	BinaryTree(): head(NULL) {}
	
	bool find(const int& num) {
		if (!head) {
			return false;
		} else {
			Node dummyNode(num);
			Node* currNode = head;
			while (1) {
				if ((*currNode) == dummyNode ) return true;
				if (dummyNode<(*currNode)) {
					if (currNode->hasLeft()) {
						currNode = currNode->getL();
					} else {
						return false;
					}
				} else {
					if (currNode->hasRight()) {
						currNode = currNode->getR();
					} else {
						return false;
					}
				}
			}
		}
	}
	

	bool insert(const int& num) {
		if (find(num)) return false;
		Node* newNode = new Node(num);
		if (!head) {
			head=newNode;
			return true;
		} else {
			Node* currNode = head;
			while (1) {
				if ((*newNode)<(*currNode)) {
					if (currNode->hasLeft()) {
						currNode = currNode->getL();
					} else {
						(currNode->setL(newNode));
						return true;
					}
				} else {
					if (currNode->hasRight() ) {
						currNode = currNode->getR();
					} else {
						(currNode->setR(newNode));
						return true;
					}
				}
			}
		}
		assert(false);
		return false;
	}
	
	void inOrder(){
		inOrderRec(head);
	}
		
private:
	Node* head;
	
	
	void inOrderRec(Node* node) const {
		if (node) {
			inOrderRec(node->getL());
			node->print(cout);
			inOrderRec(node->getR());
		}
	}
};

#endif /* BinaryTree_hpp */
