class Solution {
public:
    int minSteps(string s, string t) {
        int count[26];
        memset(count, 0, sizeof(count));
        int result = 0;
        
        for(auto c : s){
            count[c - 'a']++;
        }
        
        for(auto c : t){
          count[c - 'a']--;
        }
        
        for(auto cnt : count){
            result += cnt < 0 ? abs(cnt) : 0;
        }
        
        return result;
      
    }
};