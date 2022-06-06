// class Solution {
// public:
    
//     vector<vector<int>> result;
//     unordered_set<string> uniques;
    
//     void helper(string s, vector<int>& nums, vector<int> visited){
//         if(s.length() == nums.size()){
//             if(uniques.find(s) == uniques.end()){
//                 vector<int> temp;
//                 for(int i = 0; i < s.length(); i++){
//                     temp.push_back(s[i]-'0');
//                 }
//                 result.push_back(temp);
//                 uniques.insert(s);
//             }            
//             return;
//         }
        
        
//         for(int i = 0 ; i < nums.size(); i++){
//             if(!visited[i]){
//                 s.push_back(nums[i] + '0');
//                 visited[i] = true;
//                 helper(s, nums, visited);
//                 s.pop_back();
//                 visited[i] = false;
//             }
//         }
        
//     }
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         if(nums.size() == 0) return {{}};
//         string s;
//         vector<int> visited(nums.size(), false);
//         helper(s, nums, visited);
//         return result;
//     }
// };



class Solution {
public:
    
    vector<vector<int>> result;
    
    void helper(vector<int> comb, unordered_map<int, int> count, int& N){
        
        if(comb.size() == N){
            result.push_back(comb);
            return;
        }
        
        for(auto it = count.begin(); it != count.end(); it++){
            if(it->second == 0) continue;
            
            comb.push_back(it->first);
            it->second = it->second - 1;
            helper(comb, count, N);
            comb.pop_back();
            it->second = it->second + 1;
        }

    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if(nums.size() == 0) return {{}};
        string s;
        
        unordered_map<int, int> count;
        vector<int> comb;
        for(int i = 0 ; i < nums.size(); i++){
            if(count.count(nums[i])){
                count[nums[i]] += 1;
            }else{
                count.insert({nums[i], 1});
            }
        }
        
        int N = nums.size();
        helper(comb, count, N);
        return result;
    }
};