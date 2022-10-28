class Solution {
public:
    

    vector<int> x_coords = {0, 0, -1, 1};
    vector<int> y_coords = {-1, 1, 0, 0};
    
    const int GATE = 0;
    const int WALL = -1;
    const int EMPTY = INT_MAX;
    
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        int n = rooms[0].size();
        queue<vector<int>> q;

                
        for(int i = 0 ; i < m; i++) {
            for(int j = 0 ; j < n; j++) {
                if(rooms[i][j] == GATE) {
                    // perform dfs from the gate
                    q.push({i, j});
                } 
            }
        }
        
        while(!q.empty()) {
            int levelSize = q.size();
            for(int i = 0 ; i < levelSize; i++) {
                vector<int> node = q.front();
                q.pop();
                
                int row = node[0];
                int col = node[1];
                   
                for(int i = 0 ; i < 4; i++) {
                    int next_row = row + x_coords[i];
                    int next_col = col + y_coords[i];
                    
                    if(next_row < 0 || next_col < 0 || next_row >= m || next_col >= n
                      || rooms[next_row][next_col] != EMPTY)
                        continue;
                    
                    rooms[next_row][next_col] = 1 + rooms[row][col];
                    q.push({next_row, next_col});
                }
            }
        }
        
    }
};