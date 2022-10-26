/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

typedef pair<int, int> pii;

class Comparator {
public:
  bool operator () (Interval a, Interval b) {
      return a.start > b.start;
  }  
};

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        
        vector<Interval> result;
        priority_queue<Interval, vector<Interval>, Comparator> pq;
        
        for(vector<Interval>& intervals : schedule) {
            for(Interval& interval : intervals) {
                pq.push(interval);
            }
        }
        
        int prev = 0;
        
        while(!pq.empty()) {
            Interval current = pq.top();
            pq.pop();
            prev = max(prev, current.end);
            if(!pq.empty() && prev < pq.top().start) {
                Interval temp = Interval(prev,  pq.top().start);
                result.emplace_back(temp);
            }
        }
        return result;
    }
};