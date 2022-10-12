class MyCalendar {
private:
    
    set<pair<int, int>> calendar;

public:
    bool book(int start, int end) {
        pair<int, int> event = {start, end};
        
        auto next = calendar.lower_bound(event);
        
        if(next != calendar.end() && next->first < end){
            return false;
        }
        
        if(next != calendar.begin()) {
            auto previous = prev(next);
            if(previous->second > start) {
                return false;
            }
        }
        
        calendar.insert(event);
        return true;
    }
};