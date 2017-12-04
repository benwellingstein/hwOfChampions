

//todo splay on delete/insert?

#ifndef SplayTree_hpp
#define SplayTree_hpp

#include <stdio.h>
#include <iostream>
#include <assert.h>

using std::cout;
using std::ostream;
using std::endl;

template <class T, class UpdateFunction>
class SplayTree {
    
private:
    struct Node;
    
public:
	SplayTree(Node* root = NULL): head(root), top(NULL) {}
	
	~SplayTree() {
		inOrderRecDestroy(head);
		head = NULL;
		top = NULL;
	}
	
	bool exist(const T& val) const {
		if (!head) return false;
		
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
    
    bool remove(const T& val) {
        if(!exist(val)) return false;
        splay(val);
		if (!head->lChild && !head->rChild) {
			delete head->data;
			delete head;
			head = NULL;
			top = NULL;
			return true;
		}
		if (!head->lChild) {
			Node* oldHead = head;
			head = head->rChild;
			head->father = NULL;
			delete oldHead->data;
			delete oldHead;
		} else
			if (!head->rChild) {
				Node* oldHead = head;
				head = head->lChild;
				head->father = NULL;
				delete oldHead->data;
				delete oldHead;
			} else {
				Node* lMax = findMax(head->lChild);
				SplayTree tempTree(head->lChild);
				
				tempTree.head->father = NULL;
				tempTree.splay(*(lMax->data));
				Node* oldHead = head;
				head = tempTree.head;
				head->rChild = oldHead->rChild;
				head->father = NULL;
				delete oldHead->data;
				delete oldHead;
				head->rChild->father = head;
				tempTree.head = NULL;
		}
		top = findMax(head);
		return true;
    }
	
	
	bool insert(T* val) {
		Node* newNode = new Node(val);
		if (!head) {
			head = newNode;
			top = head;
			return true;
		}
		if(exist(*val)) return false;
		find(*val);
		if( *val < *(head->data) ) {
			Node* oldHead = head;
			newNode->rChild = oldHead;
			newNode->lChild = oldHead->lChild;
			oldHead->father = newNode;

			if (oldHead->lChild) {
				oldHead->lChild->father = newNode;
				oldHead->lChild = NULL;
			}
			newNode->father = NULL;
			head = newNode;

		} else {
			Node* oldHead = head;
			newNode->lChild = oldHead;
			newNode->rChild = oldHead->rChild;
			oldHead->father = newNode;
			
			if (oldHead->rChild) {
				oldHead->rChild->father = newNode;
				oldHead->rChild = NULL;
			}
			
			head = newNode;
			if (top && *(top->data) < *val) top = newNode;

		}

		return true;
	}
	
	T* getTop() {
		if (!top) return NULL;
		return top->data;
	}
	
	
	static Node* findMax(Node* top) {
        if(top == NULL) return NULL;
        Node* current = top;
        Node* next = current->rChild;
        while(next != NULL) {
            current = next;
            next = current->rChild;
        }
        return current;
    }
    
	T* find(const T& val) {
		if (!head)  return NULL;
        Node* current = head;
        Node* next = findNext(current, val);
        while(next != NULL && current != next) {
            current = next;
            next = findNext(current, val);
        }
        splay(*(current->data));
		
		//TODO danger?
        if (next != NULL) {
            return current->data;
        }
		
        return NULL;
	}

	bool insertBT(T* val) {
		if (exist(*val)) return false;
		if (!head) {
            Node* newNode = new Node(val, NULL);
			head=newNode;
			return true;
		} else {
			Node* currNode = head;
			while (1) {
				if (*val < (*(*currNode).data)) {
					if ((*currNode).lChild) {
						currNode = currNode->lChild;
					} else {
                        Node* newNode = new Node(val, currNode);
						(currNode->lChild = newNode);
						return true;
					}
				} else {
					if ((*currNode).rChild ) {
						currNode = currNode->rChild;
					} else {
                        Node* newNode = new Node(val, currNode);
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
        if (!exist(val)) return;
        Node* current = head;
        Node* father = NULL;
        Node* grandFather = NULL;
        Node* greatGrandFather = NULL;
        while( *(current->data) != val ) {
            greatGrandFather = grandFather;
            grandFather = father;
            father = current;
            current = findNext(current, val);
        }
        if(grandFather != NULL) {
            //case3
            Node** pGrandFather = NULL;
            do{
                if (grandFather->father == NULL) {
                    pGrandFather = &head;
                } else {
                    pGrandFather = findDirection(greatGrandFather, grandFather);
                }
                
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
				
				//TODO Greatgrandfather updating?
                father = current->father;
                if(father != NULL) {
                    grandFather = father->father;
					if (grandFather != NULL) {
						greatGrandFather = grandFather->father;
					}
                }
            } while ( current != head && current->father != head );
        }
        //case2
        if(head != current) {
            if (*(father->data) < val)  {
                ZigR(&head, father, current);
                return;
            } else {
                ZigL(&head, father, current);
                return;
            }
        }
    }
	
	
	
	void exportArr(T** arr) {
		int i = 0;
		recursiveFill(arr, head, &i);
	}
    
    static void recursiveFill(T** arr, Node* node, int* i) {
        if (node) {
            recursiveFill(arr, node->lChild, i);
            //cout << *i << endl;
            arr[*i] = node->data;
            *i = *i + 1 ;
            recursiveFill(arr, node->rChild, i);
        }
    }
	
	int size() {
		return countNodes(head);
	}
    
    static int countNodes(Node* node) {
        int count = 0;
        if (node) {
            count ++;
            count += countNodes(node->lChild);
            count += countNodes(node->rChild);
        }
        return count;
    }
    

	
//	static int recursiveFill(int **gladiators,Node* node) {
//		if (node) {
//			int i = recursiveFill(gladiators, node->lChild);
//
//			recursiveFill(gladiators, node->lChild, i+1 );
//
//		}
//	}

//	static int recursiveFill(int **gladiators,Node* node) {
//		int count = 0;
//		if (node) {
//			count += countNodes(node->lChild);
//			*gladiators[i] = node->data;
//			count ++;
//
//			count += countNodes(node->rChild);
//		}
//		return count;
//	}
	
	

	
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
	
	
	
	void update(UpdateFunction updateFunction) {
		int arraySize = size();
		T** arrOriginal = new T*[arraySize + 1]();
		T** arrChanged = new T*[arraySize + 1]();
		T** arrNotChanged = new T*[arraySize + 1]();
		T** arrFinal = new T*[arraySize + 1]();

		for (int i = 0; i < arraySize; i++) {
			arrOriginal[i] = NULL;
			arrChanged[i] = NULL;
			arrNotChanged[i] = NULL;
			arrFinal[i] = NULL;
		}
		
		getData(arrOriginal);
		runFunction(arrOriginal, arrChanged, arrNotChanged, updateFunction);
		mergeSortArrays(arrChanged, arrNotChanged, arrFinal);
		inOrderRecDestroy(head);
		head = NULL;
		top = NULL;
		buildTreeFromArray(head, arrFinal);
		delete [] arrOriginal;
		delete [] arrChanged;
		delete [] arrNotChanged;
		delete [] arrFinal;
	}
	
	

private:
	void getData(T** arrOriginal) {
		int i=0;
		getDataRec(arrOriginal, head, &i);
	}


	static void getDataRec(T** arr, Node* node, int* i) {
		if (node) {
			getDataRec(arr, node->lChild, i);
			//cout << *i << endl;
			arr[*i] = new T(*(node->data));
			*i = *i + 1 ;
			getDataRec(arr, node->rChild, i);
		}
	}
	
	
	//splits original into two arrays
	void runFunction(T** arrOriginal, T** arrChanged,T**  arrNotChanged,
					 UpdateFunction updateFunction) {
		int i = 0;
		int j = 0;
		for (int k = 0; arrOriginal[k] != NULL; ++k) {
			if (updateFunction(*arrOriginal[k]))  {
				arrChanged[i] = arrOriginal[k];
				i++;
			} else {
				arrNotChanged[j] = arrOriginal[k];
				j++;
			}
		}
	}
	
	void mergeSortArrays(T** arrChanged, T** arrNotChanged, T** arrFinal) {
		int i = 0;
		int j = 0;
		int k = 0;
		while (arrChanged[i] && arrNotChanged[j]) {
			if (*arrChanged[i]< * arrNotChanged[j]) {
				arrFinal[k] = arrChanged[i];
				i++;
			} else {
				arrFinal[k] = arrNotChanged[j];
				j++;
			}
			k++;
		}
		while (arrChanged[i]) {
			arrFinal[k] = arrChanged[i];
			i++;
			k++;
		}
		while (arrNotChanged[j]) {
			arrFinal[k] = arrNotChanged[j];
			j++;
			k++;
		}
	}

	
	
	void buildTreeFromArray(Node* head, T** arrFinal) {
		for (int i = 0; arrFinal[i]; ++i ) {
			insert(arrFinal[i]);
		}
	}

	
	
	
	

	
	enum Order { LL, LR, RL, RR} ;
	
	struct Node {
		
		Node(T* data, Node* father = NULL, Node* left = NULL, Node* right = NULL): data(data), father(father), lChild(left), rChild(right) {}
		
		ostream& print(ostream& os) const {
//			os << "---------" << std::endl;
//			os << "address: " << this << std::endl;
			os  << *data << " ";
//			os << "lchild: " << lChild << std::endl;
//			os << "lchild: " << rChild << std::endl;
			return os;
		}
		
		bool operator<(const Node& other) const {
			return *data < *other.data;
		}
		
		bool operator==(const Node& other) const {
			return *data == *other.data;
		}
		
		bool operator!=(const Node& other) const {
			return !(this == other);
		}
		
		T* data;
        Node* father;
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
	
	
	Node* findNext(Node* checkAgainst, const T& val) const {
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
        child->father = NULL;
        father->father = child;
	}
	
	static void ZigR(Node** grandFather, Node* father, Node* child ) {
		*grandFather = child;
		father->rChild = child->lChild;
		child->lChild = father;
        child->father = NULL;
        father->father = child;
	}
	
	static void ZigZagLR(Node** greatGrandFather, Node* grandFather, Node* father, Node* child) {
		*greatGrandFather = child;
		father->rChild = child->lChild;
		grandFather->lChild = child->rChild;
		child->lChild = father;
		child->rChild = grandFather;
        child->father = grandFather->father;
        grandFather->father = child;
        father->father = child;
	}

	static void ZigZagRL(Node** greatGrandFather, Node* grandFather, Node* father, Node* child) {
		*greatGrandFather = child;
		father->lChild = child->rChild;
		grandFather->rChild = child->lChild;
		child->rChild = father;
		child->lChild = grandFather;
        child->father = grandFather->father;
        grandFather->father = child;
        father->father = child;
	}

	static void ZigZigRR(Node** greatGrandFather, Node* grandFather,
						  Node* father, Node* child) {
		*greatGrandFather = child;
		grandFather->rChild = father->lChild;
		father->rChild = child->lChild;
		child->lChild = father;
		father->lChild = grandFather;
        child->father = grandFather->father;
        grandFather->father = father;
        father->father = child;

	}
	
	static void ZigZigLL(Node** greatGrandFather, Node* grandFather,
						  Node* father, Node* child) {
		*greatGrandFather = child;
		grandFather->lChild = father->rChild;
		father->lChild = child->rChild;
		child->rChild = father;
		father->rChild = grandFather;
        child->father = grandFather->father;
        grandFather->father = father;
        father->father = child;
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
	Node* top;
	
};



#endif /* SplayTree_hpp */







