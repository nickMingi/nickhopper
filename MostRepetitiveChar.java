package Amazon;

import java.util.*;

public class MostRepetitiveChar {

	public static void mostRepetitiveChar(String input){
		char c ='\0';
		char previous = '\0';
		char result = '\0';
		int most = 0;
		int count = 0;
		
		for(int i = 0; i < input.length(); i++)
		{
			c = input.charAt(i);
			if(c == previous)
			{
				count++;
				
				if(most < count)
				{
					most = count;
					result = c;
				}		
			}
			else
			{
				count = 1;
			}
			
		if(most < count)
			{
				most = count;
				result = c;
			}
			
			previous = c;
					
		}
		System.out.println(result + " " + most);
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		
		String input = in.nextLine();
		
		mostRepetitiveChar(input);
		
		in.close();
		
	}
}
