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
        int distance = 0;
        
        while(!q.empty()) {
            int levelSize = q.size();
            for(int i = 0 ; i < levelSize; i++) {
                vector<int> node = q.front();
                q.pop();
            
                if(grid[node[0]][node[1]] == FOOD)
                    return distance;
                
                grid[node[0]][node[1]] = OBSTACLE;
                
                for(int i = 0 ; i < 4; i++) {
                    int x = node[0] + x_dir[i];
                    int y = node[1] + y_dir[i];
                    
                    if(x < 0 || y < 0 || x >= rows || y >= cols || grid[x][y] == OBSTACLE)
                        continue;
                    
                    q.push({x, y});
                }
            }
            distance++;
        }
        return -1;
    }
    
//     int getFood(vector<vector<char>>& grid) {
//         int rows = grid.size();
//         int cols = grid[0].size();
        
//         for(int i = 0 ; i < rows; i++) {
//             for(int j = 0 ; j < cols; j++) {
//                 if(grid[i][j] == START) {
//                     return bfs(i, j, grid);
//                 }
//             }
//         }
        
//         return -1;
//     }
    
int getFood(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        // To traverse in all directions i.e. north, east, south, and west
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};       
        
        // Standard requirement of BFS!
        queue<pair<int, int>> q;

        // Get the starting location in the Grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '*') {
                    q.push(make_pair(i, j));
                    // We found the starting place. Now, break from this loop.
                    break;
                }
            }
        }
        
        int steps = 0;
        while (!q.empty()) {
            steps++;
            
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto elem = q.front(); q.pop();
               
                // Traverse in each directions i.e.  north, east, south, and west
                for (int i = 0; i < dirs.size(); i++) {
                    int x = elem.first  + dirs[i][0];
                    int y = elem.second + dirs[i][1];
                
                    // If obstacle or reaching boundaries just continue
                    if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == 'X')
                        continue;
                
                    // We found the food
                    if (grid[x][y] == '#')
                        return steps;
                    
                    // Mark this cell as visited by putting obstacle ('X')
                    grid[x][y] = 'X';
                    q.push(make_pair(x, y));
                }
            }
        }
        return -1;
    }
};
