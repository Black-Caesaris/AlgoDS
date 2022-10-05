class Solution {
    public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
        Stack<TreeNode> s = new Stack<>();
        TreeNode node = root;
        boolean found = false;
        while (node != null || !s.isEmpty()) {
            while (node != null) {
                s.push(node);
                node = node.left;
            }
            
            node = s.pop();
            if (found) {
                return node;
            }
            if (node.val == p.val) {
                found = true;
            }
            node = node.right;
        }
        
        return null;
    }
}