class Solution {
public:
    
    vector<vector<int>> copy;

    vector<int> x_dir = {0,0,1,-1,1,1,-1,-1};
    vector<int> y_dir = {-1, 1, 0, 0,1,-1,1,-1};
    
    void mutateCell(vector<vector<int>>& board, int x, int y){
        int live = 0;
        int dead = 0;
        
        for(int i = 0 ; i < 8; i++){
            int x_new = x + x_dir[i];
            int y_new = y + y_dir[i];
            
            if(x_new >= 0 && y_new >= 0 && x_new < board.size() && y_new < board[0].size()){
                if(copy[x_new][y_new] == 1){
                    live++;
                } else {
                    dead++;
                }
            }    
        }
        
        if(board[x][y]){
            if(live < 2 || (live > 3)){
                board[x][y] = 0;
            }
        } else {
            if(live == 3) {
                board[x][y] = 1;
            }
        }
    
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        copy = board;
        
        for(int i = 0 ; i < board.size(); i++){
            for(int j = 0 ; j < board[0].size(); j++){
                mutateCell(board, i, j);
            }
        }        
        
    }
};