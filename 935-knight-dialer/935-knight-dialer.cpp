class Solution {
public:
    vector<int> x_coord = {2,2,-2,-2,1,-1,1,-1};
    vector<int> y_coord = {1,-1,1,-1,2,2,-2,-2};
    int dp[4][4][5000];
    unordered_set<string> result;
    const int mod = 1e9 + 7;

    
    bool isValid(int x, int y){
        if(x == 3 && (y == 0 || y == 2)){
            return false;
        }
        
        if(x >= 0 && x < 4 && y >=0 && y < 3) return true;
        
        return false;
    }

    int dfs(int i, int j, int n){
        if(n == 1) return 1;
        
        int& val = dp[i][j][n];
        
        if(val != -1) return val;
        
        int cnt = 0;
        
        for(int m = 0 ; m < 8; m++){
            int x = i + x_coord[m];
            int y = j + y_coord[m];
            if(isValid(x, y)){
                cnt = (cnt + dfs(x, y, n - 1)) % mod;
            }
        }
        
        return val = cnt;
    }
    
    int knightDialer(int n) {
        
        if(n == 0) return 0;
        
        string number;
        int ans = 0;
        memset(dp, -1, sizeof(dp));
        for(int i = 0 ; i < 4; i++){
            for(int j = 0 ; j < 3; j++){
                if(!isValid(i, j)){
                    continue;
                }
                ans = (ans + dfs(i, j, n)) % mod;
            }
        }
        
        
        return ans;
        
    }
};