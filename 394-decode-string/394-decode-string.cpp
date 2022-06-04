class Solution {
public:
    string decodeString(string s) {
        int n = s.length();
        
        if(n == 0) return "";
        
        stack<string> stk;
        
        for(int i = 0 ; i < n; i++){
            if(s[i] != ']'){
                stk.push(string(1, s[i]));
            }else{
                string temp;
                while(!stk.empty() && stk.top() != "["){
                    temp += stk.top();
                    stk.pop();
                }
                stk.pop();
                
                int base = 1;
                int n = 0;
                
                while(!stk.empty() && isdigit(stk.top()[0])){
                    n = n + stoi(stk.top())*base;
                    base = base * 10;
                    stk.pop();
                }
                
                
                string f;
                for(int j = 0 ; j < n; j++){
                    for(int i = temp.size() - 1; i >= 0 ; i--){
                        stk.push(string(1, temp[i]));
                    }
                }
                stk.push(f);
            }
        }
        
        
        string r;
    
        for(int i = stk.size() - 1; i >=0 ; i--){
            r = stk.top() + r;
            stk.pop();
        }
        
        
        return r;
    }
};