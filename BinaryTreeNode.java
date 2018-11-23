package google;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class BinaryTreeNode {

	TreeNode testRootPos;
	TreeNode testRootNeg;
	
	public void setUp(){
		testRootPos = new TreeNode(1);
		TreeNode a = new TreeNode(2);
		TreeNode b = new TreeNode(3);
		TreeNode c = new TreeNode(4);
		TreeNode d = new TreeNode(2);
		TreeNode e = new TreeNode(4);
		TreeNode f = new TreeNode(4);
		
		testRootPos.left = a;
		testRootPos.right = b;
		a.left = c;
		b.left = d;
		b.right = e;
		d.left = f;
		
		testRootNeg = new TreeNode(4);
		TreeNode _a = new TreeNode(2);
		TreeNode _b = new TreeNode(4);
		TreeNode _c = new TreeNode(1);
		TreeNode _d = new TreeNode(2);
		TreeNode _e = new TreeNode(4);
		TreeNode _f = new TreeNode(3);
		
		testRootNeg.left = _a;
		testRootNeg.right = _b;
		_a.left = _c;
		_b.left = _d;
		_b.right = _e;
		_d.left = _f;
	}
	
	public void testHashDuplicateSubtreesTrue(){
		List<TreeNode> results = BinaryTreeNode.hasDuplicateSubtrees(testRootPos);
		assertEquals();
		
	}
	
	public void testHashDuplicateSubtreesFalse(){
		
	}
	
	private static Set<String> seen = new HashSet<>();
	private static Map<String, TreeNode> dupes = new HashMap<>();
	
	public static List<TreeNode> hasDuplicateSubtrees(TreeNode root){
		recursiveVerify(root);
		return new ArrayList<>(dupes.values());
	}
	
	private static String recursiveVerify(TreeNode curr){
		if(curr == null) return "N";
		
		String lVal = recursiveVerify(curr.left);
		String rVal = recursiveVerify(curr.right);
		
		String signature = lVal + "I" + Integer.toString(curr.val) + "I" + rVal;
		if(seen.contains(signature)){
			if(!dupes.containsKey(signature)){
				dupes.put(signature, curr);
			}
		}
		seen.add(signature);
		return signature;
	}
}
class TreeNode{
	int val;
	TreeNode left;
	TreeNode right;
	TreeNode(int x) {val = x;}
}

