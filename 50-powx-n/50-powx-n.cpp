class Solution {
public:
    
    double halfPow(double x, long long n) {
        if(n == 0) {
            return 1.0;
        }
        
        double p = halfPow(x, n/2);
        
        if(n%2 == 0) {
            return p * p;
        } else {
            return p * p * x;
        }
        
    }
    double myPow(double x, int n) {
        
            // bad approach. array is not required; will fail for large cases to allocate the array
//         if(n == 0) return 1;
       
//         bool isNegative = n < 0 ? true : false;
//         n = abs(n);
//         long length = (long)n;
//         cout << length;
//         double dp[length+1];
        
//         dp[0] = 0;
//         dp[1] = x;
            
//         for(int i = 2 ; i <= n ; i++) {
//             // incase of even
//             if(i % 2 == 0) {
//                 dp[i] = dp[i/2] * dp[i/2];
//             } else {
//                 // incase of odd
//                 dp[i] = dp[(i-1)/2] * dp[(i-1)/2] * x;
//             }
//         }
        
//         return isNegative == true ? 1/dp[n] : dp[n];
        
        long long N = n;
        if(N < 0) {
            x = 1/x;
            N = abs(N);
        }
        
        return halfPow(x, N);
        
    }
};