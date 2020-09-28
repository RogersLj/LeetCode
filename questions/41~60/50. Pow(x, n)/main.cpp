class Solution {
public:
    #define LL long long
    double myPow(double x, int n) {
        double ans = 1, p = x;
        LL t = abs((LL)(n)); // 注意 x 为 INT_MIN时，abs 会爆掉 int。
        while(t) { // 将 n 进行二进制拆分。
            if (t & 1) ans = ans * p; // p 是提前计算好的批量连乘。
            p = p * p; // 每次更新 p，自身平方。
            t >>= 1;
        }
        return n > 0 ? ans : 1 / ans;
    }
};
