class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        unordered_map<int, int> sumIndex;
        sumIndex.insert({0, -1});
        
        int sum = 0;
        for(int i = 0 ; i < n; i++) {
            sum += arr[i];
            sumIndex.insert({sum, i});
        }
        
        int leftMinSize = INT_MAX;
        int result = INT_MAX;
        
        sum = 0;
        for(int i = 0 ; i < n; i++) {
            sum += arr[i];
            if(sumIndex.count(sum - target)) {
                leftMinSize = min(leftMinSize, i - sumIndex[sum-target]);
            }
            
            // for the right side
            if(sumIndex.count(sum + target) && leftMinSize < INT_MAX) {
                result = min(result, sumIndex[sum+target] - i + leftMinSize);
            }
        }
        
        return result < INT_MAX ? result : -1;
    }
};