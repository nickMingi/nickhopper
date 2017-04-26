package google;

import java.util.*;

public class BipartiteGraph {

	static class Node{
		int val;
		Set<Node> set;
		int tag;
		Node(int val){
			this.val = val;
			set = new HashSet<Node>();
			tag = -1;
		}
	}

	static void ProcessRelationList(int[][] relationList, HashSet<Node> set0, HashSet<Node> set1) throws Exception{
		HashMap<Integer, Node> map  = new HashMap<Integer, Node>();

		for (int i=0; i< relationList.length; i++){
			int rel1 = relationList[i][0];
			int rel2 = relationList[i][1];
			if (!map.containsKey(rel1)){
				map.put(rel1, new Node(rel1));
			}
			if (!map.containsKey(rel2)){
				map.put(rel2, new Node(rel2));
			}
			Node node1 = map.get(rel1);
			Node node2 = map.get(rel2);
			node1.set.add(node2);
			node2.set.add(node1);
		}

		Integer[] keyArr = map.keySet().toArray(new Integer[map.size()]);
		Queue<Node> q = new LinkedList<Node>();
		q.add(map.get(keyArr[0]));
		map.get(keyArr[0]).tag = 0;

		while(!q.isEmpty()){
			Node node = q.remove();
			int childTag = (node.tag+1)%2;
			if (node.tag == 0){
				set0.add(node);
			}else if (node.tag == 1){
				set1.add(node);
			}
			for (Node child: node.set){
				child.set.remove(node);
				if (child.tag == -1){
					child.tag = childTag;
				}else if (child.tag!= childTag){
					throw new Exception("Parent " + node.val + "'s Child " + child.val + " is in " + child.tag + " Retrying in :" + childTag);
				}
				q.add(child);
			}
			node.set.clear();
		}
	}

	static void PrintSet(HashSet<Node> set1,HashSet<Node> set2){
		Node[] arr1 = set1.toArray(new Node[set1.size()]);
		Node[] arr2 = set2.toArray(new Node[set2.size()]);
		System.out.print("Set1 : ");
		for (int i=0; i< arr1.length; i++){
			System.out.print(arr1[i].val + ((i==arr1.length-1)?(""):(", ")));
		}
		System.out.print("   Set2 : ");
		for (int i=0; i< arr2.length; i++){
			System.out.print(arr2[i].val + ((i==arr2.length-1)?(""):(", ")));
		}
		System.out.println();
	}

	public static void main(String[] args){
		HashSet<Node> set1 = new HashSet<Node>();
		HashSet<Node> set2 = new HashSet<Node>();
		int[][] relationList;

		set1.clear();
		set2.clear();
		relationList = new int[][] {{1,2}, {2,3}, {3,4}};
		try {
			ProcessRelationList(relationList, set1, set2);
			PrintSet(set1, set2);
		} catch (Exception e) {
			System.out.println("Exception : " + e.getMessage());
		}

		set1.clear();
		set2.clear();
		relationList = new int[][] {{1,2}, {1,3}, {2,3}, {3,4}};
		try {
			ProcessRelationList(relationList, set1, set2);
			PrintSet(set1, set2);
		} catch (Exception e) {
			System.out.println("Exception : " + e.getMessage());
		}
	}
}
