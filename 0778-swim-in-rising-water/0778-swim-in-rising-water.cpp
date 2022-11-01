class Comparator {
public:
    bool operator () (vector<int>& a, vector<int>&b) {
        return a.back() > b.back();
    }
};

class Solution {
public:
    vector<int> x_dir = {0, 0, 1, -1};
    vector<int> y_dir = {-1, 1, 0, 0};
    
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        priority_queue<vector<int>, vector<vector<int>>, Comparator> q;
        
        set<pair<int, int>> visited;
        
        q.push({0, 0, grid[0][0]});
        
        visited.insert({0, 0});
        int result = INT_MIN;
        
        while(!q.empty()) {
            int levelSize = q.size();
            for(int i = 0 ; i < levelSize; i++) {
                vector<int> node = q.top();
                q.pop();
                
                result = max(result, node[2]);
                
                if(node[0] == m - 1 && node[1] == n - 1)
                    return result;
                
                for(int i = 0 ; i < 4; i++) {
                    int next_x = node[0] + x_dir[i];
                    int next_y = node[1] + y_dir[i];
                    
                    if(next_x < 0 || next_y < 0 || next_x >= m || next_y >= n || visited.count({next_x, next_y}))
                        continue;
                    
                    q.push({next_x, next_y, grid[next_x][next_y]});
                    visited.insert({next_x, next_y});
                }
            }
        }
        
        return -1;
        
    }
};