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

    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> result;
        
        if(root == nullptr) return result;
        
        map<int, vector<int>> order;

                
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        while(!q.empty()){
            pair<TreeNode*, int> p = q.front();
            q.pop();
            
            TreeNode* node = p.first;
            int col = p.second;
            
            if(!order.count(col)){
                order.insert({col, {node->val}});
            } else {
                order[col].push_back(node->val);
            }
            
            if(node->left){
                q.push({node->left, col - 1});
            }
            
            if(node->right){
                q.push({node->right, col + 1});
            }
        }
        
        for(auto i : order){
            result.push_back(i.second);
        }
        
        return result;
    }
};