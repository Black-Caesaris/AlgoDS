class Solution {
public:
    vector<int> x_coord = {0, 0, 1, -1, 1, 1, -1, -1, };
    vector<int> y_coord = {1, -1, 0, 0, 1, -1, 1, -1};
    
    bool isValid (int x, int y, vector<vector<int>>& board) {
        if(x >= 0 && x < board.size() && y >= 0 && y < board[0].size()) {
            return true;
        }
        return false;
    }
    
    
    void mutateCell(vector<vector<int>>& board, int x, int y) {
        
        int live_n = 0;
        int dead_n = 0;
        
        for(int i = 0 ; i <= 7 ; i++) {
            int x_new = x + x_coord[i];
            int y_new = y + y_coord[i];
            
            if(isValid(x_new, y_new, board)) {
                if(board[x_new][y_new] == 0 || board[x_new][y_new] == -1) {
                    dead_n++;
                } else {
                    live_n++;
                }
            }
        }
        
        if(board[x][y] && (live_n < 2 || live_n > 3)) {
            board[x][y] = -2;
        } else if (!board[x][y] && live_n == 3) {
            board[x][y] = -1;
        }
        
    }
        
    void gameOfLife(vector<vector<int>>& board) {
        // states = {0, 1, -1, -2}
        
        // 1. live < 2(LN) = Dead
        // 2. live == 2(LN) || 3(LN) = live
        // 3. live > 3(LN) = dead
        // 4. dead == 3(LN) == alove
        
        int r = board.size();
        int c = board[0].size();
        
        for(int i = 0 ; i < r; i++) {
            for(int j = 0 ; j < c; j++) {
                mutateCell(board, i, j);
            }
        }
        
        for(int i = 0 ; i < r; i++) {
            for(int j = 0 ; j < c; j++) {
                if(board[i][j] == -1)
                    board[i][j] = 1;
                else if(board[i][j] == -2)
                    board[i][j] = 0;
            }
        }
        
        
        
      }
};