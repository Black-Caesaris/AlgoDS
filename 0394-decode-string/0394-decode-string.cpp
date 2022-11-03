class Solution {
public:
    string decodeString(string s) {
        
        stack<int> nums;
        stack<string> decoded;
        
        int k = 0;
        string currentString = "";
        for(char& ch : s) {
            if(isdigit(ch)) {
                k = k*10 + ch - '0';
            } else if (ch == '[') {
                nums.push(k);
                k = 0;
                
                decoded.push(currentString);
                
                currentString = "";
            } else if ( ch == ']') {
                string decodedString = decoded.top();
                decoded.pop();
                int K = nums.top();
                nums.pop();
                
                for(int i = K ; i > 0; i--) {
                    decodedString += currentString;
                }
                currentString = decodedString;   
            } else {
                currentString = currentString + ch;
            }
        }
        
        return currentString;
    }
};