class Solution {
public:
    
    vector<vector<int>> result;
    unordered_set<string> uniques;
    
    void helper(string s, vector<int>& nums, vector<int> visited){
        if(s.length() == nums.size()){
            if(uniques.find(s) == uniques.end()){
                vector<int> temp;
                for(int i = 0; i < s.length(); i++){
                    temp.push_back(s[i]-'0');
                }
                result.push_back(temp);
                uniques.insert(s);
            }            
            return;
        }
        
        
        for(int i = 0 ; i < nums.size(); i++){
            if(!visited[i]){
                s.push_back(nums[i] + '0');
                visited[i] = true;
                helper(s, nums, visited);
                s.pop_back();
                visited[i] = false;
            }
        }
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if(nums.size() == 0) return {{}};
        string s;
        vector<int> visited(nums.size(), false);
        helper(s, nums, visited);
        return result;
    }
};