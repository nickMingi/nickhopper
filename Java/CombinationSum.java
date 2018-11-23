package google;

public class CombinationSum {

	public static boolean combinationSum(int[] nums, int target){
		if(target == 0)
			return true;
		if(nums.length == 0)
			return false;
		boolean[][] dp = new boolean[nums.length+1][target+1];
		for(int i = 0; i <= nums.length; i++)
			dp[i][0] = true;
		for(int i = 1; i <= nums.length; i++){
			for(int j = nums[i-1]; j<=target; j++){
				if(dp[i-1][j]==true){
					dp[i][j]=true;
					continue;
				}
				 for(int k = 1; k <= j/nums[i-1]; k++){
					 if(dp[i][j-nums[i-1]*k]==true){
						 dp[i][j]=true;
						 break;
					 }
				 }
			}
		}
		return dp[nums.length][target];
	}
	
	public static void main(String[] args) {
		CombinationSum c = new CombinationSum();
		boolean check = c.combinationSum(new int[]{1,4,5}, 33);
		System.out.println(check);
	}
}
