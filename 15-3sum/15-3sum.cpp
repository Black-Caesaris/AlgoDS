class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() < 3) return result;
        
        // sort
        sort(nums.begin(), nums.end());
        int left, right;
        for(int i = 0 ; i < nums.size() - 2 && nums[i] <= 0; i++){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            left = i + 1;
            right = nums.size() - 1;
            
            while(left < right){
                if(nums[i] + nums[left] + nums[right] == 0){
                    result.push_back({nums[i], nums[left++], nums[right--]});
                    while(left < right && nums[left] == nums[left-1]){
                        left++;
                    }
                }else if(nums[i] + nums[left] + nums[right] < 0){
                    left++;
                }else{
                    right--;
                }
            } 
        }
        
        return result;
    }
};