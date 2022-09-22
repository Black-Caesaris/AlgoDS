class Solution {
public:
    int mySqrt(int x) {
        
        // using Binary Search
        // we know the answer can only between 1, x/2;
        
        if(x == 0 || x == 1) return x;
        
        int low = 2;
        int end = x / 2;
        int mid = 0;
        int ans = 1;
        
        while(low <= end) {
            mid = low + (end-low)/2;
            long int sq = (long)mid*mid;
            if(sq == x) {
                return mid;
            } else if (sq < x) {
                ans = mid;
                low = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        
        return ans; 
    }
};