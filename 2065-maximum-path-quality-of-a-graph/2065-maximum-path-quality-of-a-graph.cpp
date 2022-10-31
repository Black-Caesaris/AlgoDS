// class Solution {
// public:
//     unordered_map<int, vector<pair<int, int>>> graph;
//     unordered_set<int> visited;
//     int maximumTime;
//     int result;
    
//     void dfs(int source, vector<int>& values, int time, int value) {
//         if(time > maximumTime)
//             return;
        
//         if(!visited.count(source)) {
//             // add value in path only on first occurence
//             value += values[source];
            
//             // mark as visited
//             visited.insert(source);
//         }
        
//         if(source == 0 ) {
//             result = max(result, value);
//         }         

//         for(auto i = graph[source].begin() ; i != graph[source].end(); i++) {
//             int newTime = i->second;
//             int nextNode = i->first;
//             if(newTime < maximumTime)
//                 dfs(nextNode, values, time + newTime, value);
//         }
        
//     }
//     int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
//         // create the graph first
//         maximumTime = maxTime;
//         result = 0;
        
//         for(vector<int> edge : edges) {
//             graph[edge[0]].push_back({edge[1], edge[2]});
//             graph[edge[1]].push_back({edge[0], edge[2]});
//         }
        
//         int source = 0;

//         dfs(source, values, 0, 0);
        
//         return result;
//     }
// };

class Solution {
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();
        int res = values[0];
        vector<vector<pair<int,int>>> graph(n);
        for(int i=0;i<edges.size();i++)
        {
            graph[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            graph[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        
        vector<int> visited(n, 0);
        dfs(graph, values, visited, res, 0, 0, 0, maxTime);
        return res;
    }
    
    void dfs(vector<vector<pair<int,int>>>& graph, vector<int>& values, vector<int>& visited, int& res, int node, int score, int time, int& maxTime)
    {
        if(time > maxTime)
            return;
        
        if(visited[node] == 0)
            score += values[node];
        
        visited[node]++;
		
      
        if(node == 0)
            res = max(res, score);
        
        for(auto it : graph[node])
        {
            int neigh = it.first;
            int newTime = time + it.second;
            dfs(graph, values, visited, res, neigh, score, newTime, maxTime);
        }
        
        visited[node]--;
    }
};