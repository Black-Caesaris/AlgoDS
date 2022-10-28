class Solution {
public:
    
    static bool comparator(vector<int>& slot1, vector<int>& slot2) {
        return slot1[0] < slot2[0];
    }
    
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        
        vector<int> result = {};
        
        sort(begin(slots1), end(slots1), comparator);
        sort(begin(slots2), end(slots2), comparator);
        
        int ptr1 = 0;
        int ptr2 = 0;
        
        while(ptr1 < slots1.size() && ptr2 < slots2.size()) {
            int left_boundary = max(slots1[ptr1][0], slots2[ptr2][0]);
            int right_boundary = min(slots1[ptr1][1], slots2[ptr2][1]);
            
            if(right_boundary - left_boundary >= duration) {
                result.push_back(left_boundary);
                result.push_back(left_boundary + duration);
                return result;
            }
            
            
            if(slots1[ptr1][1] < slots2[ptr2][1]) {
                ptr1++;
            } else {
                ptr2++;
            }
        }
        
        return result;
    }
};