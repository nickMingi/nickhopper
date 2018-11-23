package Amazon;

public class TwoLinkedListNumbers {
	
	static class Node{
		public Node prev;
		public Node next;
		public int data;
		public Node(int d){
			this.data = d;
		}
	}

	public static void main(String[] args) {
		Node n1 = new Node(9);
		Node n2 = new Node(9);
		Node n3 = new Node(9);
		
		n1.next = n2;
		n2.next = n3;
		
		Node n4 = new Node(1);
		Node n5 = new Node(2);
		Node n6 = new Node(3);
		
		n4.next = n5;
		n5.next = n6;
		
		Node nr = MultiPly(n1, n4);
		Node cursor = nr;
		while(cursor != null){
			System.out.println(cursor.data);
			cursor = cursor.next;
		}
	}
	
	public static Node MultiPly(Node head1, Node head2){
		Node number1 = Reverse(head1);
		Node number2 = Reverse(head2);
		
		int ret;
		int carryout = 0;
		Node result = new Node(0);
		Node resultHead = result;
		Node resultCur = result;
		while(number2 != null){
			Node marker = number1;
			result = resultCur;
			carryout = 0;
			while(marker != null){
				ret = (marker.data * number2.data);
				result.data = ret + result.data + carryout;
				if(result.data > 9){
					carryout = result.data/10;
					result.data = result.data%10;
				}
				if(result.next == null){
					Node resultnext = new Node(0);
					result.next = resultnext;
				}
				result = result.next;
				marker = marker.next;
			}
			if(carryout > 0){
				result.data = carryout;
			}
			number2 = number2.next;
			resultCur = resultCur.next;
		}
		return Reverse(resultHead);
	}
	public static Node Reverse(Node head){
		Node cur = head;
		Node prev = null;
		Node next = null;
		
		while(cur != null){
			next = cur.next;
			cur.next = prev;
			prev = cur;
			cur = next;
		}
		return prev;
	}
}
