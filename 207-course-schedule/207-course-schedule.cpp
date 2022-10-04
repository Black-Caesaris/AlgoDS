class Solution {
public:
    unordered_map<int, vector<int>> graph;
    unordered_set<int> recursion_stack;
    unordered_set<int> visited;
    
    bool dfs(int node) {
        
        if(visited.count(node))
            return true;
        
        if(recursion_stack.count(node))
            return false;

        recursion_stack.insert(node);
        
        bool ret = true;
        for(auto i = graph[node].begin(); i!= graph[node].end(); i++) {
            ret &= dfs(*i);
            if(!ret)
                return ret;
        }
        
        visited.insert(node);
        recursion_stack.erase(node);
        return ret;
        
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        
        // prepare graph
        for(int i = 0 ; i < n ; i++) {
            int course1 = prerequisites[i][0];
            int course2 = prerequisites[i][1];
            if(graph.count(course2)) {
                graph[course2].push_back(course1);
            } else {
                graph.insert({course2, {course1}});
            }
        }
        
        int nodes = graph.size();

        
        for(auto i = graph.begin(); i != graph.end(); i++) {
            if(!dfs(i->first))
                return false;
        }
        
        return true;
    }
};