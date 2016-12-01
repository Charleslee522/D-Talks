//============================================================================
// Name        : 2_2_Reverse_kth_delete.cpp
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
	Node(int i) :  next_(0x0)
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
	Node * next_;
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
	if(node == 0x0) {
		cout << "node is null" << endl;
		return;
	}
	cout << node->getData() << ' ';
	Node* n = node->next();
	while(n != 0) {
		cout << n->getData() << ' ';
		n = n->next();
	}
	cout << endl;
}

// 2개의 포인터를 사용해서 찾는 알고리즘
Node * getReverseKthNode(Node * head, int k)
{
	if(head->next() == 0x0) {
		if(k == 0) {
			return head;
		} else {
			return 0x0;
		}
	}

	Node * n = head;
	for(int i = 0; i < k; ++i) {
		if(n->next() == 0x0) {
			return 0x0;
		}
		n = n->next();
	}

	Node * n2 = head;
	while(n->next() != 0x0) {
		n = n->next();
		n2 = n2->next();
	}
	return n2;
}

// 재귀 알고리즘
Node * getReverseKthNodeRecursive(Node * head, int k, int &i)
{
	if(head == 0x0) {
		return 0x0;
	}

	Node * n = getReverseKthNodeRecursive(head->next(), k, i);

	i = i + 1;
	if(i - 1 == k) {
		return head;
	}

	return n;

}

void func() {

	Node * head = new Node(0);
	head->appendToTail(1);
	head->appendToTail(2);
	head->appendToTail(3);
	head->appendToTail(3);
	head->appendToTail(3);
	head->appendToTail(4);
	head->appendToTail(4);
	head->appendToTail(5);
	head->appendToTail(1);

	cout << "Before!" << endl;
	printList(head);

	Node * node1 = getReverseKthNode(head, 3);
	printList(node1);

	Node * node2 = getReverseKthNode(head, 6);
	printList(node2);

	Node * node3 = getReverseKthNode(head, 0);
	printList(node3);

	Node * node4 = getReverseKthNode(head, 9);
	printList(node4);

	Node * head2 = new Node(0);
	head2->appendToTail(1);
	head2->appendToTail(2);

	cout << "Before!" << endl;
	printList(head2);

	int i = 0;
	Node * node5 = getReverseKthNodeRecursive(head2, 1, i);
	printList(node5);

	i = 0;
	Node * node6 = getReverseKthNodeRecursive(head2, 0, i);
	printList(node6);

	i = 0;
	Node * node7 = getReverseKthNodeRecursive(head2, 2, i);
	printList(node7);

//	i = 0;
//	Node * node6 = getReverseKthNodeRecursive(head2, 6, i);
//	printList(node6);
//
//	i = 0;
//	Node * node7 = getReverseKthNodeRecursive(head2, 0, i);
//	printList(node7);
//
//	i = 0;
//	Node * node8 = getReverseKthNodeRecursive(head2, 9, i);
//	printList(node8);


	cout << "After!" << endl;
	printList(head);

	return;
}

int main() {
	cout << "Hello World" << endl; // prints Hello World
	func();
	return 0;
}
