package Amazon;

public class LeftOrRight {

	public static <T extends Comparable<T>> String longestPath(BinaryTreeNode<T> root, String steps) {
        return longestPath(root, steps, 0, "");
    }

    private static <T extends Comparable<T>> String longestPath(BinaryTreeNode<T> node, String steps, int step, String path) {
        if (node == null) {
            return path.substring(0, path.length() - 1);
        }

        char chr = '?';
        if (step < steps.length())
            chr = steps.charAt(step);

        String pathLeft = null;
        String pathRight = null;

        switch(chr) {
            case 'L':
                pathLeft = longestPath(node.left, steps, step + 1, path + "L");
                break;
            case 'R':
                pathRight = longestPath(node.right, steps, step + 1, path + "R");
                break;
            case '?':
                pathLeft = longestPath(node.left, steps, step + 1, path + "L");
                pathRight = longestPath(node.right, steps, step + 1, path + "R");
                break;
        }

        if (pathLeft != null && pathRight != null)
            return pathLeft.length() > pathRight.length() ? pathLeft : pathRight;
        else if (pathLeft != null) return pathLeft;
        else return pathRight;
    }

    public static void main(String[] args) {
        BinaryTreeNode<Integer> root = BinaryTreeFactory.makeBinaryTree();
        String longestPath = longestPath(root, "?");
        System.out.println(longestPath);
    }
	
}
