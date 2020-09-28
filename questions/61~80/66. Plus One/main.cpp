class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int t = 1;
        for(int i = digits.size() - 1; i >= 0; i--)
        {
            digits[i] += t;
            t = digits[i] / 10;
            digits[i] %= 10;
        }
        if(t) digits.insert(digits.begin(), 1);
        return digits;
    }
};
