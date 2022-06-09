class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> sums;
        int count = 0;
        int max_ = 0;
        for(int i = 0 ; i < n; i++){
            count += (nums[i] == 1) ? 1 : -1;
            
            if(count == 0){
                max_ = max(max_, i + 1);
            }else if(sums.find(count) != sums.end()){
                max_ = max(max_, i - sums[count]);
            }else{
                sums.insert({count, i});
            }
        }
        
        return max_;
    }
};