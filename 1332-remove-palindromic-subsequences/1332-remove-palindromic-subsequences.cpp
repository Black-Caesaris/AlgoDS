class Solution {
public:
    int removePalindromeSub(string s) {
        int start = 0;
        int end = s.length() - 1;
        
        while(start <= end){
            if(s[start++] != s[end--]) return 2;
        }
        
        return 1;
    }
};