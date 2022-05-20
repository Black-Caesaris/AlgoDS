/* DP Solution; but time limit exceeded*/
// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         vector<int> dp(nums.size()+1, INT_MAX);
//         dp[0] = 0;
//         dp[1] = 0;
//         for(int i = 1; i <= nums.size(); i++){
//             for(int j = 0 ; j < i; j++){
//                 if(j > 0 && dp[j] != INT_MAX && nums[j-1] + j-1 >= i-1 ){
//                     dp[i] = min(dp[i], dp[j]+1);
//                 }
//             }
//         }
        
//         return dp[nums.size()];
//     }
// };


/* Greedy Solution*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int end = nums.size();
        int max_jump = 0;
        int result = 0;
        int current_jump_idx = 0;
        
        for(int i = 0 ; i < end - 1; i++){
            max_jump = max(max_jump,  nums[i] + i);
            
            if(i == current_jump_idx){
                current_jump_idx = max_jump;
                result++;
            }
            
            if(current_jump_idx >= end - 1) break;
        }
        
        return result;
    }
};