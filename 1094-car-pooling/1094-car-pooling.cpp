class Solution {
public:
    map<int, int> intervalCount; 
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        for(auto& trip : trips) {
            intervalCount[trip[1]] += trip[0];    
            intervalCount[trip[2]] -= trip[0];    
        }
        
        int cumm = 0;
        for(auto& it : intervalCount) {
            cumm += it.second;
            if(cumm > capacity)
                return false;
            
        }
    
        return true;
    }
};