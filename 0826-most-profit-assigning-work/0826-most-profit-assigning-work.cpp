class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        
        vector<vector<int>> jobs(n, vector<int>(2, 0));
        
        for(int i = 0 ; i < n; i++) {
            jobs[i] =  {difficulty[i], profit[i]};
        }
        
        sort(begin(jobs), end(jobs));
        sort(begin(worker), end(worker));
        int max_profit_so_far = 0;
        int i = 0 ;
        int result = 0;
        
        for(int w : worker) {
            while(i < n && jobs[i][0] <= w) {
                max_profit_so_far = max(max_profit_so_far, jobs[i][1]);
                i++;
            }
            result += max_profit_so_far;
        }
        
        return result;
    }
};