package Amazon;

public class LengthOfSum {

	public int lengthOfSum(int[] array, int n){
		return lengthOfNSumRec(array, n, 0);
	}
	
	private int lengthOfNSumRec(int[] array, int n, int start){
		if(n < 0){
			return -1;
		}
		if(n == 0){
			return 0;
		}
		for(int i = start; i < array.length; i++){
			int len = lengthOfNSumRec(array, n - array[i], i + 1);
			if(len >= 0){
				return len + 1;
			}
		}
		return -1;
	}
	
	public static void main(String[] args) {
		LengthOfSum l = new LengthOfSum();
		
		int result = l.lengthOfSum(new int[]{1,4,5,1,2,1}, 3);
		System.out.println(result);
	}
}
