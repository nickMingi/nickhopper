package facebook;

public class parentheses {

	public String balance(String str){
		if(str == null || str.isEmpty() || !isValid(str)){
			return "";
		}
		
		// Now we know the string can be balanced
		int rightBraceOverCount = 0;
		char[] array = str.toCharArray();
		for(int i = 0; i < array.length; i++){
			char c = array[i];
			if(c == ')'){
				rightBraceOverCount++;
				if(rightBraceOverCount > 0){
					array[i] = '(';
				}
			}else{
				if(rightBraceOverCount > 0){
					array[i] = ')';
				}
				rightBraceOverCount--;
			}
			
		}
		
		return str;
	}

	
	private boolean isValid(String str){
		char[] array = str.toCharArray();
		int leftBrace = 0, rightBrace = 0;
		for (char c : array){
			if(!(c == '(' || c == ')')){
				return false;
			}
			if(c == '('){
				leftBrace++;
			}else rightBrace++;
		}
		
		return leftBrace == rightBrace;
	}
	
	public static void main(String[] args) {
		parentheses p = new parentheses();
		String str = "((ab)cc)";
		System.out.println(p.balance(str));
	}
}
