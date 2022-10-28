/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = INT_MIN;
    
    int solve(TreeNode* root) {
        if(!root)
            return 0;
        
        int l_max = max(solve(root->left), 0);
        int r_max = max(solve(root->right), 0);
        
        int curr = root->val;
        
        // taking current node into path
        ans = max(ans, l_max + curr + r_max);
        
        return  max(l_max, r_max) + curr;;
    }
    
    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};