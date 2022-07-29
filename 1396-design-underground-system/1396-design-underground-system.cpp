class UndergroundSystem {
public:
    
    unordered_map<string, pair<double, double>> avg_times;
    unordered_map<int, pair<string, int>> checkInTimes;
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkInTimes.insert({id, {stationName, t}});
    }
    
    void checkOut(int id, string stationName, int t) {
        string startstation = checkInTimes[id].first;
        
        string hash = startstation + "->" + stationName;
        
        int time_taken = (t - checkInTimes[id].second);

        if(avg_times.find(hash) == avg_times.end()){
            avg_times.insert({hash, {time_taken, 1}});
        }else{
            avg_times[hash].first += time_taken;
            avg_times[hash].second += 1;
        }
        
        checkInTimes.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        double answer = avg_times[startStation + "->" + endStation].first/avg_times[startStation + "->" + endStation].second; 
        return answer; 
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */