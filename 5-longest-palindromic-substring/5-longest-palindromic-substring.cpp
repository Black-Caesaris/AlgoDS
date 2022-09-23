class Solution {
public:
    
    int centering(string&s, int left, int right) {
        while(left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }
    
    string longestPalindrome(string s) {
        
        if(s.length() == 0) return "";
        // aaabccbaaa
        int result = 0;
        int start = 0;
        int end = 0;
        for(int i = 0 ; i < s.length(); i++) {
            int len1 = centering(s, i, i);
            int len2 = centering(s, i, i+1);
            result = max(len1, len2);
            if(result > end-start){
                start = i - (result-1) / 2;
                end  = i + result/2;
            }
        }
        
        // cout << result;
        return s.substr(start, end-start+1);
    }
};