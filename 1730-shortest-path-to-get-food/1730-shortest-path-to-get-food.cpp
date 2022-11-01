class Solution {
public:
    const char START = '*';
    const char FOOD = '#';
    const char EMPTY = 'O';
    const char OBSTACLE = 'X';
    
    vector<int> x_dir = {0, 0, 1, -1};
    vector<int> y_dir = {-1, 1, 0, 0};
    
    int bfs(int a, int b, vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        queue<vector<int>> q;
        
        q.push({a, b});
        grid[a][b] = OBSTACLE;
        int distance = 1;
        
        while(!q.empty()) {
            int levelSize = q.size();
            for(int i = 0 ; i < levelSize; i++) {
                vector<int> node = q.front();
                q.pop();
                
                for(int i = 0 ; i < 4; i++) {
                    int x = node[0] + x_dir[i];
                    int y = node[1] + y_dir[i];
                    
                    if(x < 0 || y < 0 || x >= rows || y >= cols || grid[x][y] == OBSTACLE)
                        continue;

                    if(grid[x][y] == FOOD)
                        return distance;

                    grid[x][y] = OBSTACLE;
                    q.push({x, y});
                }
            }
            distance++;
        }
        return -1;
    }
    
    int getFood(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        for(int i = 0 ; i < rows; i++) {
            for(int j = 0 ; j < cols; j++) {
                if(grid[i][j] == START) {
                    return bfs(i, j, grid);
                }
            }
        }
        
        return -1;
    }
    

};
