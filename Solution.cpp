#include<iostream>
using namespace std;

struct node {
	int data;
	node* nextNode;
	node* previousNode;
	node() {
		data = 0;
		nextNode = NULL;
		previousNode = NULL;
	}
};

class doublyList {
private:
	node* listHead;
public:
	doublyList() {
		listHead = 0;
	}
	void insert(int data) {//it will insert data at the end of linked list
		if(listHead != NULL ) {
			node * tHead = listHead; // tempHead
			while (tHead->nextNode) { // untill tHead not NUll
				tHead = tHead->nextNode;
			}
			node *newNode = new node;
			newNode->data = data;
			tHead->nextNode= newNode;
			newNode->previousNode= tHead;
		}
		if (listHead == NULL) {
			listHead = new node;
			listHead->data = data;
		}
	}

	void printI() { // print with the help of next pointer
		cout << "\nList Data : ";
		node * tHead= listHead;
		
		while (tHead) {
			cout << tHead->data << " ";
			tHead = tHead->nextNode;
		}
	}
	node* getHead() {
		return listHead;
	}

	void RemoveAllBut(int key) {
		node* tHead = listHead; // temp head;
		node* tPreHead = NULL; // temp previous head
		for (int i = 0; tHead; i++) {
			if (key != tHead->data) {
				if (!tHead->previousNode || i == 0) { // i zero means we ant to delete first node
					node* tempNode = listHead;
					listHead = tempNode->nextNode;
					listHead->previousNode = NULL;
					delete tempNode; // delete first node
					tHead = listHead;
				}
				else if (!tHead->nextNode) { // delete last Node
					tPreHead->nextNode = NULL;
					delete tHead;
					tHead = tPreHead;
				}
				else {
					tPreHead->nextNode = tHead->nextNode;
					tHead->nextNode->previousNode = tPreHead;
					delete tHead;
					tHead = tPreHead;
				}
			}
			tPreHead = tHead;
			tHead = tHead->nextNode;
		}
	}
};


void concatenate(doublyList &l1, doublyList& l2){ 
	node* tHead = l2.getHead();
	if (l1.getHead() == NULL && l2.getHead() != NULL) {
		while (tHead) {
			l1.insert(tHead->data);
			tHead = tHead->nextNode;
		}
	}
	if (l1.getHead() != NULL && l2.getHead() != NULL) {
		while (tHead) {
			l1.insert(tHead->data);
			tHead = tHead->nextNode;
		}
	}
	return;

}

void main() {
	doublyList l1;
	l1.insert(10);
	l1.insert(30);
	l1.insert(30);
	l1.insert(40);
	cout << "\n------------------------>>> LIST 1 <<<------------------------";
	l1.printI();

	doublyList l2;
	l2.insert(20);
	l2.insert(20);
	l2.insert(30);
	l2.insert(30);
	cout << "\n\n------------------------>>> LIST 2 <<<------------------------";
	l2.printI();


	concatenate(l1, l2);
	cout << "\n\n------------------------>>> LIST 1 AFTER CONCATINATION <<<------------------------";
	l1.printI();

	l1.RemoveAllBut(30);
	l1.printI();

}