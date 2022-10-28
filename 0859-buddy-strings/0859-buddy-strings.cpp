class Solution {
public:
    bool buddyStrings(string s, string goal) {
        
        if(s.length() != goal.length())
            return false;
        
        int charSet[26] = {0};
        
        if(s == goal) {
            for(int i = 0 ; i < s.length(); i++) {
                if(charSet[s[i] - 'a'] == 1)
                    return true;
                else
                    charSet[s[i] - 'a'] = 1;
            }
        }
        
        
        vector<int> diff;
            
        for(int i = 0 ; i < goal.length(); i++) {
            if(s[i] != goal[i]) {
                diff.push_back(i);
            }
        }
                
        return diff.size() == 2 && s[diff[0]] == goal[diff[1]] && s[diff[1]] == goal[diff[0]];
        
    }
};