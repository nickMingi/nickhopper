package google;

import java.util.HashSet;
import java.util.Set;

public class OccurenceOfMoreN {

	public static void main(String[] args) {
		
	}
	
	public Set<Integer> findNumbers(int[] arr, double k){
		Set<Integer> result = new HashSet<>();
		double size = arr.length / k;
		if(size <= 1){
			return result;
		}
		int step = (int) size / 2;
		step = step < 1 ? 1 : step;
		for(int i = 0; i < arr.length - step; i += step){
			if(arr[i] == arr[i + step]){
				int start = binarySearch(i-step, i, arr);
				int end = start + (int) size;
				if(end < arr.length && arr[end] == arr[i]){
					result.add(arr[i]);
				}
			}
		}
		return result;
	}
	
	private int binarySearch(int start, int end, int[] arr){
		if(start < 0){
			return 0;
		}
		int target = arr[end];
		while(start < end){
			int mid = (start + end) / 2;
			if (arr[mid] == target){
				end = mid - 1;
			}else{
				start = mid + 1;
			}
		}
		return start;
	}
}
