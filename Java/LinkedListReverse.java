package Amazon;

public class LinkedListReverse {

	class LinkedListNode{
		int data;
		LinkedListNode next;
	}
	
	public LinkedListNode reverse(LinkedListNode head){
		if(head == null){
			return head;
		}
		LinkedListNode previous = null;
		LinkedListNode current = head;
		while(current != null){
			LinkedListNode t = current.next;
			current.next = previous;
			previous = current;
			current = t;
		}
		return previous;
	}
	
	public static void main(String[] args) {
		
	}
}
