class Solution {
public:
    int MOD = 1e9 + 7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> engineers;
        
        for(int i = 0 ; i < speed.size(); i++) {
            engineers.push_back({speed[i], efficiency[i]});
        }
        
        priority_queue<int, vector<int>, greater<int>> speedHeap;
        
        // sort b y efficiency in descending order
        sort(begin(engineers), end(engineers), [] (pair<int,int>& a, pair<int,int>& b) {    
           return a.second > b.second; 
        });
        
        long ans = 0;
        long totalSpeed = 0;
        for(auto &engineer : engineers) {
            int currSpeed = engineer.first;
            int currEfficiency = engineer.second;
            
            if(speedHeap.size() == k) {
                totalSpeed -= speedHeap.top();
                speedHeap.pop();
            }
            
            speedHeap.push(currSpeed);
            totalSpeed += currSpeed;
            
            ans = max(ans, (totalSpeed * currEfficiency));
        }
        
        return ans % MOD;
    }
};