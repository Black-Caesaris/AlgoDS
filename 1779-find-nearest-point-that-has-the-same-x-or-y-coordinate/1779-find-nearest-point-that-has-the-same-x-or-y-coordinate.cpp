class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int result = INT_MAX;
        int min_so_far = INT_MAX;
        for(int i = 0 ; i < points.size(); i++) {
            if(points[i][0] == x || points[i][1] == y) {
                int dist = abs(x - points[i][0]) + abs(y - points[i][1]);
                if(min_so_far > dist) {
                    min_so_far = dist;
                    result = i;
                }
            }
        }
        
        return result == INT_MAX ? -1 : result;
    }
};