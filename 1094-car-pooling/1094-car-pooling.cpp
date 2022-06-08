class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        //<timestamp, #passengers>
        vector<int> t(1001, 0);
        
        for(vector<int> trip : trips){
            t[trip[1]] += trip[0];
            t[trip[2]] -= trip[0];
        }
        
        int used =0 ;
        for(int i = 0 ; i < 1001; i++){
            used += t[i];
            if(used > capacity) return false;
        }
        
        
        return true;
            
    }
};