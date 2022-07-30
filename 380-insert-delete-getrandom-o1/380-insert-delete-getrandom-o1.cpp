class RandomizedSet {
public:
    
    unordered_map<int, int> m;
    vector<int> v;
    int idx;
    
    RandomizedSet() {
        idx = 0;
    }
    
    bool insert(int val) {
        cout << "In here" << endl;

        if(!m.count(val)){
            m.insert({val, idx});
            v.push_back(val);
            idx++;
            return true;
        }
        
        return false;
    }
    
    bool remove(int val) {
                    cout << "In here 2" << endl;
        if(m.count(val)){

            m[*(v.end() - 1)] = m[val];
            iter_swap(v.begin() + m[val], v.end() - 1);
            
            v.pop_back();
            m.erase(val);
            idx--;
            return true;
        }
        
        return false;
    }
    
    int getRandom() {
                    cout << "In here  3" << endl;
        int x = (rand() % (v.size()));
        
        cout << x << endl;
        int result =  v[x];
        cout << result << endl;
        return result;
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */