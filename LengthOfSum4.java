package Amazon;

public class LengthOfSum4 {

	static int[] givenNumbers = {1, 3, 5, 7, 11, 13, 17, 19, 1, 1, 23, 29};
	static int expSum = 30;
	
	public static void main(String[] args) {
		findIt(0, 0);
	}
	
	private static void findIt(int start, int end){
		long sum = sum(start, end);
		if(sum < expSum){
			findIt(start, nextIndex(end));
		}else if(sum > expSum){
			findIt(nextIndex(start), end);
		}else{
			for(int i = start; i <= end; i++){
				System.out.println(" " + givenNumbers[i]);
			}
		}
	}
	
	private static int nextIndex(int index){
		if(index + 1 > givenNumbers.length){
			System.out.println("can't locate subarray for sum " + expSum);
			System.exit(0);
		}
		return ++index;
	}
	
	private static long sum(int start, int end){
		long sum = 0;
		for(int i = start; i <= end; i++){
			sum += givenNumbers[i];
		}
		return sum;
	}
}
