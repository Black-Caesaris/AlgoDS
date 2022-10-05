class Solution {
    public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
        if(root == null){
            return null;
        }
        
        TreeNode successor = inorderSuccessor(root.left, p);
        if(successor != null){
            return successor;
        }
        
        if(root.val > p.val){
            return root;
        }
        
        return inorderSuccessor(root.right, p);
    }
}