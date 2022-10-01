class Solution {
public:
    vector<int> dp;
    bool backtrack(int idx, string& s, unordered_set<string>& wordSet) {
        if(idx == s.length()) {
            return true;
        }
        
        if(dp[idx] != -1) 
            return dp[idx];
        
        for(int i = idx; i < s.length(); i++) {
            string word = s.substr(idx, i-idx+1);
            if(wordSet.count(word) && backtrack(i+1, s, wordSet)){
                return dp[idx] = true;
            }
        }
        
        dp[idx] = 0;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        dp = vector<int>(s.length(), -1);
        return backtrack(0, s, wordSet);
    }
};