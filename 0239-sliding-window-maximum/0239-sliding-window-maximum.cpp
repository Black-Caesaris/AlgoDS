class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> result;
            
        deque<int> q;
        
        int l = 0;
        int r = 0;
        
        while(r < nums.size()) {
            while(!q.empty() && nums[q.back()] < nums[r]) {
                q.pop_back();
            }
            
            q.push_back(r);
            
            if(l > q.front())
                q.pop_front();
            
            if(r+1 >= k) {
                result.push_back(nums[q.front()]);
                l++;
            }

            r++;   
        }
        
        return result;
    }
};