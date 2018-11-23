package Amazon;

public class ReverseInterval {

	public static String reverseAString(String s){
		String reverse = "";
		for(int i = s.length()-1; i >= 0; i--){
			reverse = reverse + s.charAt(i);
		}
		return reverse;
	}
	
	public static String revInteval(String s, int interval){
		int j = 0;
		String reverse = "";
		
		for(int i = (interval-1); i < s.length(); i+=interval){
			String toReverse = s.substring(j, i+1);
			reverse = reverse + "-" + reverseAString(toReverse);
			j = i+1;
		}
		reverse += s.substring(j);
		return reverse;
	}
	
	public static void main(String[] args) {
		System.out.println("Reverse with interval 2 for \'Pracbox Primere\' is " + 
				revInteval("Pracbox Primere", 4)
				);
	}
}
