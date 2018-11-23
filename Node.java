package practice;

public class Node {

	private Object data;
	private Node next;
	
	public Node(Object data) {
		// TODO Auto-generated constructor stub
		this.data = data;
		this.next = null;
	}
	
	public void setNextNode(Node node){
		this.next = node;
	}
	
	public void setData(Object data){
		this.data = data;
	}
	
	public Object getData(){
		return this.data;
	}
	
	public static void main(String[] args) {
		LinkedList list = new LinkedList();
		
		int i =0;
		while(i <= 5){
			list.insertNode(new Node(i));
			i++;
		}
		System.out.println("End");
		
		list.removeNode(new Node(1));
		list.printNode();
	}
}
