package facebook;

import java.util.ArrayList;

public class PrintList {

	public void printresult(String numbers){
		ArrayList<Integer> result = new ArrayList<Integer>();
		permute(0, numbers, result, 0);
		for(Integer i : result){
			System.out.println(i);
		}
	}
	
	public void permute(int index, String numbers, ArrayList<Integer> result, int sum){
		if(numbers.length() == index){
			result.add(sum);
			return;
		}
		for(int i = index; i < numbers.length(); i++){
			int positive = Integer.valueOf(numbers.substring(index, i + 1)) * 1;
			permute(i + 1, numbers, result, sum + positive);
			int negative = Integer.valueOf(numbers.substring(index, i + 1)) * -1;
			permute(i + 1, numbers, result, sum + negative);
		}
	}
	
	public static void main(String[] args) {
		PrintList p = new PrintList();
		p.printresult("123");
	}
}
