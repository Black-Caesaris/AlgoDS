class Solution {
public:
    
    vector<vector<int>> results;
    void helper(vector<int> comb, vector<int>& candidates, int idx, int target){
        if(target == 0){
            results.push_back(comb);
            return;
        }else if(target < 0){
            return; 
        }
        
        for(int i = idx ; i < candidates.size(); i++){
            comb.push_back(candidates[i]);
            helper(comb, candidates, i, target - candidates[i]);
            comb.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> comb;
        helper(comb, candidates, 0, target);
        return results;
    }
};