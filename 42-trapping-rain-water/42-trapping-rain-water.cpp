class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> l_max(height.size());
        vector<int> r_max(height.size());
        int result = 0;
        
        l_max[0] = height[0];
        for(int i = 1 ; i < height.size(); i++){
            l_max[i] = max(l_max[i-1], height[i]);
        }
        
        r_max[height.size() - 1] = height[height.size() - 1];
        for(int i = height.size() - 2 ; i >= 0; i--){
            r_max[i] = max(r_max[i+1], height[i]);
        }
        
        
        for(int i = 0 ; i < height.size(); i++){
            result += min(l_max[i], r_max[i]) - height[i];
        }
        
        return result;
        
        
       
    }
};