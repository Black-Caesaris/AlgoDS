class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        // find the maximum height to the right of each building
        int max_height = INT_MIN;
        vector<int> result;
        for(int i = heights.size() - 1; i >= 0 ; i--){
            if(heights[i] > max_height){
                result.push_back(i);
                max_height = heights[i];
            }
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};