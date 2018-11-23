package Amazon;

public class FindNumSvc {

	public static int findNum(int[] arr){
		if(arr == null || arr.length < 2){
			throw new IllegalArgumentException();
		}
		int[][] minMax = new int[2][arr.length];
		int max = arr[0];
		for(int i = 1; i < arr.length; i++){
			minMax[0][i] = max;
			max = Math.max(arr[i], max);
		}
		int min = arr[arr.length - 1];
		for(int i = arr.length - 2; i >= 0; i--){
			minMax[1][i] = min;
			min = Math.min(arr[i], min);
		}
		for(int i = 1; i < arr.length - 1; i++){
			if(minMax[0][i] < arr[i] && minMax[1][i] > arr[i]){
				return i;
			}
		}
		if(minMax[0][arr.length - 1] < arr[arr.length - 1]){
			return arr.length - 1;
		}
		return minMax[1][0] > arr[0]? 0:-1;
	}
	
	public static void main(String[] args) {
		int[] arr = {-1,4,-3,6,-2,5,8,9};
		System.out.println(findNum(arr));
	}
}
