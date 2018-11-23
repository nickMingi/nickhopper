package facebook;

import java.util.ArrayList;
import java.util.List;

public class SplitArrayInTwo {

	public static boolean isSolution(List<Integer> solution, int sum){
		return (sum == 0);
	}
	
	public static List<Integer> construct_candidates(int []input, List<Integer> solution, int sum){
		List<Integer> candidates = new ArrayList<Integer>();
		
		for(int i = 0; i < input.length; i++){
			if(!solution.contains(i) && sum >= i){
				candidates.add(i);
			}
		}
		return candidates;
	}
	
	static void process_solution(int[] input, List<Integer> solution){
		for (int i = 0; i < input.length; i++){
			if(!solution.contains(i)){
				System.out.println(input[i] + " ");
			}
		}
		System.out.println();
		for (int i : solution){
			System.out.println(input[i] + " ");
		}
	}
	
	static boolean finished = false;
	
	static void backtrack(int[] input, List<Integer> solution, int sum){
		if (isSolution(solution, sum) ){
			finished = true;
			process_solution(input,solution);
		}else {
			List<Integer> candidates = construct_candidates(input, solution, sum); 
			for (int candidate : candidates){
				if (!finished){
					sum -= input[candidate];
					solution.add(candidate);
					backtrack(input,solution,sum);
					solution.remove(candidate);
					sum += input[candidate];
				}
			}
		}
	}
	
	public static void main(String[] args) throws java.lang.Exception {
		
		int[] input = { 5, 15, 10, 25, 35, 10, 15, 45};
		int sum = 0;
		for (int x : input){
			sum+=x;
		}
		if (sum%2 != 0){
			System.out.println("Not possible");
			return;
		}else
			System.out.println("Sum is " + sum + " Trying for " + sum/2);
		List<Integer> solution = new ArrayList<Integer>();
		backtrack(input,solution, sum/2);
	}
}
