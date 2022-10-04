class Solution {
public:
    
    int quickselect(int start, int end, vector<int>& nums, int k) {
        if(start == end)
            return nums[start];
        
        int pivot = end;
        int pivotNum = nums[end];
        int insertPosition = start;
        
        for(int i = start; i <= end; i++) {
            if(nums[i] < pivotNum) {
                swap(nums[i], nums[insertPosition++]);
            }
        }
        
        swap(nums[insertPosition], nums[pivot]);
        
        if(insertPosition == k)
            return nums[insertPosition];
        else if(k < insertPosition)
            return quickselect(start, insertPosition - 1, nums, k);
        else
            return quickselect(insertPosition + 1, end, nums, k);   
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        return quickselect(0, nums.size() - 1, nums, nums.size() - k);
    }
};