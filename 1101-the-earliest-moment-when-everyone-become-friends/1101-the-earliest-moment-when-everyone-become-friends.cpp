class UnionFind {
    public:
        vector<int> parent;
        vector<int> rank;

        UnionFind(int& size) {
            parent = vector<int>(size);
            rank = vector<int>(size, 0); 

            // make everyone parent of itself
            for(int i = 0 ; i < size; i++) {
                parent[i] = i;
            }
        }

        
        // finds the parent of a node and compresses the path
        int find(int& node) {
            if(node == parent[node]) {
                return node;
            }

            return parent[node] = find(parent[node]);
        }
    
        bool Union(int& node1, int& node2) {
            int parent1 = find(node1);
            int parent2 = find(node2);
            
            bool didWeMerge = false;
            
            if(parent1 == parent2) {
                // already in the same group
                return didWeMerge;
            }
            
            if(rank[parent1] < rank[parent2]) {
                parent[parent1] = parent2;
            } else if(rank[parent1] > rank[parent2]) {
                parent[parent2] = parent1;
            } else {
                parent[parent1] = parent2;
                rank[parent2] += 1;
            }
            
            return didWeMerge = true;
        }
        
        
};



class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });
            
        UnionFind* uf = new UnionFind(n);
        
        for(vector<int>& log : logs) {
            int timestamp = log[0];
            int friend1 = log[1];
            int friend2 = log[2];
            
            if(uf->Union(friend1, friend2)) {
                n--;
            }
            
            if(n==1)
                return timestamp;
        }
        return -1;
    }
};