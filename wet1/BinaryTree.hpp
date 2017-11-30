////
////  BinaryTree.hpp
////
////
////  Created by Ben on 30/11/2017.
////
//
//#ifndef BinaryTree_hpp
//#define BinaryTree_hpp
//
//#include <stdio.h>
//#include <iostream>
//#include <assert.h>
//
//using std::cout;
//using std::ostream;
//
//
//template <class T>
//class BinaryTree {
//public:
//	BinaryTree(): head(NULL) {}
//
//	~BinaryTree() {
//		inOrderRecDestroy(head);
//	}
//
//
//
//	bool find(const T& val) {
//		if (!head) {
//			return false;
//		} else {
//			Node* currNode = head;
//			while (1) {
//				if ( (*(*currNode).data) == val ) return true;
//				if ( val< (*(*currNode).data)) {
//					if ( (*currNode).lChild) {
//						currNode = currNode->lChild;
//					} else {
//						return false;
//					}
//				} else {
//					if ((*currNode).rChild) {
//						currNode = currNode->rChild;
//					} else {
//						return false;
//					}
//				}
//			}
//		}
//	}
//
//	bool insert(T* val) {
//		if (find(*val)) return false;
//		Node* newNode = new Node(val);
//		if (!head) {
//			head=newNode;
//			return true;
//		} else {
//			Node* currNode = head;
//			while (1) {
//				if (*val < (*(*currNode).data)) {
//					if ((*currNode).lChild) {
//						currNode = currNode->lChild;
//					} else {
//						(currNode->lChild = newNode);
//						return true;
//					}
//				} else {
//					if ((*currNode).rChild ) {
//						currNode = currNode->rChild;
//					} else {
//						(currNode->rChild = newNode);
//						return true;
//					}
//				}
//			}
//		}
//		assert(false);
//		return false;
//	}
//
//	void inOrder(){
//		inOrderRecPrint(head);
//	}
//
//
//
//
//private:
//	Node* head;
//
//	struct Node {
//
//		Node(T* data): data(data), lChild(NULL), rChild(NULL) {}
//
//		ostream& print(ostream& os) const {
//			os << "---------" << std::endl;
//			os << "address: " << this << std::endl;
//			os << "data: " << *data << std::endl;
//			os << "lchild: " << lChild << std::endl;
//			os << "lchild: " << rChild << std::endl;
//			return os;
//		}
//
//		bool operator<(const Node& other) {
//			return *data < *other.data;
//		}
//
//		bool operator==(const Node& other) {
//			return *data == *other.data;
//		}
//
//		T* data;
//		Node* lChild;
//		Node* rChild;
//	};
//
//	void inOrderRecDestroy(Node* node) const {
//		if (node) {
//			inOrderRecDestroy(node->lChild);
//			inOrderRecDestroy(node->rChild);
//			delete node->data;
//			delete node;
//		}
//	}
//
//	void inOrderRecPrint(Node* node) const {
//		if (node) {
//			inOrderRecPrint(node->lChild);
//			node->print(cout);
//			inOrderRecPrint(node->rChild);
//		}
//	}
//
//};
//
//
//#endif /* BinaryTree_hpp */

