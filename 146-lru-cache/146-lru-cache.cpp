class LRUCache {
public:
    
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    list<int> lru;
    int capacity;
    
    LRUCache(int capacity) {
        this->capacity = capacity; 
    }
    
    int get(int key) {
        // access key
        if(cache.count(key)) {
            int val = cache[key].first;
            lru.erase(cache[key].second);
            lru.push_back(key);
            cache[key].second = prev(lru.end());
            return val;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        
        if(cache.count(key)) {
            // if key present
            lru.erase(cache[key].second);
            lru.push_back(key);
            cache[key].first = value;
            cache[key].second = prev(lru.end());
        } else {
            if(cache.size() >= capacity) {
                cache.erase(lru.front());
                lru.pop_front();
            }
            lru.push_back(key);
            cache.insert({key, {value, prev(lru.end())}});
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */



