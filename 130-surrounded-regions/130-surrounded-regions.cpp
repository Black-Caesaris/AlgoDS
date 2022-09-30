class Solution {
public:
    
    vector<int> x_coord = {0, 0, 1, -1};
    vector<int> y_coord = {-1, 1, 0, 0};
    
    bool isValid(int x, int y, vector<vector<char>>& board) {
        if(x >= 0 && x < board.size() && y >= 0 && y < board[0].size()) {
            return true;
        }
        
        return false;
    }
    
    void dfs(vector<vector<char>>& board, int x, int y) {
        if(!isValid(x, y, board))
            return;
        
        if(board[x][y] != 'O')
            return;
        
        board[x][y] = 'E';
        
        for(int i = 0 ; i < 4; i++) {
            int new_x = x + x_coord[i];
            int new_y = y + y_coord[i];
            dfs(board, new_x, new_y);
        }
        
    }
    
    void solve(vector<vector<char>>& board) {
        int r = board.size();
        int c = board[0].size();
        
        for(int i = 0 ; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(i*j == 0 || i == r - 1 || j == c - 1) {
                    dfs(board, i, j);
                }
            }
        }
        
        for(int i = 0 ; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(board[i][j] == 'E') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};