package facebook;

public class EncodingChar {

	//Iterative Time Complexity:O(N)
	public int countEncodings(String str){
		if(str == null || str.length() == 0 || str.charAt(0) == 0){
			return 0;
		}
		int n_1 = 1;
		int n_2 = 1;
		for(int i = 1; i < str.length(); i++){
			int oneDigit = Integer.parseInt(str.substring(i,i+1));
			int twoDigit = Integer.parseInt(str.substring(i - 1, i + 1));
			if(oneDigit == 0 && twoDigit == 0){
				return 0;
			}
			int nextTotal = 0;
			if(oneDigit >= 1 && oneDigit < 10){
				nextTotal += n_1;
			}
			if(twoDigit >= 10 && twoDigit <= 26){
				nextTotal += n_2;
			}
			n_2 = n_1;
			n_1=nextTotal;
		}
		return n_1;
	}
	
	public static void main(String[] args) {
		EncodingChar c = new EncodingChar();
		String str= "abcabcabc";
		System.out.println(c.countEncodings(str));
	}
}
