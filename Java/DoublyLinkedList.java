package Amazon;

public class DoublyLinkedList {

	static DoublyLinkedList DLL = new DoublyLinkedList();
	
	public static void main(String[] args) {
		
	}
	
	private void isPalindrome(DoublyLinkedList dll){
		for(int i = 0; i < dll.getSize()/2; i++){
			if(dll.head.data == dll.tail.data){
				dll.head = dll.head.next;
				dll.tail = dll.tail.prev;
			}else{
				System.out.println("not a palindrome");
			}
		}
	}
	
	private void populateDLL(){
		DLL.addDataToFirst(4);
		DLL.addDataToFirst(5);
		DLL.addDataToLast(4);
		DLL.addDataToLast(5);
	}
	
	
}
