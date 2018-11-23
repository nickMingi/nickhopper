package facebook;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Set;

public class SpaceShipProblem {

	public static void main(String[] args) {
		Coordinate source = new Coordinate(0, 0);
		Coordinate dest = new Coordinate(100, 200);
		
		List<WarmHole> list = new ArrayList<WarmHole>();
		WHPath minPath = findMinPath(source, dest, list);
		System.out.println(minPath);
	}
	
	public static WHPath findMinPath(Coordinate source, Coordinate dest,
			List<WarmHole> list){
		if(source.x == dest.x && source.y == dest.y){
			return new WHPath(null, 0);
		}
		WHPath minPath = null;
		Set<WarmHole> markout = new HashSet<WarmHole>();
		for(WarmHole wh : list){
			if(markout.contains(wh)){
				continue;
			}
			markout.add(wh);
			Iterator<Coordinate> it = wh.pairs.iterator();
			Coordinate whpointA = null;
			Coordinate whpointB = null;
			if(it.hasNext()){
				whpointA = it.next();
			}
			if(it.hasNext()){
				whpointB = it.next();
			}
			// find minPath from left and right point of the warm hole, compare which one is better to use
			WHPath pathA = findMinPath(whpointB, dest, list);
			WHPath pathB = findMinPath(whpointA, dest, list);
			List<WarmHole> path = null;
			int distance = 0;
			if(findDistance(source, whpointB) + pathA.distance < findDistance(
					source, whpointA) + pathB.distance){
				path = pathB.path;
				distance = findDistance(source, whpointB) + pathA.distance;
			}else{
				path = pathA.path;
				distance = findDistance(source, whpointA) + pathB.distance;
			}
			if(path != null){
				if(minPath == null){
					minPath = new WHPath(path, distance);
				}else if(distance < minPath.distance){
					minPath.distance = distance;
					minPath.path = path;
				}
			}
		}
		return minPath;
	}
	
	public static int findDistance(Coordinate source, Coordinate dest){
		return Math.abs(source.x - dest.x) + Math.abs(source.y - dest.y);
	}
}

class WHPath{
	int distance;
	List<WarmHole> path;
	
	WHPath(List<WarmHole> path, int distance){
		this.path = path;
		this.distance = distance;
	};
}

class Coordinate{
	int x;
	int y;
	
	Coordinate(int x, int y){
		this.x = x;
		this.y = y;
	};
}

class WarmHole{
	Set<Coordinate> pairs = new HashSet<Coordinate>();
	WarmHole(Coordinate a, Coordinate b){
		pairs.add(a);
		pairs.add(b);
	};
}