class Solution {
public:
    
    vector<vector<int>> results;
    vector<bool> visited;
    
    void helper(vector<int>& candidates, vector<int> comb, int target, int idx){
        if(target == 0){
            results.push_back(comb);
            return;
        }else if(target < 0){
            return;
        }
        
        for(int i = idx; i < candidates.size(); i++){
                if(i != 0 && candidates[i] == candidates[i-1] && i != idx){
                    continue;
                }
                comb.push_back(candidates[i]);
                helper(candidates, comb, target - candidates[i], i+1);
                comb.pop_back();  

        }
        
        
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> comb;
        visited = vector<bool>(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        helper(candidates, comb, target, 0);
        return results;
    }
};