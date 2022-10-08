typedef vector<int> vi;

class Solution {
public:
    vi original;
    vi current;
    Solution(vector<int>& nums) {
        original = nums;
        current = nums;
    }
    
    vector<int> reset() {
        current = original;
        return original;
    }
    
    vector<int> shuffle() {
        int random1 = rand() % original.size();
        int random2 = rand() % original.size();
        swap(current[random1], current[random2]);
        
        int shuffled = current.size();
        while(shuffled > 0) {
            int random_idx = rand() % shuffled;
            swap(current[random_idx], current[shuffled - 1]);
            shuffled--;
        }
        
        return current;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */