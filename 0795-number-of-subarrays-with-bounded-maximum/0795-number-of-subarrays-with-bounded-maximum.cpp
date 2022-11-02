class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int l = -1;
        int r = -1;
        int result = 0;
        
        for(int i = 0 ; i < nums.size(); i++) {
            int n = nums[i];
            if(n > right) {
                l = r = i;
                continue;
            } 
            
            if(n >= left) {
                r = i;
            }
            
            result += r - l;
            
        }
        
        return result;
    }
};