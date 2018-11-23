package google;

import java.util.HashMap;
import java.util.Map;

public class TestSquare {

	public void testSquare( int a, int b){
		int max = Math.max(a, b);
		int min = Math.min(a, b);
		int number = 0;
		Map<String, Integer> squarePerSize = new HashMap<>();
		while(max > 0 && min > 0){
			int less = max - min;
			String key = min + "x" + min;
			Integer j =squarePerSize.getOrDefault(key, 0); 
			squarePerSize.put(key,j+1);
			max = Math.max(min, less);
			min = Math.min(min, less);
			number++;
		}
		for(Map.Entry<String, Integer> stringIntegerEntry : squarePerSize.entrySet())
		{
			System.out.println(stringIntegerEntry.getKey() + ":" + stringIntegerEntry.getValue());
		}
		System.out.println("total:" + number);
	}
	
	public static void main(String[] args) {
		TestSquare t = new TestSquare();
		t.testSquare(4, 5);
	}
	
}
