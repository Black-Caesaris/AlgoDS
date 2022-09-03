class Solution {
public:
    
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        
        if(board.size() == 0) return board;
        
        int m = board.size();
        int n = board[0].size();
        bool todo = false;
        
        // first run sliding window over rows
        for(int i = 0 ; i < m; i++){
            for(int j = 0 ; j + 2 < n; j++){
                int v = abs(board[i][j]);
                if(v != 0 && abs(board[i][j+1]) == v &&  abs(board[i][j+2]) == v){
                    board[i][j+1] = -v;
                    board[i][j+2] = -v;
                    board[i][j] = -v;
                    todo = true;
                }
            }
        }
       
        // then run sliding window over columns
        for(int i = 0 ; i + 2 < m; i++){
            for(int j = 0 ; j < n; j++){
                int v = abs(board[i][j]);
                if(v != 0 && abs(board[i+1][j]) == v &&  abs(board[i+2][j]) == v){
                    board[i+1][j] = -v;
                    board[i+2][j] = -v;
                    board[i][j] = -v;
                    todo = true;
                }
            }
        }
        
        
        
        for(int c = 0 ; c < n; c++){
            int wr = m - 1;
            for(int r = m - 1 ; r >= 0 ; r--){
                if(board[r][c] > 0){
                    board[wr--][c] = board[r][c];
                }
            }

            while(wr >= 0){
                board[wr--][c] = 0;
            }
        }
        
        // then run sliding window over columns
        return todo ? candyCrush(board) : board;
    }
};