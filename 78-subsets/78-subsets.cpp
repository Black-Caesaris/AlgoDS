class Solution {
public:
    vector<vector<int>> ss;
    void compute(vector<int>& input, vector<int> output, int n) {
        if(n < 0) {
            ss.push_back(output);
            return ;
        } 
        
        compute(input, output, n - 1);
        output.push_back(input[n]);
        compute(input, output, n - 1);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        compute(nums, {}, nums.size() - 1);
        return ss;
    }
};