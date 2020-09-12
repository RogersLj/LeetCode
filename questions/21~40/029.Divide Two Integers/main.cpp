class Solution {
public:
    int divide(int x, int y) {
        if (x == INT_MIN && y == -1) {
            return INT_MAX; //如果除法溢出，返回2 ^ 31 - 1
        }
        long a = labs(x), b = labs(y), ans = 0;
        int sign = x > 0 ^ y > 0 ? -1 : 1;
        
        while (a >= b) { //当a比b大，说明a/b至少等于1
            long temp = b, m = 1;
            while (temp << 1 <= a) { //当除数倍增后依然小于被除数
                temp <<= 1; //除数倍增
                m <<= 1; //个数倍增
            }
            a -= temp; 
            ans += m;
        }
        return sign * ans;
    }
};
