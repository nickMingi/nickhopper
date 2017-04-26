package facebook;

public class NonzeroElement {

	public static int moveNonZeroToLeft(int[] a){
		if(a.length==0)
			return 0;
		int start = 0, end = 0;
		while(end < a.length){
			if(a[end]!=0 && start==end)
				start++;
			else if(a[end]!=0){
				a[start] = a[end];
				start++;
			}
					end++;
		}
		return start;
	}
	
	public static void main(String[] args) {
		NonzeroElement n = new NonzeroElement();
		int[] a = new int[]{4,0,2,3,0,0,1};
		System.out.println(n.moveNonZeroToLeft(a));
		
	}
}
