class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        if(nums.size() == 1)
            return nums[0];
        
        for(int i = 0 ; i < nums.size(); i++) {
            cout << nums[abs(nums[i])] << endl;
            if(nums[abs(nums[i])] < 0)
                return abs(nums[i]);
            nums[abs(nums[i])] = -1*nums[abs(nums[i])];
        }
        
        return nums[0];
    }
};