package google;

public class BinaryExpressionTree {

	enum Operator{
		add(true), subtract(false), multiply(true), divide(false);
		
		private boolean symmetric;
		
		private Operator(boolean symmetric){
			this.symmetric = symmetric;
		}
		
		boolean compare(OperatorNode a, OperatorNode b){
			if(a.left.isEqual(b.left) && a.right.isEqual(b.right))
				return true;
			if(symmetric){
				return (a.left.isEqual(b.right) && a.right.isEqual(b.left));
			}
			return false;
		}
	}
	
	abstract class Node{
		abstract boolean isEqual(Node other);
	}
	
	class OperatorNode extends Node{
		Operator operator;
		Node left;
		Node right;
		
		boolean isEqual(Node other){
			if(!(other instanceof OperatorNode)){
				return false;
			}
			OperatorNode n = (OperatorNode) other;
			if(operator != n.operator){
				return false;
			}
			return operator.compare(this, n);
		}
	}
	
	class LeafNode extends Node{
		String value;
		
		boolean isEqual(Node other){
			if(!(other instanceof LeafNode)){
				return false;
			}
			LeafNode n = (LeafNode) other;
			return value.equals(n.value);
		}
	}
	
	boolean compare(Node a, Node b){
		return a.isEqual(b);
	}
}
