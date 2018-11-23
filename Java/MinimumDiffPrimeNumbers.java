package Amazon;

import java.util.Arrays;
import java.util.TreeMap;

public class MinimumDiffPrimeNumbers {

	public static void main(String[] args) {
		int[] numbers = {101, -113, 1, 45, 78, -2, -3, 7};
		new MinimumDiffPrimeNumbers().findPrimes(numbers);
	}
	
	private int[] findPrimes(int[] numbers){
		int[] returnArray = new int[2];
		TreeMap<Integer, Integer> map = new TreeMap<Integer, Integer>();
		
		for(int i = 0; i < numbers.length; i++){
			if(isPrime(numbers[i]))
				map.put(numbers[i], numbers[i]);
		}
		
		returnArray[0] = map.firstKey().intValue();
		returnArray[1] = map.lastKey().intValue();
		System.out.println(Arrays.toString(returnArray));
		return returnArray;
	}
	
	private boolean isPrime(int n){
		
		if(n<0)
			n = 0 - n; // just convert n to positive for simplicity
		for(int i = 2; i < n/2; i++){
			if(n%i == 0)
				return false;
		}
		
		return true;
	}
}
