class DisjointSet {
public:
    vector<int> parent;
    vector<int> rank;
    
    DisjointSet(int n) {
        parent.resize(n);
        rank = vector<int>(n, 1);
        makeSet(n);
    }
    
    void makeSet(int size) {
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x) {
        if(parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void join(int a, int b) {
        int parent_a = find(a);
        int parent_b = find(b);
        
        if(parent_a == parent_b)
            return;
        
        if(rank[parent_a] < rank[parent_b]) {
            parent[parent_a] = parent_b;
        } else if(rank[parent_b] < rank[parent_a]) {
            parent[parent_b] = parent_a;
        } else {
            parent[parent_b] = parent_a;
            rank[parent_a] += 1;
        }
    }
    
    
};

class Solution {
public:
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int row = isConnected.size();
        int col = isConnected[0].size();
        
        DisjointSet* s = new DisjointSet(row);
        
        for(int i = 0 ; i < row; i++) {
            for(int j = 0; j < col; j++) {
                // if(i >= j)
                //     continue;
                
                if(isConnected[i][j]) {
                    s->join(i, j);
                }
            } 
        }
        
        unordered_set<int> provinces;
        int result = 0;
//         for(int& p : s->parent) {
//             if(s->parent[p] == p) {
//                 result++;
//             }
//         }
        
        for(int i = 0 ; i < s->parent.size() ; i++) {
            if(s->parent[i] == i)
                result++;
        }
        
        return result; 
    }
};


