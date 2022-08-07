class LRUCache {
public:
    unordered_map<int, pair<list<int>::iterator, int>> m;
    int capacity = 0;
    list<int> lruKey;
    
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(m.count(key)){
            // o(1) deletion using iterator
            lruKey.erase(m[key].first);
            lruKey.push_back(key);
            
            // update the list iterator in the map to point to latest
            m[key].first = --lruKey.end();
            
            return m[key].second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        
        if(m.count(key)){
            
            // delete the last usage of key
            lruKey.erase(m[key].first);
            
            // add to back
            lruKey.push_back(key);
            
            m[key].first = --lruKey.end();
            m[key].second = value;
            
            return;
        }
        
        if(m.size() < capacity){
            
            // only add to front since 1st usage
            lruKey.push_back(key);
            
            m.insert({key, {--lruKey.end(), value}});

            
            return;
        }
        
        // evict least recently used from LRU and the map
        m.erase(lruKey.front());
        lruKey.pop_front();
        

        lruKey.push_back(key);
        m.insert({key, {--lruKey.end(), value}});

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */