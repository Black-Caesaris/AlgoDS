class Solution {
public:
    
    vector<int> memo;
    bool isValid(const char& x, const char& y) {
        int a = x - '0';
        int b = y - '0';
        if(a == 0 || a > 2) {
            return false;
        }
        
        if(a == 2 && b >= 7) {
            return false;
        }
        
        return true;
    }
    
    int backtrack(int idx, string& s) { 
        
        if (idx == s.length()) {
            return 1;
        }

        if (s[idx] == '0') {
            return 0;
        }

        if (idx == s.length() - 1) {
            return 1;
        }
        
        
        if(memo[idx] >= 0) {
            return memo[idx];
        }
        
        int result = 0;
        result += backtrack(idx + 1, s);

            
        if(isValid(s[idx], s[idx+1])) {
            result += backtrack(idx + 2, s);
        }

        
        return memo[idx] = result;
    }
    
    int numDecodings(string s) {
        if(s.length() == 0) return 0;
        memo = vector<int>(s.length(), -1);
        return backtrack(0, s);
    }
};