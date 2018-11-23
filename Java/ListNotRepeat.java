package Amazon;

import java.util.Arrays;
import java.util.List;

public class ListNotRepeat {

	public static void merge(List<String> l1,List<String> l2,List<String> l3){
		int i1 = 0;
		int i2 = 0;
		int i3 = 0;
		
		while(i1 < l1.size() && i2 < l2.size() && i3 < l3.size()){
			if(l1.get(i1).compareTo(l2.get(i2)) < 0){
				// l1 < l2
				if(l1.get(i1).compareTo(l3.get(i3)) < 0){
					// l1 < l3
					System.out.println(l1.get(i1));
					
					if(l2.get(i2).compareTo(l1.get(i1)) == 0) i2++;
					if(l3.get(i3).compareTo(l1.get(i1)) == 0) i3++;
					
					i1++;
				}else{
					// l3 < l1
					System.out.println(l3.get(i3));
					
					if(l1.get(i1).compareTo(l3.get(i3)) == 0) i1++;
					if(l2.get(i2).compareTo(l3.get(i3)) == 0) i2++;
					
					i3++;
				}
			}else{
				// l2 < l1
				if(l2.get(i2).compareTo(l3.get(i3)) < 0){
					// l2 < l3
					System.out.println(l2.get(i2));
					
					if(l1.get(i1).compareTo(l2.get(i2)) == 0) i1++;
					if(l3.get(i3).compareTo(l2.get(i2)) == 0) i3++;
					
					i2++;
				}else{
					// l3 < l2
					System.out.println(l3.get(i3));
					
					if(l1.get(i1).compareTo(l3.get(i3)) == 0) i1++;
					if(l2.get(i2).compareTo(l3.get(i3)) == 0) i2++;
					
					i3++;
				}
			}
		}
		
		if(i3 < l3.size()){
			if(i1 > l1.size()){
				i1 = i2;
				l1 = l2;
			}else{
				i2 = i3;
				l2 = l3;
			}
		}
		
		while(i1 < l1.size() && i2 < l2.size()){
			if(l1.get(i1).compareTo(l2.get(i2)) < 0){
				System.out.println(l1.get(i1));
				
				if(l2.get(i2).compareTo(l1.get(i1)) == 0) i2++;
				
				i1++;
			}else{
				System.out.println(l2.get(i2));
				
				if(l2.get(i2).compareTo(l1.get(i1)) == 0) i2++;
				i2++;
			}
		}
		
		if(i2 < l2.size()){
			i1 = i2;
			l1 = l2;
		}
		
		while(i1 < l1.size()){
			System.out.println(l1.get(i1++));
		}
	}
	
	public static void main(String[] args) {
		merge(Arrays.asList("aaa","bbb","ddd","xyxz"),
				Arrays.asList("bbb","ccc","ccc","hkp"),
				Arrays.asList("ddd","eee","ffff","lmn"));
	}
}
