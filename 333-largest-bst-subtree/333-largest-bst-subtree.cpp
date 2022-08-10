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
    
    
    int findMax(TreeNode* root){
        if(root == nullptr) return INT_MIN;
        
        return max({root->val, findMax(root->left), findMax(root->right)});
    }
    
    int findMin(TreeNode* root){
        if(root == nullptr) return INT_MAX;
        
        return min({root->val, findMin(root->left), findMin(root->right)});
    }
    
    int countNodes(TreeNode* root){
        if(root == nullptr) return 0;
        
        return (1 + countNodes(root->left) + countNodes(root->right));
    }
    
    bool isBST(TreeNode* root){
        if(root == nullptr) return true;
        
        int left_max = findMax(root->left);
        int right_min = findMin(root->right);
        
        if(root->val <= left_max || root->val >= right_min){
            return false;
        }
        
        if(isBST(root->left) && isBST(root->right)){
           return true; 
        }
        
        
        return false;
    }
    

    int largestBSTSubtree(TreeNode* root) {
        if(!root) return 0;
        
        if(isBST(root)){
            return countNodes(root);
        }
        
        return (max(largestBSTSubtree(root->left), largestBSTSubtree(root->right)));
    }
};