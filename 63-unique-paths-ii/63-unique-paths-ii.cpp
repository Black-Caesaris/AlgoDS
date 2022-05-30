class Solution {
public:
    vector<int> x = {0, -1};
    vector<int> y = {1, 0};
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        
        int m = og.size();
        int n = og[0].size();
        
        if(og[m-1][n-1] || og[0][0]) return 0;
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        dp[0][0] = 1;

        //base cases 
        for(int i = 1 ; i < og.size(); i++){
            if(og[i][0] == 0){
                dp[i][0] = dp[i-1][0];
            }else{
                dp[i][0] = 0;
            }
        }
        
        //base cases 
        for(int i = 1 ; i < og[0].size(); i++){
            if(og[0][i] == 0){
                dp[0][i] = dp[0][i-1];
            }else{
                dp[0][i] = 0;
            }
        }
        
        for(int i = 1; i < dp.size(); i++){
            for(int j = 1; j < dp[0].size(); j++){
                if(og[i][j] == 0){
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }else{
                    dp[i][j] = 0 ;
                }       
            }
        }
        
        return dp[m-1][n-1];
    }
};