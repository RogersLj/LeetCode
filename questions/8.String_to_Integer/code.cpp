class Solution {
public:
    int myAtoi(string str) {
        long long res = 0;
        int k = 0;
        int minus = 1;
        while (k < str.size() && str[k] == ' ') k ++;
        if (k >= str.size()) return 0;

        if (str[k] == '-') minus = -1, k ++;
        if (str[k] == '+')
        {
            if (minus == -1) return 0;
            else k ++;
        }

        while (str[k] >= '0' && str[k] <= '9')
        {
            int t = str[k] - '0';
            res = res * 10 + t;
            k ++;
            if (res > INT_MAX) break;
        }

        res *= minus;

        if (res > INT_MAX) return INT_MAX;
        if (res < INT_MIN) return INT_MIN;

        return res;
    }
};
