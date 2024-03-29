class Solution {
    
public:
    unordered_map<char, int> charIndex;
    
    bool inRange(int element, int left, int right) {
        if(charIndex[element] >= left && charIndex[element] <= right) {
            return true;
        }
        return false;
    }
    
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(k == 0)
            return 0;
        
        if(s.length() == 0 || s.length() == 1)
            return s.length();
        
        int left = 0;
        int right = 1;
        int ans = 0;
        int currDistinct = 1;
        
        charIndex.insert({s[0], 0});
        
        
        while(right < s.length()) {
            
            if(charIndex.count(s[right])) {
                if(!inRange(s[right], left, right)) {
                    currDistinct++;
                }
                charIndex[s[right]] = right;
            } else {
                charIndex.insert({s[right], right});
                currDistinct++;
            }
            
            while(currDistinct > k && left < right) {
                if(!inRange(s[left], left+1, right)) {
                    currDistinct--;
                }
                left++;
            }
            
            right++;
            ans = max(ans, right - left);
        }
        
        return ans;
    }
};