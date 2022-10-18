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
        
        if(sum != finalSum) {
            long long remaining = finalSum - sum;
            long long last =  result[result.size() - 1];
            if(remaining > last) {
                result.push_back(remaining);
            } else {
                result.pop_back();
                result.push_back(last + remaining);
            }
        }
        
        return result;
    }
};


// 2, 4, 