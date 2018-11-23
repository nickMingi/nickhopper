package google;

import java.util.Arrays;
import java.util.List;

public class HtmlStyle {

	public static String makeBold(String s, List<String> sub){
		for(String eachSub : sub){
			String[] parts = s.split(eachSub);
			StringBuilder sb = new StringBuilder();
			String insert = new StringBuilder("<b>").append(eachSub).append("</b>").toString();
			for(int i = 0; i < parts.length; i++){
				sb.append(parts[i]);
				if(i < parts.length - 1)
					sb.append(insert);
			}
			s = sb.toString();
		}
		return s;
	}
	
	public static void main(String[] args) {
		System.out.println(HtmlStyle.makeBold("HelloWorld HelloWorld", Arrays.asList("el","rl")));
	}
}
