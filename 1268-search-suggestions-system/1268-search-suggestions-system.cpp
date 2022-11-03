class Node {
public:
    vector<Node*> hash;
    char ch;
    bool isEnd;
        
    Node() {
        this->isEnd = false;
        this->hash = vector<Node*>(26, nullptr);
    }
    
    Node(char ch) {
        this->ch = ch;
        this->isEnd = false;
        this->hash = vector<Node*>(26, nullptr);
    }
    
    Node* get(char ch) {
        return hash[ch - 'a']; 
    }
    
    void put(char ch, Node* node) {
        hash[ch - 'a'] = node;
    }
    
    bool isWord() {
        return this->isEnd;
    }
};

class Trie {
  public:
    Node* root;
    
    Trie() {
        root = new Node(); 
    }
    
    void insert(string prefix) {
        
        Node* curr = root;
        for(char& ch : prefix) {
            // cout << ch << " ";
            // add if not present
            if(!curr->get(ch)) {
                // cout << "At 0: " << endl;
                curr->put(ch, new Node(ch));
            }
            
            // cout << "At 1: " << endl;
            curr = curr->get(ch);
        }
        
        curr->isEnd = true;
        // cout << endl;
    }
    
    void dfs(Node* curr, vector<string>& words, string word) {
        // cout << word << endl;
        if(words.size() == 3) {
            // cout << "returning 3" << endl;
            return;
        }
        
        // if we found a word
        if(curr->isWord()) {
            // cout << "found word returning: " << endl;
            words.push_back(word);
        }
        
        for(int i = 'a' ; i <= 'z'; i++) {
            // find the next lexicographical path
            if(curr->get(i)) {
                // insert the new char to word
                word.push_back(curr->get(i)->ch);
                dfs(curr->get(i), words, word);
                word.pop_back();
            }
        }
    }
    
    vector<string> searchWithPrefix(string prefix) {
        Node* curr = root;
        vector<string> words;
        
        for(char& ch : prefix) {
            // cout << ch << " ";
            if(!curr->get(ch))
                return words;
            curr = curr->get(ch);
        }
        

        dfs(curr, words, prefix);
        return words;
    }
};




class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie* trie = new Trie();
        vector<vector<string>> result;
        
        for(string& product : products) {
            trie->insert(product);
        }
        
        // result.push_back(trie->searchWithPrefix("mou"));
        for(int i = 0 ; i < searchWord.length(); i++) {
            result.push_back(trie->searchWithPrefix(searchWord.substr(0, i + 1)));
        }
        
        return result;
    }
};