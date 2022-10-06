class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() == 0)
            return false;
        
        vector<int> lis;
        lis.push_back(nums[0]);
        
        for(int i = 1 ; i < nums.size(); i++) {
            if(nums[i] > lis[lis.size() - 1]) {
                lis.push_back(nums[i]);
                if(lis.size() == 3) {
                    return true;   
                }
            } else {
                int ind = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
                lis[ind] = nums[i]; 
            }
        }
        
        return false;
    }
};