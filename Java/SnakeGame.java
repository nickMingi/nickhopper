package google;

import java.util.*;

public class SnakeGame {

	int[][] grid;
	DoublyLinkedList dll;
	
	public static void main(String[] args) {
		SnakeGame sg = new SnakeGame(3);
		
	}
	
	public SnakeGame(int bounds){
		grid = new int[bounds][bounds];
		dll = new DoublyLinkedList();
		play();
	}
	
	public void play(){
		startingPoint();
		placeFood();
		printGrid();
		while(true){
			try{
				getMove();
				printGrid();
			}catch(GameOverException e){
				System.out.println(e.getMessage());
				return;
			}
		}
	}
	
	public void getMove() throws GameOverException{
		Scanner sc = new Scanner(System.in);
		String input = sc.next();
		int currentRow = dll.head.position[0];
		int currentCol = dll.head.position[1];
		if(input.equals("w")){
			currentRow--;
		}else if(input.equals("a")){
			currentCol--;
		}else if(input.equals("s")){
			currentRow++;
		}else if(input.equals("d")){
			currentCol++;
		}else{
			getMove();
			return;
		}
		if(currentCol < 0 || currentCol == grid.length || currentRow < 0 ||
				currentRow == grid.length)
		{ throw new GameOverException("You hit a wall");
		}else if(grid[currentRow][currentCol] == 1) throw new GameOverException("You ate yourself");
		else if(grid[currentRow][currentCol] == 7){
			dll.addFront(currentRow, currentCol);
			if(dll.size == grid.length*grid.length) throw new GameOverException("You won!");
			placeFood();
		}else{
			dll.addFront(currentRow, currentCol);
			dll.removeTail();
		}
	}
	
	public int[] getRandomPosition(){
		Random r = new Random();
		int row, col;
		do{
			row = r.nextInt(grid.length);
			col = r.nextInt(grid.length);
		}while(grid[row][col] != 0);
		int[] result = {row, col};
		return result;
	}
	
	public void startingPoint(){
		int[] position = getRandomPosition();
		dll.addFront(position[0], position[1]);
		grid[position[0]][position[1]] = 1;
	}
	
	public void placeFood(){
		int[] position = getRandomPosition();
		grid[position[0]][position[1]] = 7;
	}
	
	public void printGrid(){
		for(int i = 0; i < grid.length; i++){
			System.out.println(Arrays.toString(grid[i]));
		}
	}
	
	public class DoublyLinkedList{
		Node head, tail;
		int size = 0;
		public DoublyLinkedList(){
			head = null; tail = null;
		}
		public void addFront(int row, int col){
			if(head == null && tail == null){
				head = tail = new Node(null, row, col, null);
			}else if(head == tail){
				head = new Node(null, row, col, tail);
				tail.prev = head;
			}else{
				head = new Node(null, row, col, head);
				head.next.prev = head;
			}
			grid[row][col] = 1;
			size++;
		}
		public void removeTail(){
			if(tail == null){
				return;
			}else if(head == tail){
				grid[tail.position[0]][tail.position[1]] = 0;
				head = tail = null;
			}else{
				grid[tail.position[0]][tail.position[1]] = 0;
				tail = tail.prev;
				tail.next = null;
			}
			size--;
		}
	}
	public class Node{
		int[] position;
		Node next;
		Node prev;
		public Node(Node prev, int row, int col, Node next){
			int[] pos = {row, col};
			position = pos;
			this.next = next;
			this.prev = prev;
		}
	}
	public class GameOverException extends Exception{
		public GameOverException(String message){
			super(message);
		}
	}
}
