package google;

import java.util.ArrayList;
import java.util.HashMap;

public class PrintBinaryTree {

	static class Node{
		Character c;
		Node l,r;
		Node(Character c){
			this.c = c;
			this.l = null;
			this.r = null;
		}
	}
	
	static String GetStringForHyphen(int count){
		String hyphenString = "";
		for (int i = 0; i < count; i++){
			hyphenString="-";
		}
		return hyphenString;
	}
	
	static void PrintTree(Node head, int hyphenCnt, int minHyphenCnt, ArrayList<Node> q, HashMap<Node, Integer> map){
		map.put(head, hyphenCnt);
		q.add(head);
		
		if(head.r == null && head.l == null){
			for(int i = 0; i < q.size(); i++){
				Node n = q.get(i);
				String hyphenStr = GetStringForHyphen(map.get(n) - minHyphenCnt);
				System.out.println(hyphenStr + n.c);
			}
			System.out.println("");
			q.remove(q.size()-1);
			return;
		}
		if(head.l != null){
			PrintTree(head.l, hyphenCnt-1, Integer.min(minHyphenCnt, hyphenCnt-1), q, map);
		}
		if(head.r != null){
			PrintTree(head.r, hyphenCnt+1, Integer.min(minHyphenCnt, hyphenCnt+1), q, map);
		}
		q.remove(q.size()-1);
	}
	
	public static void main(String[] args) {
		Node head = new Node('A');
		head.l = new Node('B');
		head.r = new Node('C');
		
		head.l.l = new Node('D');
		
		head.l.r = new Node('E');
		head.r.l = new Node('F');
		head.r.r = new Node('G');
		
		head.l.l.l = new Node('H');
		head.l.l.r = new Node('I');
		head.l.r.l = new Node('J');
		head.l.r.r = new Node('K');
		head.l.r.r.l = new Node('P');
		head.l.r.r.l.l = new Node('Q');
		head.l.r.r.l.l.l = new Node('R');
		head.l.r.r.l.l.l.l = new Node('S');
		
		head.r.l.l = new Node('L');
		head.r.l.r = new Node('M');
		head.r.r.l = new Node('N');
		head.r.r.r = new Node('O');
		
		ArrayList<Node> stack = new ArrayList<Node>();
		PrintTree(head, 0, 0, stack, new HashMap<Node, Integer>());
	}
}
