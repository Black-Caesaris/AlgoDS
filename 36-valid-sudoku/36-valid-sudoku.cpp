class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int rows = board.size();
        int cols = board[0].size();
        
        vector<unordered_set<int>> rowSets(rows);
        vector<unordered_set<int>> colSets(cols);
        vector<unordered_set<int>> gridSets(rows);
        
        for(int i = 0 ; i < rows ; i++) {
            for(int j = 0 ; j < cols ; j++) {
                
                if(board[i][j] == '.') {
                    continue;
                }
                
                
                // check for ith row
                if(rowSets[i].count(board[i][j] - '0')) {
                    return false;
                }
                
                rowSets[i].insert(board[i][j] - '0');
                
                // check for jth col
                if(colSets[j].count(board[i][j] - '0')) {
                    return false;
                }
                
                colSets[j].insert(board[i][j] - '0');
                
                // check for grid
                
                int gridIdx = (i/3) * 3 + (j/3);
                
                if(gridSets[gridIdx].count(board[i][j] - '0')) {
                    return false;
                }
                
                gridSets[gridIdx].insert(board[i][j] - '0');
        }
        }
        return true;
    }
};