package facebook;

import java.util.ArrayList;
import java.util.List;

public class SignPlusMin {

	/**
	 *  0 : append "+"
	 *  1 : append "-"
	 *  2 : just append number
	 */
	private static int[] MASK = { 0, 1, 2 };
	
	private List<String> subsetResult = new ArrayList<String>();
	
	public void generateSubset(String input){
		int[] mask = new int[input.length()];
		subset(input, mask, 0);
	}
	
	private void subset(String input, int[] mask, int k){
		if(isSolution(input, k)){
			processSolution(input, mask);
		}else{
			k++;
			for(int i = 0; i < MASK.length; i++){
				mask[k-1] = MASK[i];
				subset(input, mask, k);
			}
		}
	}
	
	private boolean isSolution(String input, int k){
		return k == input.length();
	}
	
	private void processSolution(String input, int[] mask){
		StringBuilder tmpBuilder = new StringBuilder();
		for(int i = 0; i < input.length(); i++){
			if(mask[i] == 0){
				tmpBuilder.append("+");
			}else if(mask[i] == 1){
				tmpBuilder.append("-");
			}
			tmpBuilder.append(input.charAt(i));
		}
		String tmp = tmpBuilder.toString();
		
		// remove duplicate when subset started without sign
		if(tmp.startsWith("+") || tmp.startsWith("-")){
			subsetResult.add(tmp);
		}
	}
}
