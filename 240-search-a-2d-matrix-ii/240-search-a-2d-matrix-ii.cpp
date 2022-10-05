class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        int search_space = r+c;
        
        bool flag = true;
        int i = 0 ; 
        int j = c - 1;
        
        while(i >= 0 && i < r && j >= 0 && j < c) {
            if(matrix[i][j] > target)
                j--;
            else if (matrix[i][j] < target)
                i++;
            else
                return true;
        }
        
        return false;
    }
};