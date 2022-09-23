class Solution {
public:
    vector<string> result;
    unordered_map<char, string> digitsMap {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
    };
    
    
    void backtrack(int idx, string& digits, string word) {
        if(word.length() == digits.length()) {
            result.push_back(word);
            return;
        }
        
        char ch = char(digits[idx]);
        string letters = digitsMap[ch];
        for(int j = 0 ; j < letters.size(); j++) {
            word += letters[j];
            cout << word << endl;
            backtrack(idx + 1, digits, word);
            word.pop_back();
        }
        
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        backtrack(0, digits, "");
        return result;
    }
};