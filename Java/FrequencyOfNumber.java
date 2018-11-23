package Amazon;

import java.util.Arrays;

public class FrequencyOfNumber {

	//Time Complexity O (logn)
	public int searchFirstOccurrence(int a[], int target){
		int low = 0;
		int high = a.length - 1;
		int result = -1;
		
		while(low <= high){
			int mid = ( high + low ) / 2;
			
			if(target == a[mid]){
				result = mid;
				high = mid - 1;
			}else if(target > a[mid]){
				low = mid + 1;
			}else{
				high = mid - 1;
			}
		}
		
		return result;
	}
	
	// Time Complexity O(logn)
	public int searchLastOccurrence(int a[], int target){
		int low = 0;
		int high = a.length - 1;
		int result = -1;
		
		while (low <= high){
			int mid = (high + low) / 2;
			if(target == a[mid]){
				result = mid;
				low = mid + 1;
			}else if(target > a[mid]){
				low = mid + 1;
			}else{
				high = mid - 1;
			}
		}
		
		return result;
	}
	
	// Time Complexity O(logn)
	public int countOccurrence(int a[], int target){
		return searchLastOccurrence(a, target) - searchFirstOccurrence(a, target) + 1;
	}
	
	public static void main(String[] args) {
		FrequencyOfNumber f = new FrequencyOfNumber();
		int b[] = {2,2,2,4,2,2,10,4,4,4,10,2,10,18,18,20,18,20,20,20};
		Arrays.sort(b);
		System.out.println(Arrays.toString(b));
		
		System.out.println("First occurrence of 10: " + f.searchFirstOccurrence(b, 10));
		System.out.println("Last occurrence of 10: " + f.searchLastOccurrence(b, 10));
		System.out.println("Count total occurrence of 10: " + f.countOccurrence(b, 10));
		
		System.out.println("First occurrence of 2: " + f.searchFirstOccurrence(b, 2));
		System.out.println("Last occurrence of 2: " + f.searchLastOccurrence(b, 2));
		System.out.println("Count total occurrence of 2: " + f.countOccurrence(b, 2));
	}
	
}
