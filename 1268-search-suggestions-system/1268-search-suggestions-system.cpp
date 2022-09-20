class Node{
  public:
    Node* nodes[26];
    bool ends = false;
    
    bool containsKey(char ch) {
        return (nodes[ch - 'a'] != nullptr);
    }
    
    void put(char ch, Node* node) {
        nodes[ch - 'a'] = node;
    }
    
    Node* get(char ch){
        return nodes[ch - 'a'];
    }
    
    bool doesEnd() {
        return ends;
    }
};

class Trie{
    private: Node* root;
    public:
    
        Trie () {
            root = new Node();
        }
    
        void insert(string& word) {
            Node* node = root;
            for(int i = 0; i<word.length(); i++){
                
                if(!node->containsKey(word[i])){
                    node->put(word[i], new Node());
                }
                node = node->get(word[i]);
            }
            cout << endl;
            node->ends = true;
        }
        
        void dfsWithPrefix(Node* node, string& word, vector<string>& result){
            if(result.size() == 3) return;
            
            if(node->doesEnd())
            {
                result.push_back(word);
            }
            
            for(char ch = 'a' ; ch <= 'z'; ch++){
                if(node->nodes[ch - 'a']) {
                    word += ch;
                    // cout << word << endl;
                    dfsWithPrefix(node->nodes[ch - 'a'], word, result);
                    word.pop_back();
                }
            }
        }
    
        vector<string> getWordsStartingWith(string& prefix) {
            Node* curr = root;
            vector<string> result;
                
            for(char& ch : prefix){
                if(!curr->nodes[ch - 'a']){
                   return result;
                }
                curr = curr->nodes[ch - 'a'];
            }
            
            dfsWithPrefix(curr, prefix, result);
            return result;
        }
};

class Solution {
public:
    
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        Trie* trie = new Trie();
        vector<vector<string>> result;
        
        for(int i=0; i<products.size(); i++){
            trie->insert(products[i]);
        }
        
        for(int i=0; i<searchWord.length(); i++){
            // single letter char edge case to consider
            string temp = searchWord.substr(0, i+1);
            result.push_back(trie->getWordsStartingWith(temp));
        }
        
        return result;
    }
};