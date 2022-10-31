class DisjointSet {
public:
    vector<int> dset;  
    int size;
    
    DisjointSet(int x) {
        makeSet(x);
    }
    
    void makeSet(int x) {
        dset = vector<int>(x);
        iota(begin(dset), end(dset), 0);
        size = x;
    }
        
    int find(int x) {
        if(x != dset[x])
            dset[x] = find(dset[x]);
        return dset[x];
    }
    
    void join(int n1, int n2) {
        int parent1 = find(n1);
        int parent2 = find(n2);
        
        if(parent1 != parent2) {
            dset[parent1] = n2;
            size--;
        }
    }
    
    int setSize() {
        return size;
    }
};

class Solution {
public:
    
    bool isSimilar(string& a, string& b) {
        if(a.length() != b.length())
            return false;
        
        int count = 0;
        for(int i = 0 ; i < a.length(); i++) {
            if(a[i] != b[i] && ++count > 2)
                return false;
        }
        
        return true;
    }
    
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        DisjointSet* sd = new DisjointSet(n);
        
        for(int i = 0 ; i < n; i++) {
            for(int j = i + 1 ; j < n ; j++) {
                if(isSimilar(strs[i], strs[j])) {
                    sd->join(i, j);
                }
            }
        }
        
        return sd->setSize();
    }
};
