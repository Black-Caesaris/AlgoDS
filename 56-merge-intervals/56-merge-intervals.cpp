class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;

        if(intervals.size() == 0) return result;
        
        sort(begin(intervals), end(intervals), [](vector<int>& a, vector<int>& b){
            if(a[0] == b[0]){
                return (a[1] < b[1]);
            }
            
            return (a[0] < b[0]);
        });
            
        result.push_back(intervals[0]);
        for(auto& interval : intervals){
            // if start of interval is before end of previous interval
            if(interval[0] <= result.back()[1]){
                // overlap
                cout << "In here";
                vector<int> temp(2);
                temp[0] = result.back()[0];
                temp[1] = max(interval[1], result.back()[1]);
                result.pop_back();
                result.push_back(temp);
            } else {
                result.push_back(interval);
            }
        }
        
        
        return result;
            
    }
};