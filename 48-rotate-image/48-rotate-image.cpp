class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // transpose and reverse
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        for(int r = 0 ;r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                if(r<c) {
                    swap(matrix[r][c], matrix[c][r]);
                }
            }
            reverse(matrix[r].begin(), matrix[r].end());
        }
    }
};