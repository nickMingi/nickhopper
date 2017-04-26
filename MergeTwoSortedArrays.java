package google;

import java.util.Arrays;

public class MergeTwoSortedArrays {
	
	public static void main(String[] args) {
		int[] a = new int[]{1,2,3,8,39,57};
		int[] b = new int[]{4,5,6,25,44,77};
		
		System.out.println(Arrays.toString(mergeTwoSortedArrays(a, b)));
	}

	static int[] mergeTwoSortedArrays(int[] a, int[] b){
		// Corner cases
		if(a == null && b == null){
			return null;
		}
		if(a == null){
			return Arrays.copyOf(b, b.length);
		}
		if(b == null){
			return Arrays.copyOf(a, a.length);
		}
		
		// Common cycle
		int[] c = new int[a.length + b.length];
		
		int i = 0, j = 0, k = 0;
		while(i < a.length && j < b.length){
			if(a[i] < b[j]){
				c[k] = a[i];
				i++;
			}else{
				c[k] = b[j];
				j++;
			}
			k++;
		}
		
		// ends
		if(i == a.length){
			while(j < b.length){
				c[k++] = b[j++];
			}
		}else{
			while(i < a.length){
				c[k++] = a[i++];
			}
		}
		return c;
	}
}
