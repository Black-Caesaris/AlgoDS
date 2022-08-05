class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return 0;
            
        sort(begin(intervals), end(intervals), [](vector<int>& a, vector<int>& b){
            return (a[0] < b[0]);
        });
        
        
            
        priority_queue<int, vector<int>, greater<int>> q;
        
        q.push(intervals[0][1]);
        for(auto i = 1 ; i < intervals.size(); i++){
            if(q.top() <= intervals[i][0]){
                q.pop();
            }
            
            q.push(intervals[i][1]);

        }
        
        return q.size();
    }
};