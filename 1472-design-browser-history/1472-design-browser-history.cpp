class Node{
public:
    Node* next;
    Node* prev;
    string val;
    
    Node (string s) {
        prev = next = nullptr;
        val = s;
    }
};


class BrowserHistory {
public:
    Node* head = nullptr;
    
    BrowserHistory(string homepage) {
        head = new Node(homepage);
    }
    
    void visit(string url) {
        Node* node = new Node(url);
        head->next = node;
        head->next->prev = head;
        head = head->next;
    }
    
    string back(int steps) {
        while(head->prev != nullptr && steps > 0){
            head = head->prev;
            steps--;
        }
        
        return head->val;
    }
    
    string forward(int steps) {
        while(head->next != nullptr && steps > 0){
            head = head->next;
            steps--;
        }
        
        return head->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */