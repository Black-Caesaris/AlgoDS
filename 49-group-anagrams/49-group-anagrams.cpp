class Solution {
public:
    
    string hashIt(const string& s){
        int  charCount[26] = {0};
        
        for(const char& ch : s) {
            charCount[ch - 'a'] += 1;
        }
        
        string hash = "";
        for(int i = 0 ; i < 26; i++) {
            hash.push_back(charCount[i]);
        }
        
        return hash;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> anagramMap;
        vector<vector<string>> result;
        
        for(int i = 0 ; i < n; i++) {
            string hash = hashIt(strs[i]);
            if(anagramMap.count(hash)) {
                anagramMap[hash].push_back(strs[i]);
            } else {
                anagramMap.insert({hash, {strs[i]}});
            }
        }
        
        for(auto i = anagramMap.begin(); i != anagramMap.end(); i++) {
            result.push_back(i->second);
        }
        
        return result;
    }
};