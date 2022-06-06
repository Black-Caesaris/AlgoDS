class Solution {
public:
    vector<vector<int>> ans;
    vector<int> vis;
    void helper(int idx,vector<int> &nums,vector<int> out){
        int n = nums.size();
        if(idx==n){
            ans.push_back(out);
            return;
        }
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                if(i!=0 && nums[i]==nums[i-1] && vis[i-1]==0)
                    continue;
                vis[i]=1;
                out.push_back(nums[i]);
                helper(idx+1,nums,out);
                out.pop_back();
                vis[i]=0;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        ans = {};
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vis = vector<int>(n,0);
        helper(0,nums,{});
        return ans;
    }
};