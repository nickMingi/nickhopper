package practice;

public class LinkedList {

	private Node head;
	public Node tail;
	
	//inserting node
	public void insertNode(Node newNode){
		if(head == null){
			head = newNode;
			newNode.setNextNode(tail);
		}
		else{
			newNode.setNextNode(head.getNextNode());
			head.setNextNode(newNode);
		}
	}
	
	public void removeNode(Node rNode){
		Node tmpNode = head;
		while(tmpNode != null){
			
			if(tmpNode.getNextNode().getData() == rNode.getData()){
				tmpNode.setNextNode(tmpNode.getNextNode().getNextNode());
				break;
			}
			if(tmpNode == tail){
				System.out.println("There is no same data.");
				return;
			}
				tmpNode = tmpNode,getNextNode();
		}
	}
	
	public void printNode(){
		
		Node printNode = head;
		while(printNode != null){
			System.out.println(printNode.getData());
			printNode = printNode.getNextNode();
		}
	}
	
}

