package google;

public class Attendance {

	public boolean studentReward(String studentRec){
		
		
		if (studentRec.indexOf("A") != studentRec.lastIndexOf("A")){
			// absent more than 1s
			return false;
		}
		
		// LLA ALL LAL
		// no consecutive late/Absent 3 times
		if (studentRec.matches(".*(A|L){3}.*")){
			return false;
		}
		
		return true;
	}
	
	public static void main(String[] args) {
		String studentRec = "OOLLAOOLLOO";
		boolean check = new Attendance().studentReward(studentRec);
		System.out.println(check);
	}
}
