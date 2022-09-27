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
    
    unordered_map<int, int> inorderRootIndex;
    int preorderRootIndex = 0;
    
    TreeNode* arrayToTree(vector<int>& preorder, const int left, const int right) {
            if(left > right) {
                return nullptr;
            }
        
            int rootVal = preorder[preorderRootIndex++];
            TreeNode* root = new TreeNode(rootVal);
        
            root->left = arrayToTree(preorder, left, inorderRootIndex[rootVal] - 1);
            root->right = arrayToTree(preorder, inorderRootIndex[rootVal] + 1, right);
            return root;
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0 ; i < inorder.size(); i++) {
            inorderRootIndex.insert({inorder[i], i});
        }
        
        
        return arrayToTree(preorder, 0, inorder.size() - 1);
        
    }
};