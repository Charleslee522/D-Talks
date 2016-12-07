package main;

import node.Node;

public class DeleteMid {

	public static void main(String[] args) {
		Node node = new Node(1);
		node.appendToTail(2);
		node.appendToTail(3);
		node.appendToTail(4);
		Node targetNode = new Node(5);
		node.appendToTail(targetNode);
		node.appendToTail(6);
		node.appendToTail(7);
		node.appendToTail(8);
		node.appendToTail(9);

		printAll(node);
		
		deleteTargetNode(targetNode);
		
		printAll(node);
	}

	private static void deleteTargetNode(Node targetNode) {
		Node next = targetNode.next();
		targetNode.setData(next.getData());
		targetNode.setNext(next.next());
		next = null;
	}

	private static void printAll(Node node) {
		while(node != null) {
			System.out.print(node.getData() + "->");
			node = node.next();
		}
		System.out.println("null");
	}

}
