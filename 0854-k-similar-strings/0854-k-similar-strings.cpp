class Solution {
public:
    
    vector<string> generateNei (string node, string target) {
        
        vector<string> neighs;
        
        int i = 0;
        for(; i < node.length(); i++) {
            if(node[i] != target[i])
                break;
        }
        
        // the breaking point is at i
        // find the next element int node, that fulfills the char for this breakage point
        for(int j = i + 1; j < node.length(); j++) {
            if(node[j] == target[i] && node[j] != target[j]) {
                swap(node[j], node[i]);
                neighs.push_back(node);
                swap(node[j], node[i]);
            }
        }
        
        return neighs;
    }

    int kSimilarity(string a, string b) {
        if(a.length() != b.length())
            return -1;
        
        unordered_set<string> visited;
        queue<string> q;
        q.push(a);
        visited.insert(a);
        int currentLevel = 0;
        
        // perform bfs, keeping 1 char at it's correct place at a time
        while(!q.empty()) {
            int levelSize = q.size();
            for(int i = 0 ; i < levelSize; i++) {
                string node = q.front();
                q.pop();
                
                if(node == b) 
                    return currentLevel;
                
                for(string& nei : generateNei(node, b)) {
                    if(!visited.count(nei)) {
                        visited.insert(nei);
                        q.push(nei);
                    }
                }
            }
            currentLevel++;
        }
        
        return currentLevel;
    }
};