typedef pair<int, int> ii; 

class Compare{
  public:
    bool operator() (ii& a, ii& b) {
        return a.second > b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // heap solution nLogk
        
        priority_queue<ii, vector<ii>, Compare> pq;
        unordered_map<int, int> m;
        vector<int> result;
        
        for(int &num : nums) {
            if(m.count(num)){
                m[num] +=1 ;
            } else {
                m.insert({num, 1});
            }
        }  
        
        for(ii currentPair : m) {
            if(!pq.empty()) {
                if(pq.size() == k && pq.top().second < currentPair.second) {
                    pq.pop();
                    pq.push(currentPair);
                } else if (pq.size() < k) {
                    pq.push(currentPair);
                }
                
            } else {
                pq.push(currentPair);
            }
        }
        
        while(!pq.empty()) {
            result.push_back(pq.top().first);
            pq.pop();
        }
        
        return result;
    }
};