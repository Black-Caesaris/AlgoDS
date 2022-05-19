class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.length() + 1, 0);
        int max_ = 0;
        for(int i = 1 ; i <= s.length(); i++){
            if(s[i] == ')' && s[i-1] == '('){
                dp[i] = i >= 2 ? dp[i-2] + 2 : 2;
            }else if(i-dp[i-1] > 0 && s[i] == ')' && s[i-1] == ')'){
                if(s[i-dp[i-1]-1] == '('){
                    dp[i] = dp[i-1] + ( (i - dp[i-1] >= 2) ? dp[i-dp[i-1]-2] + 2 : 2 );
                }
            }
            max_ = max(max_, dp[i]);
        }
        
        return max_;
    }
};