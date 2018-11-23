package Amazon;

public class PairSum {

	public static void printPair(int a[], int b[], int sum){
		
		for(int i = 0; i < a.length; i++)
		{
			for(int j = 0; j < b.length; j++)
			{
				if(a[i] + b[j] == sum)
					System.out.println("(" + a[i] + "," + b[j] +")");
			}
		}
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int a[] = {1,2,4,-6,5,7,9};
		int b[] = {3, 6, 3, 4, 0};
		int sum = 5;
		
		printPair(a, b, sum);
	}
}
