class Solution {
public:
//     vector<int> productExceptSelf(vector<int>& nums) {
        
//         if(nums.size() < 2)
//             return nums;
        
//         vector<int> leftProduct(nums.size());
//         vector<int> rightProduct(nums.size());
//         vector<int> answer(nums.size());
        
//         leftProduct[0] = nums[0];
//         rightProduct[nums.size() - 1] = nums[nums.size() - 1];
        
//         for(int i = 1 ; i < nums.size(); i++) {
//             leftProduct[i] = nums[i]*leftProduct[i-1];
//         }
        
//         for(int i = nums.size() - 2 ; i >= 0; i--) {
//             rightProduct[i] = nums[i]*rightProduct[i+1];
//         }
        
//         answer[0] = rightProduct[1];
//         answer[nums.size() - 1] = leftProduct[nums.size() - 2];
        
//         for(int i = 1 ; i < nums.size() - 1; i++) {
//             answer[i] = leftProduct[i-1] * rightProduct[i+1];
//         }
        
//         return answer;
//     }
    
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.size() < 2) {
            return nums;
        }
        
        vector<int> answer(nums.size());
        
        int lp = 1;
        int rp = 1;
        
        for(int i = 0 ; i < nums.size(); i++) {
            answer[i] = lp;
            lp *= nums[i];
        }
        
        for(int i = nums.size() - 1; i >= 0; i--) {
            answer[i] *= rp;
            rp *= nums[i];
        }
        
        return answer;
    }
};