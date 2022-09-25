class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rowTop = 0;
        int rowBottom = matrix.size() - 1;
        int colLeft = 0;
        int colRight = matrix[0].size() - 1;
        int n = matrix.size() * matrix[0].size();
        
        vector<int> result;
        
        while(result.size() < n) {

            for(int i = colLeft ; i <= colRight; i++) {
                result.push_back(matrix[rowTop][i]);
            }
            rowTop++;
            
            for(int i = rowTop ; i <= rowBottom; i++) {
                result.push_back(matrix[i][colRight]);
            }
            colRight--;
            
            if(rowTop <= rowBottom){
                for(int i = colRight ; i >= colLeft; i--) {
                    result.push_back(matrix[rowBottom][i]);
                }  
            }

            rowBottom--;
            
            if(colLeft <= colRight) {
                for(int i = rowBottom ; i >= rowTop; i--) {
                    result.push_back(matrix[i][colLeft]);
                }
            }

            colLeft++;
            
        }
        
        return result;
    }
};