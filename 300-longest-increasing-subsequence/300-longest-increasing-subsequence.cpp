class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        dp[0] = 1;
        for(int i = 1; i < dp.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }
        
        int result = 0;
        for(int& a : dp) {
            result = max(result, a);
        }
        return result;
    }
};