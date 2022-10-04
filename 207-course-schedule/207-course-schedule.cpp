class Solution {
public:
    unordered_map<int, vector<int>> graph;
    // unordered_set<int> recursion_stack;
    // unordered_set<int> visited;
    
    bool dfs(int node, vector<int>& recursion_stack, vector<int>& visited) {
        
        // if(visited.count(node))
        //     return true;
        
        // if(recursion_stack.count(node))
        //     return false;
        if(visited[node])
            return true;
        
        if(recursion_stack[node])
            return false;

        // recursion_stack.insert(node);
        recursion_stack[node] = true;
        
        bool ret = true;
        for(auto i = graph[node].begin(); i!= graph[node].end(); i++) {
            ret &= dfs(*i, recursion_stack, visited);
            if(!ret)
                return ret;
        }
        
//         visited.insert(node);
//         recursion_stack.erase(node);
        visited[node] = true;
        recursion_stack[node] = false;
        
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

//         unordered_set<int> recursion_stack;
//         unordered_set<int> visited;
//         int *recursion_stack = new int[numCourses];
//         int *visited = new int[numCourses];
        
        vector<int> recursion_stack(numCourses, false);
        vector<int> visited(numCourses, false);         
        
        for(auto i = graph.begin(); i != graph.end(); i++) {
            if(!dfs(i->first, recursion_stack, visited))
                return false;
        }
        
        return true;
    }
};