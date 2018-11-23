package Amazon;

import java.util.ArrayList;

public class ListNotRepeat2 {

	public static void main(String[] args) {
		String[] list1 = new String[]{"aaa","bbb","ddd","xyxz"};
		String[] list2 = new String[]{"bbb","ccc","ccc","hkp"};
		String[] list3 = new String[]{"ddd","eee","fff","lmn"};
		
		solutionProblem(list1, list2, list3);
	}
	static int index1 = 0;
	static int index2 = 0;
	static int index3 = 0;
	
	private static void solutionProblem(String[] list1, String[] list2, String[] list3){
		ArrayList<String> outputArray = new ArrayList<>();
		while(true){
			String outputInfo = FetchCondidate(list1,list2,list3);
			if(outputInfo!=""){
				outputArray.add(outputInfo);
			}
			if(index1>=list1.length && index2>=list2.length && index3>=list3.length){
				break;
			}
		}
		System.out.println(outputArray.toString());
	}
	
	private static String FetchCondidate(String[] list1, String[] list2, String[] list3){
		String str1="", str2="", str3="";
		if(index1<list1.length){
			str1 = list1[index1];
		}
		if(index2<list2.length){
			str2 = list2[index2];
		}
		if(index3<list3.length){
			str3 = list3[index3];
		}
		
		return FindMinValueAndSetIndexes(str1,str2,str3);
	}
	
	private static String FindMinValueAndSetIndexes(String str1, String str2, String str3){
		int findedIndex = 0;
		findedIndex = Compaire(str1,str2,str3);
		switch(findedIndex){
			case 1:
				index1++;
				return str1;
			case 2:
				index2++;
				return str2;
			case 3:
				index3++;
				return str3;
		}
		return "";
	}
	
	private static int Compaire(String str1, String str2, String str3){
		int returnVal = 0;
		returnVal = Compaire(str1,str2,1,2);
		if(returnVal == 1){
			return Compaire(str1,str3,1,3);
		}
		if(returnVal == 2){
			return Compaire(str2,str3,2,3);
		}
		return returnVal;
	}
	
	private static int Compaire(String str1, String str2, int si1, int si2){
		if(str1 == "")
			return si2;
		if(str2 == "")
			return si1;
		int cmpVal = str1.compareTo(str2);
		if(cmpVal == 0){
			if(si1 == 1 || si2 == 1){
				index1++;
			}
			if(si1 == 2 || si2 == 2){
				index2++;
			}
			if(si1 == 3 || si2 == 3){
				index3++;
			}
			return 0;
		}
		if(cmpVal<0)
			return si1;
		return si2;
	}
}
