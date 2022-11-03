class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prev_min = prices[0];
        int result = 0;
        
        for(int i = 0 ; i < prices.size(); i++) {
            result = max(result, prices[i] - prev_min);
            prev_min = min(prev_min, prices[i]);
        }
        
        return result;
    }
};