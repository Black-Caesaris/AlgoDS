class Solution {
public:
    
    string createHash(string s){
        string hash;
        for(int i = 0 ; i < s.length() - 1; i++){
            int temp = s[i+1] - s[i];
            hash = hash + "#" + to_string(temp < 0 ? temp + 26 : temp);    
        }
        
        cout << hash << " ";
        return hash;
    }
    vector<vector<string>> groupStrings(vector<string>& strings) {
        int n = strings.size();
        
        unordered_map<string, vector<string>> hash;
        for(string& s : strings){
            string h = createHash(s);
            if(hash.find(h) != hash.end()){
                hash[h].push_back(s);
            }else{
                hash.insert({h, {s}});
            }
        }
                            
        vector<vector<string>> result;
        for(auto it = hash.begin(); it != hash.end(); it++){
            result.push_back(it->second);
        }
                            
        return result;
    }
};