class Solution {
public:
    
//     unordered_map<string, int> memo;
//     unordered_map<string, bool> memo2;
    
//     bool isSS(string source, string target) {
//         if(target.length() == 0)
//             return false;
        
//         if(source.length() == 0)
//             return false;
        
//         int j = 0;
//         int i = 0;
        
//         while(i < source.length() && j < target.length()) {
//             if(source[i] == target[j]) {
//                 j++;
//             }
            
//             i++;
//         }
        
//         return j == target.length();
//     }
    
//     int backtrack(int idx, string& source, string& target) {
//         if(idx == target.length())
//             return 0;
        
//         if(memo.count(target)) {
//             return memo[target];
//         }
        
//         int result = 1e3;
//         for(int i = idx ; i < target.length(); i++) {
//             string nextSSCandidate = target.substr(idx, i - idx + 1);
//             if(memo2.count(nextSSCandidate) || isSS(source, nextSSCandidate)) {
//                 memo2[nextSSCandidate] = true;
//                 int ans = backtrack(i+1, source, target) + 1;
//                 result = min(ans, result);
//             }
//         }
        
//         return memo[target.substr(idx, target.length() - idx)] = result;
//     }
//     int shortestWay(string source, string target) {
//         int result = backtrack(0, source, target);
        
//         if(result == 1e3)
//             return -1;
//         return result;
//     }
    
    int shortestWay(string source, string target) {
        int result = 1;
        
        unordered_map<char, vector<int>> invertedIndex;
        
        for(int i = 0 ; i < source.length(); i++) {
            int ch = source[i];
            
            if(invertedIndex.count(ch)) {
                invertedIndex[ch].push_back(i);
            } else {
                invertedIndex.insert({ch, {i}});
            }
        }
        
        int prev = -1;
        for(int i = 0 ; i < target.length(); i++) {
            char ch = target[i];
            
            if(!invertedIndex.count(ch)) {
                return -1;
            }
            
            auto idx = lower_bound(invertedIndex[ch].begin(), invertedIndex[ch].end(), prev);
            
            if(idx != invertedIndex[ch].end()) {
                // cout << *idx << endl;
                prev = *idx + 1;
            } else {
                result++;
                prev = invertedIndex[ch][0] + 1;
            }
        }
        
        
        return result;
        
    }
};