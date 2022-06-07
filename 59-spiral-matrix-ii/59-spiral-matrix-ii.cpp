class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> result(n, vector<int>(n, 0));
        
        if(n == 0) return {{0}};
        
        int l = 0, t = 0;
        int r = n-1, b = n-1;
        int count = 1;
        
        while(l <= r && t <= b){
            
            if(l <= r){
                for(int i = l ; i <= r; i++){
                    result[t][i] = count++;
                }
            }
            t++;
            
            if(t <= b){
                for(int i = t ; i <= b; i++){
                    result[i][r] = count++;
                }
            }
            r--;

            if(l <= r){
                for(int i = r ; i >= l; i--){
                    result[b][i] = count++;
                }
            }
            b--;

        
            if(t <= b){
                for(int i = b ; i >= t; i--){
                    result[i][l] = count++;
                }
            }
            l++;

        }
        
        
        return result;
         
    }
};
