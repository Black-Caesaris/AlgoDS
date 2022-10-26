class Solution {
public:
    vector<int> x_coords = {0,0,1,-1};
    vector<int> y_coords = {-1,1,0,0};
    int shortestPath(vector<vector<int>>& grid, int k) {
        queue<vector<int>> q;
        q.push({0, 0, k});
        int minDistance = 0;
        
        unordered_set<string> visited;
        while(!q.empty()) {
            int currLevelSize = q.size();
            for(int i = 0 ; i < currLevelSize; i++) {
                
                vector<int> node = q.front();
                int x = node[0];
                int y = node[1];
                int chances = node[2];
                q.pop();
                
                if(x == grid.size() - 1 && y == grid[0].size() - 1) {
                    return minDistance;
                }
                
                for(int i = 0 ; i < 4; i++) {
                    int new_x = x + x_coords[i];
                    int new_y = y + y_coords[i];
                    
                    if(new_x < 0 || new_y < 0 || new_x == grid.size() || new_y == grid[0].size())
                        continue;
                    
                    int leftChances = node[2] - grid[new_x][new_y];
                    
                    string hash = to_string(new_x) + "#"  + to_string(new_y) + "#" + to_string(leftChances) ;
                    
                    
                    
                    
                    if(leftChances >= 0 && !visited.count(hash)) {
                        visited.insert(hash);
                        q.push({new_x, new_y, leftChances});
                    }
                }
                
            }
            minDistance++;
        }
        
        return -1;
    }
};