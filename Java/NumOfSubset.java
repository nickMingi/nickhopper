package google;

import java.util.*;

public class NumOfSubset {

	public static int countSubSet(int[] nums, int target){ 
        if(nums.length==0)
            return 0;
        Arrays.sort(nums);
       int subsets=0;
       int start=0, end=nums.length-1;
       
       while(start<=end){
           if(2*nums[start]>=target)
               return subsets;
          if(nums[start]+nums[end]<target){
              if(start==end)
                  subsets=subsets+1;
              else 
               subsets= subsets+(int)Math.pow(2,end-start-1);
                
              start++;
              }
           else
               end--;
       }
       return subsets;       
	}
	
	public static void main(String[] args) {
		int[] nums = new int[]{1,2,3,4,5,6};
		int target = 5;
		NumOfSubset n = new NumOfSubset();
		System.out.println(n.countSubSet(nums, target));
	}
}
