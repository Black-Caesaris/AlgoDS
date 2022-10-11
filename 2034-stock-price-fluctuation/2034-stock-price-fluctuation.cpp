typedef pair<int, int> pi;

class MaxComparator {
    public:
        bool operator () (const pi& a, const pi& b) {
                return a.second < b.second;
        }
};

class MinComparator {
    public:
        bool operator () (const pi& a, const pi& b) {
                return a.second > b.second;
        }
};



class StockPrice {
    
public:

    // (timestamp, stockprice)
    unordered_map<int, int> timestampPrice;
    priority_queue<pi, vector<pi>, MinComparator> minHeap;
    priority_queue<pi, vector<pi>, MaxComparator> maxHeap;
    int latestTimestamp;
    
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        latestTimestamp = max(latestTimestamp, timestamp);
        
        if(timestampPrice.count(timestamp)) {
            timestampPrice[timestamp] = price;
        } else {
            timestampPrice.insert({timestamp, price});
        }
        
        // insert in Min Heap
        minHeap.push({timestamp, price});
        
        // insert in Max Heap
        maxHeap.push({timestamp, price});
    }
    
    int current() {
        return timestampPrice[latestTimestamp];
    }
    
    int maximum() {
        while(!maxHeap.empty()) {
            int timestamp = maxHeap.top().first;
            int price = maxHeap.top().second;
            
            if(timestampPrice[timestamp] != price) {
                // discard the current old timestamp
                maxHeap.pop();
            } else {
                break;
            }
        }
        
        return maxHeap.top().second;
    }
    
    int minimum() {
            while(!minHeap.empty()) {
                int timestamp = minHeap.top().first;
                int price = minHeap.top().second;

                if(timestampPrice[timestamp] != price) {
                    // discard the current old timestamp
                    minHeap.pop();
                } else {
                    break;
                }
            }

            return minHeap.top().second;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */