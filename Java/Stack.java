package practice;
import java.util.*;
import java.util.EmptyStackException;

public class Stack extends Vector {
	
	private Object push(Object item) {
		// TODO Auto-generated method stub
		addElement(item);
		return item;
	}
	
	private Object pop() {
		// TODO Auto-generated method stub
		Object obj = peek();
		removeElementAt(size()-1);
		return obj;
	}
	
	private Object peek() {
		// TODO Auto-generated method stub
		int len = size();
		
		if(len == 0){
			throw new EmptyStackException();
		}
		return elementAt(len-1);
	}
	
	private boolean empty() {
		// TODO Auto-generated method stub
		return size() == 0;
	}
	
	private int search(Object o) {
		// TODO Auto-generated method stub
		int i = lastIndexOf(o);
		if(i >= 0){
			return size()-i;
		}
		return -1;
	}
	
	public static void main(String[] args) {
		Stack s = new Stack();
		s.push(1);
		s.push(2);
		s.pop();
		s.push(3);
		
		
		System.out.println(s);
		System.out.println(s.peek());
		System.out.println(s.empty());
		System.out.println(s.search(0));
	}
}
