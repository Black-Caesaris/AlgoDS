class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        
        for(int i = 0 ; i < nums.size(); i++){
            if(numMap.count(target - nums[i])) {
                vector<int> result; 
                result.push_back(numMap[target-nums[i]]);
                result.push_back(i);
                return result;
            } 
            
            numMap.insert({nums[i], i});
        }
        
        return {};
    }
};