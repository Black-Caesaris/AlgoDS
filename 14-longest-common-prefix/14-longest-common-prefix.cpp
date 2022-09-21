

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        
        if(strs.size() == 0)
            return result;
        
        sort(strs.begin(), strs.end(), [](string& s1, string& s2){
            return (s1.length() > s2.length());
        });
        
        string initialString = strs[0];
        
        for(int i = 0; i < initialString.length(); i++){
            char ch = initialString[i];
            for(int j = 0; j < strs.size(); j++) {
                // if the character i for the jth string is equal to character i for reference string
                // add it to result
                if(ch != strs[j][i]){
                    return result;
                }
            }
            result += string(1, ch);
        }
        
        return result;
    }
};