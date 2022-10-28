class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> count;
        int result = 0;
        
        for(char& ch : s) {
            count[ch] += 1;
        }
        
        for(char& ch : t) {
            count[ch] -= 1;
        }
        
        
        for(auto it : count) {
            result += it.second > 0 ? it.second : 0;
        }
        
        return result;
    }
};