class Solution {
public:
    unordered_map<int, vector<int>> graph;
    stack<int> order;
    
    bool dfs(int node, vector<vector<int>>& prerequisites, vector<int>& recursion_stack, vector<int>& visited) {
        if(visited[node])
            return false;
        
        if(recursion_stack[node])
            // cycle found
            return true;
        
        recursion_stack[node] = true;
        
        bool ret = false;
        for(auto i = graph[node].begin(); i != graph[node].end(); i++) {
            ret |= dfs(*i, prerequisites, recursion_stack, visited);
            if(ret)
                return ret;
        }
        
        order.push(node);
        visited[node] = true;
        recursion_stack[node] = false;
        
        return ret;
        
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> recursion_stack(numCourses, false);
        vector<int> visited(numCourses, false);
        vector<int> result = {};
        
        for(int i = 0 ; i < prerequisites.size(); i++) {
            if(graph.count(prerequisites[i][1])) {
                graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            } else {
                graph.insert({prerequisites[i][1], {prerequisites[i][0]}});
            }
        }
        
        for(int  i = 0 ; i < numCourses; i++) {
            if(dfs(i, prerequisites, recursion_stack, visited)){
                return result;
            }
        }
        

        while(!order.empty()) {
            result.push_back(order.top());
            order.pop();
        }
        
        return result;
        
    }
};