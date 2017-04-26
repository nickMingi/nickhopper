package google;

public class MaxSubArray {

	static class Data{
		int product;
		int startIndex;
		int endIndex;
		Data(){
			super();
			this.product = Integer.MIN_VALUE;
			this.startIndex = -1;
			this.endIndex = -1;
		}

		public Data(int product, int startIndex, int endIndex) {
			super();
			this.product = product;
			this.startIndex = startIndex;
			this.endIndex = endIndex;
		}

		@Override
		public String toString() {
			return "Data [product=" + product + ", startIndex=" + startIndex + ", endIndex=" + endIndex + "]";
		}
	}

	static Data ProcessSubArray(int[] arr, int startIndex, int endIndex){
		if (startIndex == endIndex){
			return new Data(arr[startIndex], startIndex, endIndex);
		}else{
			int val = 1;
			int firstNegativeIndex = -1;
			int lastNegativeIndex = -1;

			for (int i=startIndex; i<=endIndex; i++){
				val *= arr[i];
				if (arr[i] <=0){
					if (firstNegativeIndex == -1){
						firstNegativeIndex = i;
					}
					lastNegativeIndex = i;
				}
			}

			if (val < 0){
				int multiplierFirst = 1;
				for (int j=startIndex; j<=firstNegativeIndex; j++){
					multiplierFirst*=arr[j];
				}
				int multiplierLast = 1;
				for (int j=lastNegativeIndex; j<=endIndex; j++){
					multiplierLast*=arr[j];
				}
				if (val/multiplierFirst > val/multiplierLast){
					startIndex = firstNegativeIndex+1;
					val = val/multiplierFirst;
				}else{
					endIndex = lastNegativeIndex -1;
					val = val/multiplierLast;
				}
			}
			Data data = new Data(val, startIndex, endIndex);
			return data;
		}
	}

	private static void ProcessArr(int[] arr) {
		if (arr == null || arr.length <=0){
			System.out.println(new Data(Integer.MIN_VALUE, -1, -1));
			return;
		}
		Data maxData = new Data();
		int startIndex = -1;
		for (int i=0; i<arr.length; i++){
			if (arr[i] == 0){
				if (startIndex != -1){
					Data data = ProcessSubArray(arr, startIndex, i-1);
					if (data.product>maxData.product){
						maxData = data;
					}
					startIndex =-1;
				}
				if (0>maxData.product){
					maxData = new Data(0, i, i);
				}
			} else {
				if (startIndex == -1){
					startIndex = i;
				}
			}
		}

		if (startIndex!=-1){
			Data data = ProcessSubArray(arr, startIndex, arr.length-1);
			if (data.product>maxData.product){
				maxData = data;
			}
		}

		System.out.println(maxData.toString());
	}

	public static void main(String[] args){
		int arr[] = {0, 1, 2, -6, 8, 10, -9, -5, 1, 0, 8, 6, 5, 0};
		ProcessArr(arr);
		arr = new int[]{};
		ProcessArr(arr);
		arr = new int[]{0};
		ProcessArr(arr);
		arr = new int[]{-1};
		ProcessArr(arr);
		arr = new int[]{2};
		ProcessArr(arr);
		arr = new int[]{-3, 2};
		ProcessArr(arr);
		arr = new int[]{3, -2};
		ProcessArr(arr);
		arr = new int[]{-3, 2, 0, 0 , 3, -2};
		ProcessArr(arr);
		arr = new int[]{0, 0, -3, 2, 0, 0 , 3, -2, 0, 0};
		ProcessArr(arr);
	}
}