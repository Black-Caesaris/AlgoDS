typedef list<list<string>> lls;
typedef list<string> ls;
typedef vector<string> vs;

class Solution {
public:
    
    unordered_map<string, lls> dp;
    unordered_set<string> wordSet;
    
    lls backtrack(string& s) {
        if(s.length() == 0) {
            lls result;
            result.push_back({});
            return result;
        }
        
        if(dp.count(s)) {
            return dp[s];
        }
        
        for(int i = 1 ; i <= s.length(); i++) {
            string prefix = s.substr(0, i);
            if(wordSet.count(prefix)) {
                string next = s.substr(i);
                lls sentences = backtrack(next);                
                // in each sentence add the current prefix
                for(ls sentence : sentences) {
                    sentence.push_front(prefix);
                    dp[s].push_back(sentence);
                }
            }
        }
        
        return dp[s];
        
    }    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vs result;
        wordSet = unordered_set<string>(wordDict.begin(), wordDict.end());
        backtrack(s);
        
        lls sentences = dp[s];
        
        for(ls sentence : sentences) {
            // add spaces
            string temp;
            for(string word : sentence) {
                temp += word;
                temp += " ";
            }
            temp.pop_back();
            result.push_back(temp);
        }
        
        return result;
    }
};