class Solution {
public:
    
    vector<int> dp;
    
    int compute(int idx, vector<vector<int>>& books, int shelfWidth){
        if(idx >= books.size()){
            return 0;
        }
        
        if(dp[idx] != -1){
            return dp[idx];
        }
        
        int max_height = 0;
        int curr_width = 0;
        int i = idx;
        int ans = INT_MAX;
        
        while(i < books.size() && curr_width + books[i][0] <= shelfWidth){
            curr_width += books[i][0];
            max_height = max(max_height, books[i][1]);
            ans = min(ans, max_height + compute(i+1, books, shelfWidth));
            i++;
        }
        
        return dp[idx] = ans;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        dp = vector<int>(books.size(), -1);
        return compute(0, books, shelfWidth);
    }
};