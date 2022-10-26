class Solution {
public:
    int MOD = 1e9 + 7;
    vector<vector<int>> dp;
    long backtrack(int picked, int delivered, int& n) {
        if(picked == n && delivered == n) {
            return 1;
        }
        
        if(picked > n || delivered > n || delivered > picked) {
            return 0;
        }
        
        if(dp[picked][delivered] != -1) {
            return dp[picked][delivered];
        }
        
        long ans = 0;
        ans += (n-picked)* backtrack(picked+1, delivered, n);
                            
        ans = ans % MOD;
        ans += (picked-delivered)* backtrack(picked, delivered+1, n);
                            
        ans = ans %  MOD;
        
        return  dp[picked][delivered] = ans;
    }
    int countOrders(int n) {
        dp = vector<vector<int>>(n+1, vector<int>(n+1, -1));
        return backtrack(0, 0, n);
    }
};


