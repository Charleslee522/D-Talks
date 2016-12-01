//============================================================================
// Name        : 2_1_DeleteDuplicate.cpp
// Author      : Charles
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Node
{

public:
	Node(int i)
	{
		data_ = i;
	}

	void appendToTail(int data)
	{
		Node * node = new Node(data);
		Node *n = this;
		while(n->next_ != 0) {
			n = n->next_;
		}
		n->next_ = node;
	}

	void setNext(Node* node)
	{
		next_ = node;
	}

	Node * next() const
	{
		return next_;
	}

	int getData() const {
		return data_;
	}

private:
	Node * next_ = 0x0;
	int data_;

};


Node* deleteOneNode(Node* head, int d) {
	Node* n = head;
	if(n->getData() == d) {
		head = head->next();
		return head;
	}

	while((n != 0x0) && (n->next() != 0)) {
		if(n->next()->getData() == d) {
			n->setNext(n->next()->next());
			return head;
		}
		n = n->next();
	}
	return head;
}

Node* deleteAllNode(Node* head, int d) {
	while(head->getData() == d) {
		head = head->next();
	}
	Node* n = head;

	while((n != 0x0) && (n->next() != 0)) {
		if(n->next()->getData() == d) {
			n->setNext(n->next()->next());
			continue;
		}
		n = n->next();
	}
	return head;
}
void printList(const Node* node)
{
	cout << node->getData() << ' ';
	Node* n = node->next();
	while(n != 0) {
		cout << n->getData() << ' ';
		n = n->next();
	}
}

void deleteDuplicate(Node* node) {
	Node * n = node->next();
	while(n != 0x0) {

		n = node->next();
	}
}

void func() {

	Node * n0 = new Node(0);
	n0->appendToTail(1);
	n0->appendToTail(2);
	n0->appendToTail(3);
	n0->appendToTail(3);
	n0->appendToTail(3);
	n0->appendToTail(4);
	n0->appendToTail(4);
	n0->appendToTail(5);
	n0->appendToTail(1);

	cout << "Before!" << endl;
	printList(n0);
	cout << endl;

	n0 = deleteOneNode(n0, 2);
	n0 = deleteOneNode(n0, 1);
	n0 = deleteOneNode(n0, 4);
	n0 = deleteOneNode(n0, 0);
	n0 = deleteAllNode(n0, 3);

	cout << "Before!" << endl;
	printList(n0);
	cout << endl;

	deleteDuplicate(n0);

	cout << "After!" << endl;
	printList(n0);
	cout << endl;

	return;
}

int main() {
	cout << "Hello World" << endl; // prints Hello World
	func();
	return 0;
}
