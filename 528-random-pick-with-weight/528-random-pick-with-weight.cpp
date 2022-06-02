class Solution {
public:
    
    vector<int> prefix_sum;
    Solution(vector<int>& w) {
        for(int n : w){
            prefix_sum.push_back(n + (prefix_sum.empty() ? 0 : prefix_sum.back()));
        }
    }
    
    int pickIndex() {
        float rand_n = (float) rand() / RAND_MAX;
        float target = rand_n * prefix_sum.back();
        
        int left = 0;
        int right = prefix_sum.size() - 1;
        
        int ans = 0;
        while(left <= right){
            int mid = left + (right - left) / 2;
            
            if(target <= prefix_sum[mid]){
                ans = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */