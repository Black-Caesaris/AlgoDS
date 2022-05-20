class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1, n2;
        double result = 0;
        if(nums1.size() < nums2.size()){
        }else{
            nums1.swap(nums2);
        }
        
        n1 = nums1.size();
        n2 = nums2.size();
        
        int low = 0;
        int high = n1;
        
        while(low <= high){
            // find partition in the first array
            int p1 =  low + (high-low)/2;
            
            // find the partition in the second array
            int p2 = (n1+n2)/2 - p1;
            
            int l_top = (p1 == 0) ? INT_MIN : nums1[p1-1];
            int l_bottom = (p2 == 0) ? INT_MIN : nums2[p2-1];
                
            int r_top = (p1 == n1) ?INT_MAX : nums1[p1];
            int r_bottom = (p2 == n2) ? INT_MAX : nums2[p2];
            
            if(l_top > r_bottom){
                high = p1 - 1;
            }else if(l_bottom > r_top){
                low = p1 + 1;
            }else{
                return ((n1+n2)%2 == 0) ? (double)(max(l_top, l_bottom) + min(r_top, r_bottom))/2 : (double)min(r_top, r_bottom); 
                break;
            }
        }
        
        return INT_MIN;
    }
};
