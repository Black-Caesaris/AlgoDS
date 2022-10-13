typedef vector<vector<string>> vvs;
typedef list<list<string>> lls;
typedef vector<string> vs;
typedef list<string> ls;


class Solution {
public:
    
    unordered_map<string, lls> dp;
    unordered_set<string> wordSet;
    
    lls backtrack(string& s) {
        if(s.length() == 0) {
            cout << "In";
            lls result;
            result.push_back({});
            return result;
        }
        
        if(dp.count(s)) {
            return dp[s];
        }
        
        // cout << s << endl;
        for(int i = 1 ; i <= s.length(); i++) {
            string prefix = s.substr(0, i);
            // cout << prefix << " " << endl;
            if(wordSet.count(prefix)) {
                cout << prefix << endl;
                string next = s.substr(i);
                lls sentences = backtrack(next);
                // cout << sentences.size();
                
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
        ls result;
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
            cout << temp;
            temp.pop_back();
            result.push_back(temp);
        }
        
        vector<string> resultVector(result.begin(), result.end());
        return resultVector;
    }
};