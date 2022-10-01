class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int min_so_far = nums[0];
        int max_so_far = nums[0];
        int ans = nums[0];
        
        for(int i = 1 ; i < nums.size(); i++) {
            int temp_max = max(nums[i], max_so_far*nums[i]);
            temp_max = max(temp_max, min_so_far*nums[i]);
            
            min_so_far = min(nums[i], min_so_far*nums[i]);
            min_so_far = min(min_so_far, max_so_far*nums[i]);
            
            max_so_far = temp_max;
            
            ans = max(ans, max_so_far);

        }
        
        return ans;
        
    }
};