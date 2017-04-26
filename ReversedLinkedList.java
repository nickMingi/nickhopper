package Amazon;

public class ReversedLinkedList {

	int value;
	ReversedLinkedList next = null;
	
	public ReversedLinkedList(int i) {
		// TODO Auto-generated constructor stub
		this.value = i;
	}
	
	public ReversedLinkedList addNode(int i){
		this.next = new ReversedLinkedList(i);
		return next;
	}
	
	public ReversedLinkedList getNext(){
		return next;
	}
	
	public String toString(){
		String restElement = value + "->";
		ReversedLinkedList newNext = getNext();
		while(newNext != null){
			restElement = restElement + newNext.value + "->";
			newNext = newNext.getNext();
		}
		restElement = restElement + newNext;
		return restElement;
	}
	
	public static void main(String[] args) {
		ReversedLinkedList headnode = new ReversedLinkedList(1);
		headnode.addNode(2).addNode(3);
		
		System.out.println(headnode);
		headnode = reverse(null, headnode, headnode.getNext());
		
		System.out.println(headnode);
	}
	
	private static ReversedLinkedList reverse(ReversedLinkedList prev,
			ReversedLinkedList current, ReversedLinkedList next){
		current.setNext(prev);
		if(next == null)
			return current;
		return reverse(current,next,next.getNext());
	}
	
	private void setNext(ReversedLinkedList prev){
		this.next = prev;
	}
	
}
