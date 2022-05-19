class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> answer;
        
        for(int i = 0 ; i < nums.size(); i++){
            if(m.find(target - nums[i]) != m.end()){
                answer.push_back(i);
                answer.push_back(m[(target - nums[i])]);
                return answer;
            }
            
            m.insert(make_pair(nums[i], i));
        }
        
        return answer;
    }
};