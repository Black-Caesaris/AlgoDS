class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        priority_queue<int, vector<int>, greater<int>> heap;
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        });
            
        for(int i = 0 ; i < intervals.size(); i++) {
            vector<int> interval = intervals[i];
            
            if(!heap.empty() && heap.top() <= interval[0]) {
                heap.pop();
            }
            heap.push(interval[1]);
        }
        
        return heap.size();
    }
};