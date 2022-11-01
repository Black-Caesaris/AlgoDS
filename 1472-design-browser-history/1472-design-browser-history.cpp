class BrowserHistory {
public:
    vector<string> history;
    int pos = 0;
    
    BrowserHistory(string homepage) {
        history.push_back(homepage);
    }
    
    void visit(string url) {
        ++pos;
        history.resize(pos);
        history.push_back(url);
    }
    
    string back(int steps) {
        pos = pos - steps >= 0 ? pos - steps : 0;
        return history[pos];
    }
    
    string forward(int steps) {
        pos = pos + steps < history.size() ? pos + steps : history.size() - 1;
        return history[pos];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */