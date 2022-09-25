class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [] (vector<int>& a, vector<int>& b) {
            if(a[0] == b[0]) {
                return a[1] < b[1];
            } 
            
            return a[0] < b[0];
        });
        
        vector<vector<int>> result;
        for(int i = 0 ; i < intervals.size(); i++) {
            if (i == 0 || intervals[i][0] > result[result.size() - 1][1]) {
                result.push_back(intervals[i]);
            } else {
                result[result.size() - 1][1] = max(result[result.size() - 1][1], intervals[i][1]);
            }
        }
        
        return result;
    }
};