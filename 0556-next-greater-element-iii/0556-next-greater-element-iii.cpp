class Solution {
public:
    
    
    int max_so_far(string digits, char ref, int idx) {
        while(idx < digits.size() - 1 && digits[idx+1] > ref){
            idx++;
        }
        return idx;
    }
    
    int nextGreaterElement(int n) {
        string digits = to_string(n);
        
        string int_max = "2147483647";

        int size = digits.size();
        
        for(int i = size - 1 ; i > 0 ; i--) {
            if(digits[i] > digits[i-1]) {
                swap(digits[i-1], digits[max_so_far(digits, digits[i-1], i-1)]);
                reverse(begin(digits) + i, end(digits));
                return (size == 10 && digits > int_max) ? -1 : stoi(digits);
            }         
        }
        
        return -1;
    }
};