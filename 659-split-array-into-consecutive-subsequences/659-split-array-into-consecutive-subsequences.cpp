class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> f;
        unordered_map<int, int> s;
        
        for(auto& num : nums){
            f[num]++;
        }
        
        for(int& num : nums){
            if(f[num] == 0){
                continue;
            }
            
            if(s[num - 1] > 0){
                s[num-1]--;
                s[num]++;
            } else if (f[num + 1] > 0 && f[num + 2] > 0){
                s[num + 2]++;
                f[num+1]--;
                f[num+2]--;
            } else {
                return false;
            }
            
            f[num]--;
        }
        return true;
    }
};