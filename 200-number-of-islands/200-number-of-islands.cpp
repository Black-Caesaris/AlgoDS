class Solution {
public:
    
    vector<int> x_dir = {0, 0, -1, 1};
    vector<int> y_dir = {-1, 1, 0, 0};
    
    bool isValid(int x, int y, vector<vector<char>>& grid) {
        if(x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()) {
            return true;
        }
        return false;
    }
    
    void dfs(int x, int y, vector<vector<char>>& grid) {
        grid[x][y] = '0';
        
        for(int i = 0 ; i < 4; i++) {
            int x_coord = x + x_dir[i];
            int y_coord = y + y_dir[i];
            if(isValid(x_coord, y_coord, grid) && grid[x_coord][y_coord] == '1') {
                    dfs(x_coord, y_coord, grid);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int result = 0;
        
        if(r == 0 && c == 0) {
            return result;
        }
        
        for(int i = 0 ; i < r; i++) {
            for(int j = 0 ; j < c; j++) {
                if(grid[i][j] == '1'){
                    result++;
                    dfs(i, j, grid);
                }
            }
        }
        
        return result;
    }
};