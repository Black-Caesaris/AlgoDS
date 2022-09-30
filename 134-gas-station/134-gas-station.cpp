class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> diff(gas.size());
        int sum = 0;
        
        for(int i = 0 ; i < gas.size(); i++) {
            diff[i] = gas[i] - cost[i];
            sum += diff[i];
        }
        
        if(sum < 0) {
            return -1;
        } else {
            sum = 0;
        }
        
        int start = 0;
        int i = 0;
        int steps = 0;
        while(steps < diff.size()) {
            sum += diff[i % diff.size()];
            steps++;
            if(sum < 0) {
                steps = 0;
                start = (i+1) % diff.size();
                sum = 0;
            }
            i++;
        }
        return start;
    }
};