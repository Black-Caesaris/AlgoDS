class Solution {
public:
    vector<vector<string>> result;
    
    void backtrack(int idx, string& s, vector<string> substring, vector<vector<bool>>& dp) {
        if(idx == s.length()) {
            result.push_back(substring);
            return;
        }
        
        for(int i = idx; i < s.length(); i++) {
            if(s[i] == s[idx] && (i-idx <= 2 || dp[idx+1][i-1])) {
                dp[idx][i] = true;
                substring.push_back(s.substr(idx, i-idx+1));
                backtrack(i+1, s, substring, dp);
                substring.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
        vector<vector<bool>> dp(16, vector<bool>(16, false));
        backtrack(0, s, {}, dp);
        return result;
    }
};