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
            cout << "Out insert";
            return false;
        }
        
        v.push_back(val);
        // size = index of element in the vector
        
        m.insert({val, v.size() - 1});
        
        cout << "Out insert";
        
        return true;
        
    }
    
    bool remove(int val) {
        if(!m.count(val)){
            cout << "Out remove";
            return false;   
        }
        
        int curr_index = m[val];
        m[v[v.size() - 1]] = curr_index;
        swap(v[curr_index], v[v.size() - 1]);
        v.pop_back();
        m.erase(val);


        cout << "Out remove";

        return true;
    }
    
    int getRandom() {
        int random = rand() % (v.size());
        cout << "Out random";

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