package practice;

public class Queue {
	private Object obj[];
	private int tail;
	private int head;
	// queue constructor
	public Queue() {
		// TODO Auto-generated constructor stub
		this.obj = new Object[200];
		this.tail = 1;
		this.head = 0;
	}
	// queue is FIFO
	public void pop(){
		// If head == tail , there is no number
		if(this.head == this.tail || this.tail ==1){
			System.out.println("No space to pop");
		}else{
			this.obj[this.head] = null; 
			this.head++;
			System.out.println("head = "+head+" tail = "+tail);
			
		}
	}
	
	public void push(int num){
		this.obj[this.tail] = num; // insert into tail of queue
		this.tail++;
		System.out.println("head = "+head+" tail = "+tail);
	}
	
	public void print(){
		int count;
		System.out.println("Queue value = ");
		for(count = this.head; count < this.tail; count++){
			System.out.println(this.obj[count] + ",");
		}
	}
	
	public static void main(String[] args) {
		Queue q = new Queue();
		q.push(3);
		q.push(4);
		q.pop();
		q.push(6);
		q.push(8);
		q.pop();
		q.print();
	}
}
