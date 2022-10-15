class Solution {
public:
    
// top down approach (TLE)
//     unordered_map<string, int> memo;
//     int dfs(vector<string>& words, string currWord, unordered_set<string> wordSet) {
//         if(currWord == "") {
//             return 0;
//         }
        
//         if(memo.count(currWord)) {
//             return memo[currWord];
//         }
        
//         int ans = 1;
//         for(int i = 0 ; i < currWord.length(); i++) {
//             string predCandidate = currWord.substr(0, i) + currWord.substr(i + 1);
//             if(wordSet.count(predCandidate)) {
//                 int curr = 1 + dfs(words, predCandidate, wordSet);
//                 ans = max(ans, curr);
//             }
//         }
        
//         memo.insert({currWord, ans});
//         return memo[currWord];
        
        
//     }
//     int longestStrChain(vector<string>& words) {
//         // sort(words.begin(), words.end(), [](string& a, string& b) {
//         //     return a.length() < b.length();
//         // });
        
//         unordered_set<string> wordSet(words.begin(), words.end());
        
//         int ans = 0;
//         for(string& word : words) {
//             ans = max(ans, dfs(words, word, wordSet));
//         }
        
//         return ans;
//     }
    
    // bottom up approach
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](string& a, string& b) {
            return a.length() < b.length();
        });
        
        unordered_set<string> wordSet(words.begin(), words.end());
        
        unordered_map<string, int> dp;
        int result = 1;
        
        
        for(string& word : words) {
            int ans = 1;
            for(int i = 0; i < word.length(); i++) {
                string predCandidate = word.substr(0, i) + word.substr(i+1);
                if(dp.count(predCandidate)) {
                    int prevLength = dp[predCandidate];
                    ans = max(ans, prevLength + 1);
                }
            }
            dp.insert({word, ans});
            result = max(result, ans);
        }
        
        return result;
    }
};