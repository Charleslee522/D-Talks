package main;

import node.Node;

public class main {

	public static void main(String[] args) {
		
		Node node = new Node(2);
		node.appendToTail(5);
		node.appendToTail(7);
		node.appendToTail(9);
		node.appendToTail(8);
		node.appendToTail(4);
		node.appendToTail(1);
		node.appendToTail(6);
		node.appendToTail(3);
		printAll(node);
		
		Node resultNode = splitListFrom(node, 4);
		
		printAll(resultNode);
	}

	private static void printAll(Node node)
	{
		while(node != null) {
			System.out.print(node.getData() + "->");
			node = node.next();
		}
		System.out.println("null");
	}
	
	static Node splitListFrom(Node node, int n)
	{
		Node n1 = null;
		Node n2 = null;
		while(node != null) {
			if(node.getData() < n) {
				if(n1 == null) {
					n1 = new Node(node.getData());
				} else {
					n1.appendToTail(node.getData());
				}
			} else {
				if(n2 == null) {
					n2 = new Node(node.getData());
				} else {
					n2.appendToTail(node.getData());
				}
			}
			node = node.next();
		}
		n1.appendToTail(n2);
		return n1;
	}
}
