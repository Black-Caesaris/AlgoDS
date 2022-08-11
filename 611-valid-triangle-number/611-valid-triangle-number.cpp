class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size() < 3) return 0;
        sort(nums.begin(), nums.end(), greater<int>());
        
        // for(int i = 0 ; i < nums.size(); i++){
        //     cout << nums[i] << " ";
        // }
        int begin  = 0;
        int end = 0;
        int ans = 0;
        
        for(int i = 0 ; i < nums.size() - 2; i++){

            begin = i + 1;
            end = nums.size() - 1;
            
                        
            while(begin < end){
                if((nums[begin] + nums[end]) > nums[i]){
                    ans += end - begin;
                    begin++;

                } else {
                    end--;
                }
            } 
        }
        
        
        return ans ;
    }
};