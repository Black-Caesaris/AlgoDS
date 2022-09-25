class Solution {
public:
    vector<vector<int>> result;
    void backtrack(int idx, vector<int>& nums, vector<int> perm, int n) {
        if(perm.size() == n) {
            result.push_back(perm);
            return;
        }
        
        for(int i = idx ; i < nums.size(); i++) {
            swap(nums[idx], nums[i]);
            perm.push_back(nums[idx]);
            backtrack(idx+1, nums, perm, n);
            perm.pop_back();
            swap(nums[idx], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> perm;
        backtrack(0, nums, perm, nums.size());
        return result;
    }
};