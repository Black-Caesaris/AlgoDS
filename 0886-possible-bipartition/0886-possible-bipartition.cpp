class Solution {
public:
    unordered_map<int, vector<int>> graph;
    unordered_map<int, int> visited;
    
    bool dfs(int node) {
        for(auto i = graph[node].begin() ; i != graph[node].end(); i++) {
            if(visited.count(*i)) {
                // if the color is same as parent, then return false
                if(visited[*i] == visited[node])
                    return false;
            } else {
                visited[*i] = 1 - visited[node];
                if(!dfs(*i))
                    return false;   
            }

        }
        
        return true;
    }
    
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        // form the graph
        for(vector<int>& dislike : dislikes) {
            graph[dislike[0]].push_back(dislike[1]);
            graph[dislike[1]].push_back(dislike[0]);
        }
        
        int groups = 0;

        for(int i = 1; i <= n ; i++) {
            if(!visited.count(i) && !dfs(i)) {
                visited[i] = 1;
                groups++;
                return false;
            }
            
            if(i < n && groups == 2) {
                return false;
            }
        }
        
        return true;
    }
};