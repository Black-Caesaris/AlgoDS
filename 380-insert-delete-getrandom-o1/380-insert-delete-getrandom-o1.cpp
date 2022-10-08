typedef vector<int> vi;
typedef unordered_map<int, int> mi;

class RandomizedSet {
public:
    vi v;
    mi m;
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(m.count(val)){
            return false;
        }
        
        v.push_back(val);
        // size = index of element in the vector
        m.insert({val, v.size() - 1});
        return true;
        
    }
    
    bool remove(int val) {
        if(!m.count(val)){
            return false;   
        }
        
        int curr_index = m[val];
        m[v[v.size() - 1]] = curr_index;
        swap(v[curr_index], v[v.size() - 1]);
        v.pop_back();
        m.erase(val);

        return true;
    }
    
    int getRandom() {
        int random = rand() % (v.size());
        return v[random];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */