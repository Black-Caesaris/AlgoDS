class Solution {
public:
    
    int solve(vector<vector<int>>& jobs, vector<int>& startTime) {
        vector<int> dp(jobs.size(), 0);
                
        for(int i = jobs.size() - 1; i >= 0; i--) {
            int currProfit = 0;
            int nextNonConflicting = lower_bound(startTime.begin(), startTime.end(), jobs[i][1]) - startTime.begin();
            if(nextNonConflicting != startTime.size()) {
                currProfit = jobs[i][2] + dp[nextNonConflicting];
            } else {
                currProfit = jobs[i][2];
            }
            
            if(i == jobs.size() - 1){
                dp[i] = currProfit;
            } else {
                dp[i] = max(currProfit, dp[i+1]);
            }
        }
        
        return dp[0];
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        vector<vector<int>> jobs;
        
        for(int i = 0 ; i < startTime.size(); i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        
        sort(jobs.begin(), jobs.end());
        
        for(int i = 0; i < jobs.size(); i++) {
            startTime[i] = jobs[i][0];
        }
        
        
        return solve(jobs, startTime);

    }
};

