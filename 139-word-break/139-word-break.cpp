class Solution {
public:
    

    
    bool backtrack(int index, string& s, unordered_set<string>& wordSet, vector<int>& memo){
        if(index == s.length()){
            return true;
        }
        
        if(memo[index] != -1) return memo[index];
        
        for(int i=index; i<s.length(); i++){
            string temp = s.substr(index, i-index+1);
            if(wordSet.count(temp) && backtrack(i+1, s, wordSet, memo)){
                return memo[i] = 1;
            }
        }
        
        return memo[index] = 0;
    }
    
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        if(s.length() == 0) return true;
        
        // create word set
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        
        // create dp array
        vector<int> memo(s.length(), -1);
        
        return backtrack(0, s, wordSet, memo);
        
    }
};