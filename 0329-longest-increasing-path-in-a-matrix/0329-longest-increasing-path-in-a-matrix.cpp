class Solution {
public:
    map<string, int> dp;
    set<string> visited;
    
    vector<int> x_coords = {0, 0, -1, 1};
    vector<int> y_coords = {-1, 1, 0, 0};
    
    bool isValid(int x, int y, vector<vector<int>>& matrix) {
        if(x >= 0 && y >= 0 && x < matrix.size() && y < matrix[0].size())
            return true;
        return false;
    }
    
    int dfs(vector<vector<int>>& matrix, int x, int y) {     
        string hash = to_string(x) + "#" + to_string(y);
    
        
        if(dp.count(hash))
            return dp[hash];
        
        int result = 0;
        for(int i = 0 ; i < 4; i++) {
            int next_x = x + x_coords[i];
            int next_y = y + y_coords[i];
            
            if(isValid(next_x, next_y, matrix) && matrix[next_x][next_y] > matrix[x][y]) {
                result = max(result, 1 + dfs(matrix, next_x, next_y));
            }
        }
        
        dp.insert({hash, result});
        
        return result;
        
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int result = 0;
        
        for(int i = 0 ; i < m; i++) {
            for(int j = 0 ; j < n; j++) {
                result = max(result, 1 + dfs(matrix, i, j));
            }
        }
        
        return result;
    }
};