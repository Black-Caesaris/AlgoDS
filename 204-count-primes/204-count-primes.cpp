class Solution {
public:
    int countPrimes(int n) {
        vector<bool> multiples(n+1, true);
        int result = 0;
        
        for(int i = 2 ; i <= sqrt(n); i++) {
            if(multiples[i] == true) {
                for(int j = i*i ; j < n; j+=i) {
                    multiples[j] = false;
                }              
            }
        }
        
        for(int i = 2 ; i < multiples.size() - 1; i++) {
            if(multiples[i])
                result++;
        }
        
        return result;
    }
};