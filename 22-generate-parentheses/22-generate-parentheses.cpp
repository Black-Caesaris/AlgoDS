class Solution {
public:
    vector<string> result;
    
    void backtrack(string word, int left, int right, int n) {
        if(word.length() == n*2) {
            result.push_back(word);
            return;
        }
        
        if(left < n) {
            word += '(';
            backtrack(word, left+1, right, n);
            word.pop_back();
        }
        
        if(right < left){
            word += ')';
            backtrack(word, left, right+1, n);
            word.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        backtrack("", 0, 0, n);
        return result;
    }
};