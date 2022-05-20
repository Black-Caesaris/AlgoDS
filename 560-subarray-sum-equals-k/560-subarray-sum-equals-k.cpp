class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int n = nums.size();
        int result = 0;
        int sum = 0;
        map.insert({0, 1});
        for(int i = 0; i < n; i++){
            sum += nums[i];
            if(map.find(sum-k) != map.end()){
                result += map[sum-k];
            }
            if(map.find(sum) != map.end()){
                map[sum] += 1;
            }else{
                map.insert({sum, 1});
            }
        }
        
        return result;
    }
};