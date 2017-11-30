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


template <class T>
class BinaryTree {
public:
	BinaryTree(): head(NULL) {}
	
	~BinaryTree() {
		
	}
	
	
	
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
	
	class Node {
	public:
		Node(const T& data): data(data), lChild(NULL), rChild(NULL) {}
		
		ostream& print(ostream& os) const {
			os << "---------" << std::endl;
			os << "address: " << this << std::endl;
			os << "data: " << data << std::endl;
			os << "lchild: " << lChild << std::endl;
			os << "lchild: " << rChild << std::endl;
			return os;
		}
		
		bool operator<(const Node& other) {
			return data< other.data;
		}
		
		bool operator==(const Node& other) {
			return data == other.data;
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
		T data;
		Node* lChild;
		Node* rChild;
	};

	Node* head;
	
	
	void inOrderRec(Node* node) const {
		if (node) {
			inOrderRec(node->getL());
			node->print(cout);
			inOrderRec(node->getR());
		}
	}
	
};






//template <class T>
//ostream& operator<<(ostream& os, const Node<T>& node) {
//	node.print(os);
//	return os;
//}

#endif /* BinaryTree_hpp */
