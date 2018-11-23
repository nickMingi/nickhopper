package facebook;

import java.util.*;

public class WorkAllocation {

	  public static ArrayList<int[]> getArrangements(int[] jobTimes, int currentJob, int k) {
	        ArrayList<int[]> arrangements = new ArrayList<int[]>();
	        if (currentJob == jobTimes.length - 1) {
	            // for each worker, we create a partial arrangement with the last job allocated to that worker
	            for (int w = 0; w < k; ++w) {
	                int[] arrangement = new int[jobTimes.length];
	                arrangement[currentJob] = w;
	                arrangements.add(arrangement);
	            }
	            return arrangements;
	        }
	        for (int w = 0; w < k; ++w) {
	            // for each worker, we get the partial arrangements that allocate all jobs > currentJob
	            // then create a new partial arrangement with the currentJob allocated to that worker
	            ArrayList<int[]> partial = getArrangements(jobTimes, currentJob + 1, k);
	            for (int[] arrangement : partial) {
	                int[] newArrangement = arrangement.clone();
	                newArrangement[currentJob] = w;
	                arrangements.add(newArrangement);
	            }
	        }
	        return arrangements;
	    }

	    public static int getMinimum(int[] jobTimes, int k) {
	        if (jobTimes.length < 1) return 0;
	        ArrayList<int[]> arrangements = getArrangements(jobTimes, 0, k);
	        System.out.println("All arrangements:");
	        for (int[] arrangement : arrangements) {
	            printArrangement(arrangement, jobTimes, k);
	        }
	        System.out.println();
	        int minimum = Integer.MAX_VALUE;
	        int[] bestArrangement = null;
	        for (int[] arrangement : arrangements) {
	            int[] workerTimes = new int[k];
	            for (int job = 0; job < arrangement.length; ++job) {
	                workerTimes[arrangement[job]] += jobTimes[job];
	            }
	            int arrangementTime = Integer.MIN_VALUE;
	            for (int time : workerTimes) {
	                if (time > arrangementTime) arrangementTime = time;
	            }
	            if (arrangementTime < minimum) {
	                minimum = arrangementTime;
	                bestArrangement = arrangement;
	            }
	        }
	        System.out.println("Best arrangement:");
	        printArrangement(bestArrangement, jobTimes, k);
	        return minimum;
	    }

	    public static void main(String[] args) {
	        int[] jobTimes = new int[] {2, 2, 3, 7, 1};
	        int k = 2;
	        int min = getMinimum(jobTimes, k);
	        System.out.println(min);
	    }

	    public static void printArrangement(int[] arrangement, int[] jobTimes, int k) {
	        HashMap<Integer, ArrayList<Integer>> workerToJobs = new HashMap<Integer, ArrayList<Integer>>();
	        for (int w = 0; w < k; ++w) {
	            workerToJobs.put(w, new ArrayList<Integer>());
	        }
	        for (int j = 0; j < arrangement.length; ++j) {
	            workerToJobs.get(arrangement[j]).add(j);
	        }
	        int charactersAvailable = 30;
	        for (int w = 0; w < k; ++w) {
	            String s = "W" + w + ": { ";
	            for (int j : workerToJobs.get(w)) {
	                s += jobTimes[j] + " ";
	            }
	            s += "}";
	            int remaining = charactersAvailable - s.length();
	            for (int i = 0; i < remaining; ++i) s += " ";
	            System.out.print(s);
	        }
	        System.out.println();
	    }
}
