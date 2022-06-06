class Solution {
public:
    
    bool helper(int left, int right, string& s){
        if(s.length() == 0 || s.length() == 1) return true;
        
        while(left < right){
            if(s[left++] != s[right--]) return false;
        }
        
        return true;
    }
    bool validPalindrome(string s) {
        if(s.length() == 0 || s.length() == 1){
            return true;
        }
        
        int left = 0;
        int right = s.length() - 1;
        
        while(left < right){
            if(s[left++] != s[right--]){
                if(helper(left-1, right, s) || helper(left, right+1, s)) return true;
                else{
                        return false;
                }
            }
        }
        
        return true;
    }
};