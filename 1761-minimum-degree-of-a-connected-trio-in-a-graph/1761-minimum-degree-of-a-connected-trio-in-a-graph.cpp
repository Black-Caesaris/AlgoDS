class Solution {
public:
    
//     n00b fat solution
//     unordered_map<int, vector<int>> graph;
    
//     int calcDegree(int node1, int node2, int node3) {
//         return graph[node1].size() + graph[node2].size() + graph[node3].size() - 6;
//     }
    
//     int minTrioDegree(int n, vector<vector<int>>& edges) {
//         set<vector<int>> hashEdges(edges.begin(), edges.end());
//         int result = INT_MAX;
        
//         for(auto edge : edges) {
//             if(graph.count(edge[0])) {
//                 graph[edge[0]].push_back(edge[1]);
//             } else {
//                 graph.insert({edge[0], {edge[1]}});
//             }
            
//             if(graph.count(edge[1])){
//                 graph[edge[1]].push_back(edge[0]); 
//             } else {
//                 graph.insert({edge[1], {edge[0]}});
//             }
//         }
        
//         for(auto edge : edges) {
//             int node1 = edge[0];
//             int node2 = edge[1];
            
//             for(int i = 1 ; i <= n; i++) {
//                 if(i == node1 || i == node2)
//                     continue;
//                 // cout << "Testing with node : " << i << endl;
//                 // construct edge
//                 vector<vector<int>> testEdges = {{node1, i}, {i, node1}, {i, node2}, {node2, i}};
//                 int count = 0;
//                 for(auto testEdge : testEdges) {
//                     // cout << "Test Edge: " << testEdge[0] << " : " << testEdge[1] << endl;
//                     if(hashEdges.count(testEdge)) {
//                         count++;
//                     }
//                 }
                
//                 // cout << "count : " << count << endl;
                
//                 if(count >= 2) {
//                     // cout << "calcDegree(node1, node2, n) : " << calcDegree(node1, node2, n) << endl;
//                     result = min(result, calcDegree(node1, node2, i));
//                 }
//             }
//         }
        
        
//         return result == INT_MAX ? -1 : result;
//     }
    
    // pro level solution
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        
        int result = INT_MAX;
        
        // store in a sorted manner, so that later we are checking in sorted manner
        vector<set<int>> graph(n + 1);
        vector<int> counts(n + 1);
        
        for(auto edge : edges) {
            graph[min(edge[0], edge[1])].insert(max(edge[0], edge[1]));
            ++counts[edge[0]];
            ++counts[edge[1]];
        }
        
        for(int i = 1 ; i <= n ; i++) {
            for(auto it1 = begin(graph[i]) ; it1 != end(graph[i]); it1++) {
                for(auto it2 = next(it1); it2 != end(graph[i]); it2++) {
                    // mean edge found
                    if(graph[*it1].count(*it2)) {
                        result = min(result, counts[*it1] + counts[*it2] + counts[i] -  6);
                    }
                }
            }
        }
        
        return result == INT_MAX ? -1 : result;
    }
};