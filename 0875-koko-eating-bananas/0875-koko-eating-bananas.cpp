class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        
        int sum = 0;

        int result = 0;
        while(left < right) {
            int mid = left + (right - left ) / 2;
            int hours = 0;
            
            for(int& pile : piles) {
                hours += pile / mid + (pile % mid != 0);
            }
            
            if(hours <= h) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return right;
    }
};