class Solution {
public:
    
    vector<int> x_coord = {0, 0, 1, -1};
    vector<int> y_coord = {1, -1, 0, 0};
    
    void dfs(vector<vector<char>>& grid, int x, int y){
        if(grid[x][y] == '1'){
          grid[x][y] = 'X'; 
        } else {
            return;
        }

            
        for(int i = 0 ; i < 4; i++){
            int x_new = x + x_coord[i];
            int y_new = y + y_coord[i];
            
            if(x_new >= 0 && x_new < grid.size() && y_new >= 0 && y_new < grid[0].size()){
                
                dfs(grid, x_new, y_new);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        
        for(int i = 0 ; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    result++;
                }
            }
        }
        
        return result;
    }
};