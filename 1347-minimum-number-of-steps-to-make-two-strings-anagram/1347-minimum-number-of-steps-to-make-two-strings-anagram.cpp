class Solution {
public:
    int minSteps(string s, string t) {
        // can convert this to an array
        int count[26] = {0};
        int result = 0;
        
        for(char& ch : s) {
            count[ch - 'a'] += 1;
        }
        
        for(char& ch : t) {
            count[ch - 'a'] -= 1;
        }
        
        
        for(int diff : count) {
            result += diff > 0 ? diff : 0;
        }
        
        return result;
    }
};