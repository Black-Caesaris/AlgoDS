class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        
        int carry = 1;
        int sum = 0;
        
        for(int i = 0 ; i < digits.size(); i++) {
            sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;
        }
        
        if(carry)
            digits.push_back(carry);
        
        reverse(digits.begin(), digits.end());
        
        return digits;
    }
};