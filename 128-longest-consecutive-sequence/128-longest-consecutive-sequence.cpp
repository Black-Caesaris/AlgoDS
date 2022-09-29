class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        
        int ans = 0; 
        
        for(auto i = s.begin() ; i != s.end(); i++) {
            int num = *i;
            cout << num << " ";
            if(s.find(num - 1) == s.end()) {
                int current_count = 1;
                int current_num = num;
                
                while(s.find(current_num+1) != s.end()) {
                    current_count += 1;
                    current_num+=1;
                }
                ans = max(ans, current_count);
            }
        }
        
        
        
        return ans;
    }
};