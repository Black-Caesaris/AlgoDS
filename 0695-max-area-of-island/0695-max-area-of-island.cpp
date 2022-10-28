class Solution {
public:
    
    int const ISLAND = 1;
    int const WATER = 0;
    
    vector<int> x_coords = {0, 0, 1, -1};
    vector<int> y_coords = {-1, 1, 0, 0};
    
    int dfs(int x, int y, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        grid[x][y] = WATER;
        
        int result = 1;
        for(int i = 0 ; i < 4; i++) {
            int next_x = x + x_coords[i];
            int next_y = y + y_coords[i];
            
            if(next_x < 0 || next_y < 0 || next_x >= m || next_y >= n || grid[next_x][next_y] != ISLAND)
                continue;
            
            result += dfs(next_x, next_y, grid);
        }
        
        return result;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int ans = 0;
        
        for(int i = 0 ; i < m; i++) {
            for(int j = 0 ; j < n; j++) {
                if(grid[i][j] == ISLAND) {
                    ans = max(ans, dfs(i, j, grid));
                }
            }
        }
        
        return ans;
    }
};