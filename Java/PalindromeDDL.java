package Amazon;


public class PalindromeDDL {

	static class Node{
		Node next = null;
		Node back = null;
		int data;
		public Node(int data){
			this.data = data;
		}
		
		public Node(Node next, Node prev, int data) {
			// TODO Auto-generated constructor stub
			this.next = next;
			this.back = prev;
			this.data = data;
		}
	}

	private boolean isPalindrome(Node start){
		if(start == null)
			return false;
		
		if(start.next == null)
			return true;
		
		Node rearRunner = start; // from middle to back till start
		Node runner = start.next;
		Node frontRunner = runner; // from middle to end.
		while(runner.next != null){
			runner = runner.next;
			frontRunner = frontRunner.next;
			if(runner.next != null){
				runner = runner.next;
				rearRunner = rearRunner.next;
			}
		}
		boolean isPalindrome = true;
		
		while(frontRunner != null){
			if(rearRunner.data != frontRunner.data){
				isPalindrome = false;
				break;
			}else{
				rearRunner = rearRunner.back;
				frontRunner = frontRunner.next;
			}
		}
		
		return isPalindrome;
	}
	public static void main(String[] args) {
		PalindromeDDL p = new PalindromeDDL();
		Node head = new Node(5);
		head.next = new Node(4);
		head.next.next = new Node(5);
		head.next.next.next = new Node(4);
		
		
		System.out.println(p.isPalindrome(head));
		
		
	}
}
