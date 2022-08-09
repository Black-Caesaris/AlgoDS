class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0) return 0;
        
        unordered_map<char, int> m;
        int max_length = 0;
        
        int start = 0;
        int end = 0;
            
        while(end < s.length()){
            
            // checking if char is already present
            if(m.count(s[end])){
                if(m[s[end]] >= start){
                    start = m[s[end]] + 1;
                }
            }
            
            
            max_length = max(max_length, end-start+1);
            
            if(m.count(s[end])){
                m[s[end]] = end;
            } else {
                m.insert({s[end], end});
            }
            
            end++;
        }
        
        return max_length;
    }
};