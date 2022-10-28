class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int charSet[26] = {0};
        if(s == goal) {
            for(int i = 0 ; i < s.length(); i++) {
                if(charSet[s[i] - 'a'] == 1)
                    return true;
                else
                    charSet[s[i] - 'a'] = 1;
            }
        }
        
        
        int first = -1;
        int second = -1;
        
        for(int i = 0 ; i < goal.length(); i++) {
            if(s[i] != goal[i]) {
                if(first == -1)
                    first = i;
                else
                    second = i;
            }
        }
        
        if(first == -1 || second == -1)
            return false;
        
        swap(s[first], s[second]);
        
        return s == goal;
        
    }
};