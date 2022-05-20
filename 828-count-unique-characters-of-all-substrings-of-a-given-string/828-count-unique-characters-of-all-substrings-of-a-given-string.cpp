class Solution {
public:
    int uniqueLetterString(string s) {
        int size = s.length();
        
        unordered_map<int, vector<int>> map;
        
        for(int i = 0 ; i < size; i++){
            if(map.find(s[i]) != map.end()){
                map[s[i]].push_back(i);
            }else{
                map.insert({s[i], {i}});
            }
        }
        
        int sum = 0;
        unordered_map<int, vector<int>>::iterator it;
        for(it = map.begin(); it != map.end(); it++){
            vector<int> indexes = it->second;
            for(int i = 0 ; i < indexes.size(); i++){
                int left = (i == 0) ? indexes[i] + 1 : indexes[i] - indexes[i-1];
                int right = (i == indexes.size() - 1) ? s.length() - indexes[i] : indexes[i+1] - indexes[i];
                sum += (left * right);
            }
        }
        
        return sum;
    }
};