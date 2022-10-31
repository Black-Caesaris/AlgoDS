class Solution {
public:

    vector<vector<int>> coords = {
        {1, 2},
        {2, 1},
        {-1, 2},
        {-2, 1},
        {1, -2},
        {2, -1},
        {-1, -2},
        {-2, -1},
    };
    
    int minKnightMoves(int x, int y) {
        if(x == 0 && y == 0)
            return 0;
                
        queue<pair<int, int>> q;
        set<pair<int, int>> visited;
        visited.insert({0, 0});
        q.push({0, 0});
        
        x = abs(x);
        y = abs(y);
        
        int result = 0;
        
        while(!q.empty()) {
            int levelSize = q.size();
            for(int i = 0 ; i < levelSize; i++) {
                pair<int, int> node = q.front();
                
                int curr_x = node.first;
                int curr_y = node.second;
                
                if(curr_x == x && curr_y == y)
                    return result;
                
                q.pop();
                
                for(auto coord : coords) {
                    int next_x = curr_x + coord[0];
                    int next_y = curr_y + coord[1];
                    // cout << next_x << " : " << next_y << endl;
                    if(!visited.count({next_x, next_y}) && -2 <= next_x && next_x <= x + 2 && -2 <= next_y  && next_y <= y + 2) {
                        // cout << next_x << " : " << next_y << endl;
                        q.push({next_x, next_y});
                        visited.insert({next_x, next_y});
                    }
                }
            }
            result++;
        }
    return -1;
    }
};