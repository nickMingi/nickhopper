package practice;

public class StackWithoutVector {

	private Object obj[];
	private int count;
	
	public StackWithoutVector() {
		// TODO Auto-generated constructor stub
		this.obj = new Object[100];
		this.count = 0;
	}
	
	public void pop(){
		this.obj[this.count] = null;
		this.count--;
	}
	
	public void push(Object num){
		this.obj[this.count] = num;
		this.count++;
		System.out.println(count);
	}
	
	public void print(){
		for(int i = 0; i < this.count; i++){
			System.out.println(this.obj[i]+" ");
		}
	}
	
	public static void main(String[] args) {
		StackWithoutVector s = new StackWithoutVector();
		s.push(3);
		s.push(5);
		s.pop();
		s.push(7);
		
	}
}
