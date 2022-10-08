class TicTacToe {
public:
    vector<int> rows;
    vector<int> cols;
    int diagonal;
    int antiDiagonal;
    TicTacToe(int n) {
        rows = vector<int>(n, 0);
        cols = vector<int>(n, 0);
        diagonal = 0;
        antiDiagonal = 0;
    }
    
    int move(int row, int col, int player) {
        int playerValue = (player == 1) ? 1 : -1;
        
        rows[row] += playerValue;
        cols[col] += playerValue;
        
        int n = rows.size();
        
        if(row == col){
            diagonal += playerValue;
        }
        
        if(col == n - row - 1) {
            antiDiagonal += playerValue;
        }
        
        if(abs(rows[row]) == n || abs(cols[col]) == n || abs(diagonal) == n || abs(antiDiagonal) == n)
            return player;
        
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */