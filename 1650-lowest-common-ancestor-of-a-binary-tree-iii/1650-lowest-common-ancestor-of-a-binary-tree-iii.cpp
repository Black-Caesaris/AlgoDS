/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    

    Node* lowestCommonAncestor(Node* p, Node * q) {
        unordered_set<Node*> s;
        Node* par = p;
        
        if(p->parent == q) return q;
        else if(q->parent == p) return p;
        
        while(par != nullptr){
            s.insert(par);
            par = par->parent;
        }
        
        par = q;
        
        while(par != nullptr){
            if(s.find(par) != s.end()){
                return par;
            }
            par = par->parent;
        }
        
        return nullptr;
    }
};