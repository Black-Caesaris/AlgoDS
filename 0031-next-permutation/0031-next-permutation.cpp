class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        if(nums.size() <= 1)
            return;

        int i = nums.size() - 1;
        while(i >= 1 && nums[i] <= nums[i-1])
            i--;
        

        
        if(i > 0) {
            int j = nums.size() - 1;
            while(nums[j] <= nums[i-1])
                j--;
            
            swap(nums[i-1], nums[j]);
        }
        
        reverse(nums.begin() + i, nums.end());
    }
};