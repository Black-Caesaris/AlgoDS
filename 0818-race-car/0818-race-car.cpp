typedef pair<int, int> pii;

struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};

class Solution {
    
public:
    
    unordered_set<pii, pair_hash> v;
    
    void sol(queue<pii>& q, int position, int speed, int target) {
        pii node = {position, speed};
        if(position >= 0 && position < 2 * target && !v.count(node)) {
            q.push(node);
            v.insert(node);
        }    
    }
    
    int racecar(int target) {
        queue<pii> q;

        // initial (position, speed)
        q.push({0, 1});
        int size = 1;
        int result = 0;


        while(!q.empty()) {
            pii node = q.front();
            q.pop();
            
            int position = node.first;
            int speed = node.second;
            
            if(position == target)
                return result;
            
            
            sol(q, position + speed, speed * 2, target);
            
            sol(q, position, speed > 0 ? - 1 : 1 , target);
            
            if(--size == 0) {
                size = q.size();
                result++;
            }
        
        }
        
        return 0;
    }
};