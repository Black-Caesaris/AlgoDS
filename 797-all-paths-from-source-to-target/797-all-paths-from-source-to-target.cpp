class Solution {
public:
    
    vector<vector<int>> result;

    
    void backtracks(vector<vector<int>>& graph, vector<int>& path, int node){
        
        if(!path.empty() && path.back() == (graph.size() - 1)){
            result.push_back(path);
            return;
        }
        
        for(int i = 0 ; i < graph[node].size(); i++){
            cout << "Node: " << node << endl;
            path.push_back(graph[node][i]);
            backtracks(graph, path, graph[node][i]);
            path.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        if(graph.size() == 0) return result;
        
        vector<int> path;
        path.push_back(0);
        backtracks(graph, path, 0);
        
        return result;
    }
};