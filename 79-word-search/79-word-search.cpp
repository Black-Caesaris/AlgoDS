class Solution {
public:
    
    vector<int> x_coord = {0, 0, 1, -1};
    vector<int> y_coord = {-1, 1, 0, 0};
    
    bool inBounds(int x, int y, vector<vector<char>>& board) {
        if(x >= 0 && x < board.size() && y >=0 && y < board[0].size()) {
            return true;
        }
        
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, int x, int y, int idx, string& word, vector<vector<bool>>& visited) {
        if(idx >= word.length()) {
            return true;
        }
        
        if(!inBounds(x, y, board)) return false;
        if(visited[x][y] || board[x][y] != word[idx]) return false;
        

        
        visited[x][y] = true;
        
        for(int i = 0 ; i < 4; i++) {
            int x_new = x + x_coord[i];
            int y_new = y + y_coord[i];
            if(dfs(board, x_new, y_new, idx+1, word, visited)){
                return true;
            }
        }
        
        return visited[x][y] = false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int r = board.size();
        int c = board[0].size();
        
        if(!r && !c) return false;
        
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0 ; j < board[0].size(); j++) {
                if(dfs(board, i, j, 0, word, visited)){
                    return true;
                }
            }
        }
        
        return false;
    }
};