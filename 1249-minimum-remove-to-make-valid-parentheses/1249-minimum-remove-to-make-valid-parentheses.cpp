class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        string result = "";
        int counter = 0;
        
        for(char ch : s){
            if(counter >= 0 && ch == '('){
                counter++;
            }else if (counter >= 0 && ch == ')'){
                counter--;
            }
            
            if(counter < 0){
                counter = 0;
                continue;
            }
            
            result.push_back(ch);
        }
        
        // backward pass
        counter = 0;
        string f = "" ;
        for(int  i = result.length() - 1; i >=0; i--){
            char ch = result[i];
            if(counter >= 0 && ch == ')'){
                counter++;
            }else if (counter >= 0 && ch == '('){
                counter--;
            }
            
            if(counter < 0){
                counter = 0;
                continue;
            }
            
            f.push_back(ch);
        }
        
        reverse(f.begin(), f.end());
        return f;
    }
};