class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        
        for(int i = n-1; i >0 ; i--){
            if(nums[i-1] < nums[i]){
                int j = i;
                while(j < n && nums[i-1] < nums[j]){
                    j++;
                }
                
                swap(nums[i-1], nums[j-1]);

                reverse(nums.begin() + i, nums.end());
                return;
            }
        }
        
        reverse(nums.begin(), nums.end());
    }
};