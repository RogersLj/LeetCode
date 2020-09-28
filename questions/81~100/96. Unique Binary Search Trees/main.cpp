class Solution {
public:
    int numTrees(int n) {
        vector<int> f(n + 1);
        f[0] = f[1] = 1;
        for(int i = 2; i <= n; i++)
            for(int k = 0; k <= i - 1; k++)
                f[i] = f[i] + f[k] * f[i - k - 1];
        return f[n]; 
    }
};