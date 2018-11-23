package Amazon;

import java.util.Arrays;

public class PossibilityOfNumbers {

	public static void main(String[] args) 
		throws java.lang.Exception{
		
		int[] arr1 = {5, 3, 15, 19, 6};
		int[] arr2 = {24, 34, 11, 13, 16};
		int[] arr3 = {91, 45, 57, 72, 100};
		
		Arrays.sort(arr1);
		Arrays.sort(arr2);
		Arrays.sort(arr3);
		
		int x = findPossibilityCount(arr1, arr2, arr3);
		System.out.println("Number of possibilities of sequence [x < y < z] is "+ x);
	}
	
	
	private static int smallestNumber(int[] anInput){
		int smallest = anInput[0];
		
		for(int i = 1; i < anInput.length; i++){
			if(smallest > anInput[i])
				smallest = anInput[i];
		}
		
		return smallest;
	}
	
	private static int findPossibilityCount(int[] arr1, int[] arr2, int[] arr3){
		int smallestArr2 = smallestNumber(arr2);
		int smallestArr3 = smallestNumber(arr3);
		
		int counter1 = 0, counter2 = 0;
		
		for(int i = 0; i < arr1.length; i++){
			if(arr1[i] < smallestArr2){
				counter1++;
			}else
				break;
		}
		
		for(int i = 0; i < arr2.length; i++){
			if(arr2[i] < smallestArr3){
				counter2++;
			}else
				break;
		}
		
		return counter1 * counter2 * arr3.length;
	}
}
