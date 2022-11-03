class Comparator {
public:
    bool operator () (vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    }
 };

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, Comparator> q;
        vector<vector<int>> result;
        
        for(vector<int>& point : points) {
            int distance = pow(point[0], 2) + pow(point[1], 2);
            
            if(q.size() < k) {
                q.push({point[0], point[1], distance});
                continue;
            }
            
            if(q.size() == k && q.top()[2] > distance) {
                q.pop();
                q.push({point[0], point[1], distance});
                continue;
            } 
            
        }
        
        while(!q.empty()) {
            vector<int> data = q.top();
            q.pop();
            result.push_back({data[0], data[1]});
        }
        
        return result;
    }
};