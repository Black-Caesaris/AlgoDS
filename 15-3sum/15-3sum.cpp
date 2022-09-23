class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left, right;
        vector<vector<int>> result;
        
        for(int i = 0 ; i < nums.size() - 2; i++) {
            if(i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            
                left = i + 1;
                right = nums.size() - 1;
                while(left < right) {
                    if(nums[i] + nums[left] + nums[right] < 0 ) {
                        left++;
                    } else if (nums[i] + nums[left] + nums[right] > 0) {
                        right--;
                    } else {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[left++]);
                        temp.push_back(nums[right--]);
                        result.push_back(temp);
                        while(left < right && nums[left] == nums[left-1]){
                            left++;
                        }
                    }
                }
        }
        return result;
    }
};