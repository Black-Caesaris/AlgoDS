class OrderedStream {
public:
    vector<string> stream;
    int idx;
    int boundary;
    
    OrderedStream(int n) {
        idx = 0;
        boundary = n;
        
        for(int i = 0 ; i < n; i++){
            stream.push_back("");
        }
    }
    
    vector<string> insert(int idKey, string value) {
        vector<string> result;

        if(idKey > boundary){
            return result;
        }
        
        stream[idKey-1] = value;
        
        for(int i = idx; i < stream.size(); i++){
            if(stream[i] == ""){
                break;
            }
            
            result.push_back(stream[i]);
            idx++;
        }
        
        return result;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */