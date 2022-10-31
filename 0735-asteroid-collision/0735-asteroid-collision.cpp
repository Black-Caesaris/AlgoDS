class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;

        
        for(int& b : asteroids) {
            if(!s.empty()) {
                bool bacha = true;
                while(!s.empty() && s.top() > 0 && b < 0) {
                    if (s.top() == abs(b)) {
                        s.pop();
                        bacha = false;
                        break;
                    } else if (s.top() < abs(b)) {
                        s.pop();
                    } else if(s.top() > abs(b)){
                        bacha = false;
                        break;
                    }
                }
                
                if(bacha) {
                    s.push(b);
                }
            } else {
                s.push(b);
            }
         }
        
        vector<int> result(s.size());
        for(int i = s.size() - 1; i >= 0 ; i--) {
            result[i] = s.top();
            s.pop();
        }
        
        return result;
    }
};