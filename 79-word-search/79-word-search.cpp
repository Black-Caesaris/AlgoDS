class Solution {
public:
    
    vector<int> x_coord = {0, 0,-1, 1};
    vector<int> y_coord = {-1, 1, 0, 0};
    
    bool dfs(vector<vector<char>>& board, int i, int j, string& word, int n) {

        if(n >= word.length()){
            return true;
        }
            
        
        char c = board[i][j];
        board[i][j] = '#';
        
        for(int k = 0 ; k < 4; k++){
            int x = i + x_coord[k];
            int y = j + y_coord[k];
            
            if(x >= 0 && y >= 0 && x < board.size() && y < board[0].size()){
                if(board[x][y] == word[n]){
                    if(dfs(board, x, y, word, n+1)){
                        return true;
                    }
                }

            }
        }
    
        board[i][j] = c;
        
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), 0));

        for(int i = 0 ; i < board.size(); i++){
            for(int j = 0 ; j < board[0].size(); j++){
                if(board[i][j] == word[0]){
                    if(dfs(board,i, j, word, 1)){
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};