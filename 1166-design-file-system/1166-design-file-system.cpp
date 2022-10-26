class Node {
public:
    int val;
    unordered_map<string, Node*> children;
    bool isEnd;
    
    Node() {
        val = 1;
        isEnd = false;
    }

};

class FileSystem {
public:
    Node* root;
    
    FileSystem () {
        root = new Node();
    }    
    
    bool insert(string sentence, int val) {
        vector<string> words = tokenize(sentence);
        Node* node = root;
        for(int i = 1 ; i < words.size(); i++) {
            string word = words[i];
            if(!node->children.count(word)) {
                if( i == words.size() - 1) {
                  node->children.insert({word, new Node()});
                } else {
                    return false;
                }
            }
            node = node->children[word];
        }
        
        if(node->isEnd) {
            return false;
        }  
        
        node->val = val;
        return node->isEnd = true;
    }
    
    int search(string sentence) {
        vector<string> words = tokenize(sentence);
        Node* node = root;
        for(int i = 1 ; i < words.size(); i++) {
            string word = words[i];
            if(!node->children.count(word)) {
                return -1;
            }
            node = node->children[word];
        }
        
        return node->val;
    }
    
    vector<string> tokenize(string sentence){
        string delimiter = "/";
        vector<string> tokens;
        size_t pos = 0;
        string token;
        while ((pos = sentence.find(delimiter)) != string::npos) {
            token = sentence.substr(0, pos);
            tokens.push_back(token);
            sentence.erase(0, pos + delimiter.length());
        }

        tokens.push_back(sentence);
        return tokens;
    }
    
    bool createPath(string path, int value) {
        return insert(path, value);
    }
    
    int get(string path) {
        return search(path);
    }
    

};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */