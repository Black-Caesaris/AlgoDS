class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        if(s == " " || k > s.length()) return s;
        
        stack<int> count;
        for(int i = 0 ; i < s.length(); i++){
            if(i == 0){
                count.push(1);
                continue;
            }
            
            if(s[i] == s[i-1]){
                count.top() += 1;
                if(count.top() == k){
                    s.erase(i-k+1, k);
                    i = i - k;
                    count.pop();
                }
            }else{
                count.push(1);
            }
        }
        
        return s;
    }
};