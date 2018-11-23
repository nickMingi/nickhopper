package Amazon;

import java.util.TreeMap;

public class LengthOfSum2 {

	TreeMap<Integer, Integer> tmap = new TreeMap<Integer, Integer>();
	int k = 6;
	void calSum(int b, int e, int a[]){
		int tempSum = 0;
		for(int i = b; i <= e; i++){
			tempSum = tempSum + a[i];
		}
		
		if(tempSum == k){
			tmap.put(e-b+1, e-b+1);
		}
	}
	
	int function(int beg, int end, int arr[]){
		if(beg <= end){
			calSum(beg, end, arr);
			function(beg+1,end-1,arr);
			function(beg+1,end,arr);
			function(beg,end-1,arr);
		}else{
			return 0;
		}
		
		return 0;
	}
	
	void seeResult(){
		System.out.println(tmap.lastKey().toString());
	}
	
	public static void main(String[] args) throws java.lang.Exception {
		int array[] = {1,4,5,1,2,1,2,2};
		
		LengthOfSum2 id = new LengthOfSum2();
		id.function(0, array.length-1, array);
		id.seeResult();
	}
}
