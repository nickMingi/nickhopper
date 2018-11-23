package Amazon;

import java.util.Map;

public class LengthOfSum3 {

	static int[] A = {1,2,1,2,3,7,1,3,2,1};
	int M = 5;
	static Map map1;
	int total = 0;
	public int getSum(int[] A, int start, int end){
		total = total + A[end];
		if(total == M){
			System.out.println(" start " + start + " end " + end);
		}else if(total < M){
			return getSum(A, start, ++end);
		}else if(total > M){
			start++;
			total = A[start];
			end = start + 1;
			return getSum(A, start, end);
		}
		return total;
	}
	
	public static void main(String[] args) {
		LengthOfSum3 p = new LengthOfSum3();
		p.getSum(A, 0, 0);
	}
	
}
