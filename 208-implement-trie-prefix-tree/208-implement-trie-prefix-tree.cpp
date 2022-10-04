class Node{
  public:
    Node* dict[26];
    bool end = false;
    
    bool containsKey(char key) {
        return dict[key - 'a'] == nullptr ? false : true;
    }
    
    void put(char key, Node* node) {
        dict[key - 'a'] = node;
    }
    
    bool isEnd() {
        return end;
    }
    
    Node* getTrie(char key) {
        return dict[key - 'a'];
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i = 0 ; i < word.length(); i++) {
            if(!node->containsKey(word[i])) {
                Node* temp = new Node();
                node->put(word[i], temp);
            }
            node = node->getTrie(word[i]);
        }
        node->end = true;
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i = 0 ; i < word.length(); i++) {
            if(!node->containsKey(word[i])) {
                return false;
            }
            node = node->getTrie(word[i]);
        }
        return node->end;
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i = 0 ; i < prefix.length(); i++) {
            if(!node->containsKey(prefix[i])) {
                return false;
            }
            node = node->getTrie(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */