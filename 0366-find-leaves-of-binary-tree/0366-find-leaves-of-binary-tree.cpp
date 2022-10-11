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

    map<int, vector<int>> heightNodes;
    
    int height(TreeNode* root) {
        if(!root)
            return 0;
        
        int lHeight = height(root->left);
        int rHeight = height(root->right);
        
        int height = max(lHeight, rHeight) + 1;
        
        if(heightNodes.count(height)) {
            heightNodes[height].push_back(root->val);
        } else {
            heightNodes.insert({height, {root->val}});
        }
        
        return height;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        height(root);
        vector<vector<int>> result;
        
        for(auto i = heightNodes.begin(); i != heightNodes.end(); i++ ) {
            result.push_back(i->second);
        }
        
        return result;
    }
};