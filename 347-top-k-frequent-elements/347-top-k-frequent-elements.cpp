typedef pair<int, int> ii; 

class Compare{
  public:
    bool operator() (ii& a, ii& b) {
        return a.second > b.second;
    }
};

class Solution {
    unordered_map<int, int> m;
    vector<ii> num_freqs;
public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         // heap solution nLogk
        
//         priority_queue<ii, vector<ii>, Compare> pq;
//         unordered_map<int, int> m;
//         vector<int> result;
        
//         for(int &num : nums) {
//             if(m.count(num)){
//                 m[num] +=1 ;
//             } else {
//                 m.insert({num, 1});
//             }
//         }  
        
//         for(ii currentPair : m) {
//             pq.push(currentPair);
//             if(pq.size() > k)
//                 pq.pop();
//         }
        
//         while(!pq.empty()) {
//             result.push_back(pq.top().first);
//             pq.pop();
//         }
        
//         return result;
//     }
    
    void quickselect(int start, int end, int k) {
        if(start >= end)
            return;
        
        int pivot = end;
        int pivot_value = num_freqs[end].second;
        int sort_index = start;
        
        for(int i = start; i <= end; i++) {
            if(num_freqs[i].second < pivot_value) {
                swap(num_freqs[i], num_freqs[sort_index]);
                sort_index++;
            }
        }
        
        swap(num_freqs[pivot], num_freqs[sort_index]);
        
        if(sort_index == k-1) {
            return; 
        }

        else if(sort_index > k) {
            quickselect(start, sort_index-1, k);  
        }

        else {
            quickselect(sort_index + 1, end, k);
        }

        
        return;
        
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int> result;
        
        for(int i = 0 ; i < nums.size(); i++) {
            if(m.count(nums[i])) {
                m[nums[i]] +=1;
            } else {
                m.insert({nums[i], 1});
            }
        }
        
        for(ii pair : m) {
            num_freqs.push_back(pair);
        }
        
        quickselect(0, num_freqs.size() - 1, num_freqs.size() - k);
        
   
        int i = num_freqs.size() - 1;
        while(k > 0){
            result.push_back(num_freqs[i].first);
            k--;
            i--;
        }
        
        return result;
    }
};