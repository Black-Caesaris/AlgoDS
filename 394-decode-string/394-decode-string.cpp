class Solution {
public:
    
    string duplicate(int x, string s){
        string duplicate = "";
        for(int i = 0 ; i < x; i++){
            duplicate += s;
        }
        return duplicate;
    }
    
    string formNumber(int index, string s){
        string n;
        int number = 0;
        int base = 1;
        
        while(index < s.length() && isdigit(s[index])){
            n.push_back(s[index]);
            index++;
        }
            
        reverse(begin(n), end(n));

        for(char &d : n){
            number += base * (d-'0');
            base = base*10;
        }
        
        // cout << number << endl;
        return to_string(number);
    }
    
    string decodeString(string s) {
        stack<string> stk;
 
        for(int i = 0 ; i < s.length(); i++){
            if(s[i] == ']'){
                string temp;
                
                // pop from stack, and then push back number of times
                while(!stk.empty() && stk.top() != "["){
                    temp += stk.top();
                    stk.pop();
                }
                         
                // pop out '['
                stk.pop();                
                
                // duplicate x times
                int x = stoi(stk.top());
                stk.pop();
                string dup = duplicate(x, temp);
                cout << dup;
                stk.push(dup);
            } else if(isdigit(s[i])){
                string number = formNumber(i, s);
                i = i + number.length() - 1;
                stk.push(number);
            }else{
               stk.push(string(1,s[i]));   
            }
            
            cout << endl;
        }
        
        string decodedString;
        while(!stk.empty()){
            decodedString += stk.top();
            stk.pop();
        }
        
        reverse(begin(decodedString), end(decodedString));
        return decodedString;
    }
};