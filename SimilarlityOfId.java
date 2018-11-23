package facebook;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map.Entry;

public class SimilarlityOfId {

	public static void main(String[] args) {
		String a [] = {"tasneem@gmail.com","tas@hotmail.com","abc@gmail.com","abc@hotmail.com","apc@yahoo.com"};
		HashMap<Integer, ArrayList<String>> similarElementsMap = new HashMap<>();
		for(int i = 0; i < a.length - 1; i ++){
			int d = distance(a[i],a[i+1]);
			if(similarElementsMap.containsKey(d)){
				ArrayList<String> list = similarElementsMap.get(d);
				list.add(a[i]);
				list.add(a[i+1]);
			}else{
				ArrayList<String> list = new ArrayList<>();
				list.add(a[i]);
				list.add(a[i+1]);
				similarElementsMap.put(d, list);
			}
		}
		
		for(Entry<Integer, ArrayList<String>> map : similarElementsMap.entrySet() ){
			System.out.println("For distance : " + map.getKey());
			for(int i = 0; i < map.getValue().size(); i++ ){
				System.out.println(map.getValue().get(i));
			}
		}
	}
	
	private static int distance(String a, String b){
		
		a = a.substring(0, a.indexOf('@')).toLowerCase();
		b = b.substring(0, b.indexOf('@')).toLowerCase();
		// base case
		if (a.length() == 0) return b.length();
		if (b.length() == 0) return a.length();
		
		int cost[] = new int[b.length() + 1];
		// Initialise cost with each indexes initialy
		for(int i = 0; i < b.length(); i++){
			cost[i] = i;
		}
		
		// Iterate through a and b string and update cost array with each a iteration
		for(int i = 1; i <= a.length(); i ++){
			cost[0] = i;
			int k = i - 1;
			for(int j = 1; j <= b.length(); j ++){
				int c = Math.min(1 + Math.min(cost[j], cost[j-1]), a.charAt(i-1)==b.charAt(j-1) ? k : k + 1);
				// Swap the min value with cost and k
				k = cost[j];
				cost[j] = c;
			}
		}
		return cost[b.length()];
	}
}
