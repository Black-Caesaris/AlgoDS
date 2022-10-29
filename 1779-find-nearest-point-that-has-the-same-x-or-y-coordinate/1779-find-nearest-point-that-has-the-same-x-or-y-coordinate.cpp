class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int result = INT_MAX;
        int min_so_far = INT_MAX;
        for(int i = 0 ; i < points.size(); i++) {
            if(points[i][0] == x || points[i][1] == y) {
                cout << "x: " << points[i][0] << " y : " << points[i][1] << endl;
                int dist = abs(x - points[i][0]) + abs(y - points[i][1]);
                cout << dist << endl;
                if(min_so_far > dist) {
                    min_so_far = dist;
                    cout << "i : " << i << endl;
                    result = i;
                }
            }
        }
        
        return result == INT_MAX ? -1 : result;
    }
};