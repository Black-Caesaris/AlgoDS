class RandomizedSet {
public:
    
    unordered_map<int, int> m;
    vector<int> v;
    int idx;
    
    RandomizedSet() {
        idx = 0;
    }
    
    bool insert(int val) {
        if(!m.count(val)){
            m.insert({val, idx});
            v.push_back(val);
            idx++;
            return true;
        }
        
        return false;
    }
    
    bool remove(int val) {
        if(m.count(val)){
            // update index of element being swapped
            m[*(v.end() - 1)] = m[val];
            
            // swap with last element
            iter_swap(v.begin() + m[val], v.end() - 1); 
            
            // remove last
            v.pop_back();
            
            // remove from map
            m.erase(val);
            
            // decrement current index pointer
            idx--;
            return true;
        }
        
        return false;
    }
    
    int getRandom() {
        return  v[(rand() % (v.size()))];
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */