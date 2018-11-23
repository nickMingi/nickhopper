package practice;
import java.util.*;


public class MissingNumber {

	public static void main(String[] args) {
		printMissingNumber(new int[]{0,1,2,4,6}, 7);
	}
	
	private static void printMissingNumber(int[] numbers, int count){
		int missingCount = count - numbers.length;
		BitSet bitSet = new BitSet(count);
		
		for(int number : numbers){
			if(numbers[0] == 0){
			bitSet.set(number);
			}else{
			bitSet.set(number-1);
			}
		}
		System.out.println("Missing numbers in Integer array "+Arrays.toString(numbers)+" with total number of "+count);
		int lastMissingIndex = 0;
		
		for (int i = 0; i < missingCount; i++){
			lastMissingIndex = bitSet.nextClearBit(lastMissingIndex);
			if(numbers[0] == 0){
				System.out.println(lastMissingIndex++);	
			}else{
				System.out.println(++lastMissingIndex);
			}
		}
		
	}
}
