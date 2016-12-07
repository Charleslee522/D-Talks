package node;

public class Node {
	private int data;
	private Node next;
	
	public Node(int data) {
		this.setData(data);
		this.setNext(null);
	}
	
	public void appendToTail(int data) {
		Node n = this;
		while(n.next() != null) {
			n = n.next;
		}
		n.setNext(new Node(data));
	}
	
	public void appendToTail(Node node) {
		Node n = this;
		while(n.next() != null) {
			n = n.next;
		}
		n.setNext(node);
	}

	public int getData() {
		return data;
	}

	public void setData(int data) {
		this.data = data;
	}

	public Node next() {
		return next;
	}

	public void setNext(Node next) {
		this.next = next;
	}
	
	public static Node appendToTail(Node head, int data) {
		Node ret = head;
		while(head.next() != null) {
			head = head.next();
		}
		head.setNext(new Node(data));
		return ret;
	}
}
