class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> result;
        if(finalSum % 2 != 0) 
            return result;
        
        long long i = 2;
        long long sum = 0;
        
        while(sum + i <= finalSum) {
            result.push_back(i);
            sum += i;
            i += 2;
        }
        
        int remaining = finalSum - sum;
        result[result.size() - 1] += remaining > 0 ? remaining : 0;
        
        return result;
    }
};


// 2, 4, 