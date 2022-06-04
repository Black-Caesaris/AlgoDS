class Solution {
public:
    string simplifyPath(string path) {
        
        if(path.length() == 0) return "";
        
        if(path.length() == 1 && path[0] == '/') return "/";
        
        stack<string> s;
        
        for(int i = 0 ; i < path.length(); i++){
            if(path[i] == '/'){
                while(i < path.length() && path[i] == '/'){
                    i++;
                }
            }
            
            string temp = "";
            while(i < path.length() && path[i] != '/'){
                temp += path[i];
                i++;
            }
            
            if(temp == "" || temp == ".") continue;
            
            if(temp == ".."){
                if(!s.empty()) s.pop();
            }else{
                s.push(temp);
            }
            

        }
        
        string unix_path = "";
            
        stack<string> result;
        
        
        while(!s.empty()){
            result.push(s.top());
            s.pop();
        }
        
        while(!result.empty()){
            unix_path += "/";
            unix_path += result.top();
            result.pop();
        }

        
        return unix_path.length() > 0 ? unix_path : "/";
    }
};