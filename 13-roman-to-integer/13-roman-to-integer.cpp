class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        unordered_map<string, int> symbolMap {
            {"I", 1},
            {"V", 5},
            {"X", 10},
            {"L", 50},
            {"C", 100},
            {"D", 500},
            {"M", 1000},
            {"IV", 4},
            {"IX", 9},
            {"XL", 40},
            {"XC", 90},
            {"CD", 400},
            {"CM", 900},
        };
        
        for(int i = 0 ; i < s.length(); i++){
            // if the two letter symbols exist
            if(i < s.length() - 1 ) {
                string str = string(1, s[i]) + string(1, s[i+1]);
                // if the 2 letter string exists
                if(symbolMap.count(str)){
                    result += symbolMap[str];
                    i++;
                    continue;
                }
            } 
                
            result += symbolMap[string(1, s[i])];        
        }
        
        
        return result;
    }
};