//============================================================================
// Name        : 2_0_LinkedList.cpp
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
	Node(int i) : next_(0x0)
	{
		data_ = i;
	}

	void appendToTail(Node * node)
	{
		if(next_ == 0x0) {
			next_ = node;
		} else {
			Node * tmpNext = next_;
			while(tmpNext->next() != 0x0) {
				tmpNext = tmpNext->next();
			}
			tmpNext->setNext(node);
		}
	}

	void appendToTail(int data)
	{
		Node * node = new Node(data);
		this->appendToTail(node);
	}

	void setNext(Node* node)
	{
		next_ = node;
	}

	Node * next()
	{
		return next_;
	}

	int getData() {
		return data_;
	}

private:
	Node * next_;
	int data_;

};

void func() {

	Node n0(0);
	Node n1(1);
	Node n2(2);
	n0.appendToTail(&n1);
	n0.appendToTail(&n2);
	n0.appendToTail(3);

	return;
}

int main() {
	cout << "Hello World" << endl; // prints Hello World
	func();
	return 0;
}
